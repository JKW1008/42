/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_do_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 21:44:15 by kjung             #+#    #+#             */
/*   Updated: 2024/07/25 21:45:14 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "../pipex.h"

void	do_work3(char *cmd, char **env, pid_t *pid, int *p_fd)
{
	int	status;

	if (*pid == -1)
		px_error(NULL);
	else if (*pid == 0)
	{
		close(p_fd[0]);
		if (dup2(p_fd[1], 1) == -1)
			px_error("dup2");
		close(p_fd[1]);
		exec(cmd, env);
	}
	else if (*pid > 0)
	{
		close(p_fd[0]);
		close(p_fd[1]);
		waitpid(*pid, &status, 0);
	}
}

void	do_pipe2(int *p_fd, int is_last)
{
	if (!is_last)
	{
		close(p_fd[0]);
		if (dup2(p_fd[1], 1) == -1)
			px_error("dup2");
		close(p_fd[1]);
	}
}

void	do_pipe3(int *p_fd, int is_last)
{
	if (!is_last)
	{
		close(p_fd[1]);
		if (dup2(p_fd[0], 0) == -1)
			px_error("dup2");
		close(p_fd[0]);
	}
}

void	do_pipe(char *cmd, char **env, int *p_fd, int is_last)
{
	pid_t	pid;

	check_cmd(cmd, env);
	if (pipe(p_fd) == -1)
		px_error("pipe");
	pid = fork();
	if (pid == -1)
		px_error("fork");
	else if (pid == 0)
	{
		do_pipe2(p_fd, is_last);
		exec(cmd, env);
	}
	else
		do_pipe3(p_fd, is_last);
}
