/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:30:02 by kiung             #+#    #+#             */
/*   Updated: 2024/07/25 00:12:43 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_struct(t_data *str, char **argv, char **evnp, pid_t *pid)
{
	str->argv = argv;
	str->envp = evnp;
	str->pid = pid;
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

char	*check_access(char *split, char *str)
{
	char	*filename;
	char	*tmp;

	if (!split || !str)
		return (NULL);
	tmp = ft_strjoin(split, "/");
	if (!tmp)
		return (NULL);
	filename = ft_strjoin(tmp, str);
	printf("%s\n", filename);
	free(tmp);
	if (!filename)
		return (NULL);
	if (access(filename, F_OK | X_OK) == 0)
		return (filename);
	else
		return (NULL);
	free(filename);
	return (NULL);
}

char	*fp_while(char **split, char *str)
{
	int		i;
	char	*res;

	i = 0;
	while (split[i])
	{
		res = check_access(split[i], str);
		if (res != NULL)
			return (res);
		i++;
	}
	return (NULL);
}

char	*find_path(char **envp, char *str)
{
	int		i;
	char	**divided;
	char	**split;
	char	*res;

	i = 0;
	printf("%s", str);
	if (access(str, F_OK | X_OK) == 0)
		return (str);
	while (ft_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	divided = ft_split(envp[i], '=');
	split = ft_split(divided[1], ':');
	res = fp_while(split, str);
	if (res != NULL)
	{
		free_split(divided);
		free_split(split);
		return (res);
	}
	free_split(divided);
	free_split(split);
	return (NULL);
}
