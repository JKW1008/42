/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:58:58 by kjung             #+#    #+#             */
/*   Updated: 2024/07/25 23:13:15 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "../pipex.h"

void	exec(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = find_path(env, s_cmd[0]);
	execve(path, s_cmd, env);
}

void	setup_here_doc(int ac, char **av, char **env)
{
	int	i;
	int	out;
	int	p_fd[2];

	if (ac < 6)
		px_error(NULL);
	i = 3;
	out = open_file(av[ac - 1], 1);
	if (out == -1)
		px_error(av[ac - 1]);
	here_doc(av);
	while (i < ac - 2)
		do_pipe(av[i++], env, p_fd, 0);
	dup2(out, 1);
	do_pipe(av[ac - 2], env, p_fd, 1);
	while (wait(NULL) > 0)
		;
	close(out);
}

void	setup_pipes_and_execute(int ac, char **av, char **env)
{
	int	i;
	int	in;
	int	out;
	int	p_fd[2];

	if (ac < 5)
		px_error(NULL);
	i = 2;
	in = open_file(av[1], 0);
	if (in == -1)
		px_error(av[1]);
	out = open_file(av[ac - 1], 1);
	if (out == -1)
		px_error(av[ac - 1]);
	dup2(in, 0);
	while (i < ac - 2)
		do_pipe(av[i++], env, p_fd, 0);
	dup2(out, 1);
	do_pipe(av[ac - 2], env, p_fd, 1);
	while (wait(NULL) > 0)
		;
	close(in);
	close(out);
}

int	main(int ac, char **av, char **env)
{
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		if (access(av[ac - 1], W_OK) == -1)
			perror(av[ac - 1]);
		setup_here_doc(ac, av, env);
	}
	else
	{	
		if (access(av[1], R_OK) == -1)
			perror(av[1]);
		if (access(av[ac - 1], F_OK) == 0)
		{
			if (access(av[ac - 1], W_OK) == -1)
				ft_printf("%s: Permission denied\n", av[ac - 1]);
		}
		setup_pipes_and_execute(ac, av, env);
	}
	return (0);
}
