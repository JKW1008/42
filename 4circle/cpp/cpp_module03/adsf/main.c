#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2
#define ERR_CD_BAD "error: cd: bad arguments"
#define ERR_CD_DIR "error: cd: cannot change directory to "
#define ERR_FATAL "error: fatal"
#define ERR_EXE "error: cannot execute "

int     ft_strlen(char *str)
{
    int i;
    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    ft_putstr(char *err, char *arg)
{
    write(2, err, ft_strlen(err));
    if (arg)
        write(2, arg, ft_strlen(arg));
    write(2, "\n", 1);
}

int     findEndPoint(int i, char **av)
{
    int ep;
    ep = 0;
    while (av[i + ep] && strcmp(av[i + ep], ";") && strcmp(av[i + ep], "|"))
        ep++;
    return ep;
}

void    customCD(int i, int ep, char **av)
{
    if (ep != 2)
    {
        ft_putstr(ERR_CD_BAD, NULL);
        return ;
    }
    if (chdir(av[i + 1]) == -1)
    {
        ft_putstr(ERR_CD_DIR, av[i + 1]);
    }
}

void    customExecve(int prev_fd, int ep, char **av, char **env)
{
    if (prev_fd != STDIN_FILENO)
    {
        dup2(prev_fd, STDIN_FILENO);
        close(prev_fd);
    }
    av[ep] = NULL;
    if (execve(av[0], av, env) == -1)
    {
        ft_putstr(ERR_EXE, av[0]);
        exit(1);
    }
}
int main(int ac, char **av, char **env)
{
    int     idx;
    int     ep;
    int     fd[2];
    int     prev_fd;
    pid_t   pid;
    idx = 1;
    prev_fd = STDIN_FILENO;
    while (idx < ac)
    {
        ep = findEndPoint(idx, av);
//      printf("%d %s %s\n", idx, av[idx], av[idx+ep]);
        if (ep == 0)
        {
            idx++;
            continue;
        }
        if (strcmp(av[idx], "cd") == 0)
        {
            customCD(idx, ep, av);
            idx += ep + 1;
            continue;
        }
        if (!av[idx + ep] || !strcmp(av[idx + ep], ";"))
        {
            pid = fork();
            if (pid == -1)
            {
                ft_putstr(ERR_FATAL, NULL);
                exit(1);
            }
            else if (pid == 0)
            {
                customExecve(prev_fd, ep, &av[idx], env);
            }
            else
            {
                if (prev_fd != STDIN_FILENO)
                {
                    dup2(prev_fd, STDIN_FILENO);
                    close(prev_fd);
                }
                prev_fd = 0;
                while (waitpid(-1, NULL, WUNTRACED) > 1) ;
            }
        }
        else
        {
            pipe(fd);
            pid = fork();
            if (pid == -1)
            {
                ft_putstr(ERR_FATAL, NULL);
                exit(1);
            }
            else if (pid == 0)
            {
                dup2(fd[0], STDIN_FILENO);
                close(fd[0]);
                dup2(fd[1], STDOUT_FILENO);
                close(fd[1]);
                customExecve(prev_fd, ep, &av[idx], env);
            }
            else
            {
                close(fd[1]);
                if (prev_fd != STDIN_FILENO)
                {
                    dup2(prev_fd, STDIN_FILENO);
                    close(prev_fd);
                }
                prev_fd = fd[0];
                while (waitpid(-1, NULL, WUNTRACED) > 1) ;
            }
        }
        idx += ep +1;
    }
    close(prev_fd);
}