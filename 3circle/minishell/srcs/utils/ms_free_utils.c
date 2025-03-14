/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_free_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 23:53:04 by kjung             #+#    #+#             */
/*   Updated: 2024/11/30 23:43:53 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_split_free(char ***sp)
{
	int	idx;

	idx = 0;
	while ((*sp)[idx])
	{
		free((*sp)[idx]);
		idx++;
	}
	free(*sp);
	return (0);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	print_export_env(char **envp)
{
	printenv(envp, 1);
}

void	print_error_and_free(char **divided, const char *message)
{
	printf("%s\n", message);
	free_split(divided);
}
