/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:30:02 by kjung             #+#    #+#             */
/*   Updated: 2024/07/16 17:41:53 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp, char *str)
{
	int	i;
	char	**divided;
	char	**split;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	printf("%s\n", envp[i]);
	divided = ft_split(envp[i], '=');
	printf("divided 1 = %s\n", divided[0]);
	printf("divided 2 = %s\n", divided[1]);
	split = ft_split(divided[1], ':');
	for (int i = 0; split[i]; i++)
	{
		printf("split[%d] = %s\n", i, split[i]);
	}
	char	*file_name;
	for (int i = 0; split[i]; i++)
	{
		file_name = ft_strjoin(split[i], "/");
		file_name = ft_strjoin(file_name, str);
		if (access(file_name, F_OK | X_OK) == 0)
			return (file_name);
	}
	return NULL;
}