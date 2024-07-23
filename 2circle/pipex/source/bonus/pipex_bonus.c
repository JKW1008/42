/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:58:58 by kjung             #+#    #+#             */
/*   Updated: 2024/07/23 16:26:04 by kjung            ###   ########.fr       */
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
		ft_putstr_fd("command not fount: ", 2);
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
		if (ft_strncmp(ret, argv[2], ft_strlen(argv[2])) == 0)
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
	int	p_fd[2];
	pid_t	pid;

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
		wait(NULL);
	}
}

void	do_pipe(char *cmd, char **envp)
{
	pid_t	pid;
	int		p_fd[2];

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
		exec(cmd, envp);
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
		close(p_fd[0]);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	in_fd;
	int	out_fd;
	
	if (argc < 5)
		px_error(NULL);
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[2])) == 0)
	{
		if (argc < 6)
			px_error(NULL);
		i = 3;
		out_fd = open_file(argv[argc - 1], 2);
		here_doc(argv);
	}
	else
	{
		i = 2;
		in_fd = open_file(argv[1], 0);
		out_fd = open_file(argv[argc - 1], 1);
		dup2(in_fd, 0);
		close(in_fd);
	}
	while (i < argc - 2)
		do_pipe(argv[i++], envp);
	dup2(out_fd, 1);
	close(out_fd);
	exec(argv[argc - 2], envp);
}
