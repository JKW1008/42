/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:42:45 by kjung             #+#    #+#             */
/*   Updated: 2024/07/25 22:47:54 by kjung            ###   ########.fr       */
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

char	*check_absolute_or_home_path(char *str)
{
	char	*home_path;
	char	*res;

	if (str[0] == '/' || ft_strncmp(str, "./", 2) == 0)
		res = ft_strdup(str);
	else if (ft_strncmp(str, "~/", 2) == 0)
	{
		home_path = getenv("HOME");
		if (!home_path)
			return (NULL);
		res = ft_strjoin(home_path, str + 1);
	}
	else
		return (NULL);
	if (access(res, F_OK | X_OK) == 0)
		return (res);
	else
	{
		free(res);
		return (NULL);
	}
}
