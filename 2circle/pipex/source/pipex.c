/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:54:30 by kjung             #+#    #+#             */
/*   Updated: 2024/07/24 23:57:45 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_data *str, int *pipe_fd)
{
	int		fd;
	char	**cmd;
	char	*path;

	cmd = ft_split(str->argv[2], ' ');
	path = find_path(str->envp, cmd[0]);
	fd = open(str->argv[1], O_RDONLY);
	if (!cmd || !cmd[0] || !path)
	{
		ft_printf("command not found: %s\n", str->argv[2]);
		exit(0);
	}
	if (fd == -1)
		px_error(str->argv[1]);
	dup2(fd, 0);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(fd);
	if (execve(path, cmd, str->envp) == -1)
	{
		perror("execve");
		exit(0);
	}
}

void	parent_process(t_data *str, int *pipe_fd)
{
	int		fd;
	char	**cmd;
	char	*path;

	cmd = ft_split(str->argv[3], ' ');
	path = find_path(str->envp, cmd[0]);
	fd = open(str->argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (!cmd || !path)
	{
		ft_printf("command not found: %s\n", str->argv[3]);
		exit(0);
	}
	if (fd == -1)
		px_error(str->argv[4]);
	dup2(fd, 1);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(fd);
	if (execve(path, cmd, str->envp) == -1)
	{
		perror("execve");
		exit(0);
	}
}

void	do_work2(t_data *str, int *pipe_fd, pid_t *pid)
{
	int	status;

	if (*pid == -1)
		px_error(NULL);
	else if (*pid == 0)
		parent_process(str, pipe_fd);
	else if (*pid > 0)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		waitpid(*str->pid, &status, 0);
		waitpid(*pid, &status, 0);
	}
}

void	do_work(t_data	*str, int *pipe_fd)
{
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		px_error(NULL);
	*str->pid = fork();
	if (*str->pid == -1)
		px_error(NULL);
	else if (*str->pid == 0)
		child_process(str, pipe_fd);
	else if (*str->pid > 0)
	{
		pid = fork();
		do_work2(str, pipe_fd, &pid);
	}	
}

int	main(int argc, char **argv, char **envp)
{
	t_data	str;
	pid_t	pid;
	int		pipe_fd[2];

	if (argc != 5)
		px_error(NULL);
	if (argc == 5)
	{
		if (access(argv[1], R_OK) == -1)
			perror(argv[1]);
		init_struct(&str, argv, envp, &pid);
		do_work(&str, pipe_fd);
	}
	return (0);
}
