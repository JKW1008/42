/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:58:58 by kjung             #+#    #+#             */
/*   Updated: 2024/07/24 20:33:52 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "../pipex.h"

void	exec(char *cmd, char **envp)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = find_path(envp, s_cmd[0]);
	if (execve(path, s_cmd, envp) == -1)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		free_split(s_cmd);
		free(path);
		exit (127);
	}
}

void	here_doc_put_in(char **argv, int *p_fd)
{
	char	*ret;

	close(p_fd[0]);
	while (1)
	{
		ret = get_next_line(0);
		if (ret == NULL || (ft_strncmp(ret, argv[2], ft_strlen(argv[2])) == 0))
		{
			free(ret);
			exit(0);
		}
		ft_putstr_fd(ret, p_fd[1]);
		free(ret);
	}
}

void	here_doc(char **argv)
{
	int		p_fd[2];
	pid_t	pid;
	int		status;

	if (pipe(p_fd) == -1)
		px_error(NULL);
	pid = fork();
	if (pid == -1)
		px_error(NULL);
	if (!pid)
		here_doc_put_in(argv, p_fd);
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
		close(p_fd[0]);
		waitpid(pid, &status, 0);
	}
}

void	do_pipe(char *cmd, t_pbdata *data, pid_t *pids, int *p_fd)
{
	pid_t	pid;

	if (pipe(p_fd) == -1)
		px_error(NULL);
	pid = fork();
	if (pid == -1)
		px_error(NULL);
	if (!pid)
	{
		close(p_fd[0]);
		dup2(p_fd[1], 1);
		close(p_fd[1]);
		exec(cmd, data->envp);
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
		close(p_fd[0]);
		pids[data->index] = pid;
	}
}

int	main(int argc, char **argv, char **envp)
{
	int			i;
	int			in_fd;
	int			out_fd;
	pid_t		*pids;
	t_pbdata	data;

	i = check_here_doc(argv, argc, &out_fd, &in_fd);
	pids = (pid_t *)malloc((argc - 3) * (sizeof(pid_t)));
	if (!pids)
		px_error("Memory allocation faild");
	initdata(&data, argv, envp, i);
	initdata2(&data, pids, &out_fd, argc);
	dodo(&data);
	after_dodo(out_fd, &data);
	free(pids);
	return (0);
}
