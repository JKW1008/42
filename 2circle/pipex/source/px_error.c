/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:42:45 by kjung             #+#    #+#             */
/*   Updated: 2024/07/24 23:57:16 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	px_error(char *argv)
{
	if (errno == 0)
		ft_printf("Invalid number of factors. ./pipex file1 cmd1 cmd2 file2.\n");
	else if (errno == 1)
		perror(argv);
	else if (errno == 11 || errno == 12)
		perror("fork");
	else if (errno == 23 || errno == 24)
		perror("pipe");
	else if (errno == ENOSYS || errno == ENOENT)
		perror(argv);
	else if (errno == 127)
		perror(argv);
	exit(1);
}

void	file_check(char **av, int ac)
{
	if (access(av[1], F_OK) == -1 || access(av[1], R_OK) == -1)
		perror(av[1]);
	if (access(av[ac - 1], W_OK) == -1)
		perror(av[ac - 1]);
}