/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:05:24 by kjung             #+#    #+#             */
/*   Updated: 2024/06/13 16:10:47 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_split(char **line)
{
	int	i;

	i = 0;
	if (!line)
		return ;
	while (line[i] != NULL)
	{
		free(line[i]);
		i++;
	}
	free(line);
}

int	check_file_path(char *file_path)
{
	char	**path_divided;
	int		divided_length;
	int		answer;

	answer = 0;
	divided_length = 0;
	path_divided = ft_split(file_path, '.');
	if (!path_divided)
		return (ft_printf("file name err"));
	while (path_divided[divided_length] != 0)
		divided_length++;
	if (ft_strncmp(path_divided[divided_length - 1], "fdf", 4) == 0)
		answer = 1;
	while (divided_length >= 0)
	{
		free(path_divided[divided_length]);
		divided_length--;
	}
	free(path_divided);
	return (answer);
}

int	check_colum(char *line)
{
	char	**divided;
	int		i;

	i = 0;
	divided = ft_split(line, ' ');
	while (divided[i] != NULL && ft_strncmp(divided[i], "\n", 10))
		i++;
	free_split(divided);
	return (i);
}

int	check_comma(char *comma_line)
{
	int	i;

	i = 0;
	while (comma_line[i])
	{
		if (comma_line[i] == ',')
			return (i);
		i++;
	}
	return (-1);
}
