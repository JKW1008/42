/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:26:19 by kjung             #+#    #+#             */
/*   Updated: 2024/07/24 20:47:07 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "../pipex.h"

int	open_file(char *file, int in_or_out)
{
	int	ret;

	if (in_or_out == 0)
		ret = open(file, O_RDONLY, 0777);
	if (in_or_out == 1)
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (in_or_out == 2)
		ret = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (ret == -1)
		exit(0);
	return (ret);
}

void	dodo(t_pbdata *data)
{
	int	i;
	int	j;
	int	p_fd[2];

	i = data->i;
	j = 0;
	while (i < data->argc - 2)
	{
		data->index = j;
		do_pipe(data->argv[i++], data, &data->pid[j], p_fd);
		j++;
	}
}

void	after_dodo(int out_fd, t_pbdata *data)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		px_error(NULL);
	if (!pid)
	{
		dup2(out_fd, 1);
		close(out_fd);
		exec(data->argv[data->argc - 2], data->envp);
	}
	else
	{
		close(out_fd);
		if (data->i < data->argc - 3)
		{
			data->pid[data->i++] = pid;
			while (data->i < data->argc - 3)
				waitpid(data->pid[data->i++], NULL, 0);
		}
		waitpid(pid, NULL, 0);
	}
}

int	check_here_doc(char **av, int ac, int *out, int *in)
{
	int	i;

	i = 0;
	if (ac < 5)
		px_error(NULL);
	if (ft_strncmp(av[1], "here_doc", ft_strlen(av[2])) == 0)
	{
		if (ac < 6)
			px_error(NULL);
		i = 3;
		*out = open_file(av[ac - 1], 2);
		here_doc(av);
	}
	else
	{
		i = 2;
		*in = open_file(av[1], 0);
		*out = open_file(av[ac - 1], 1);
		dup2(*in, 0);
		close(*in);
	}
	return (i);
}
