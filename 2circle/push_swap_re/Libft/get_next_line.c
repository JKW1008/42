/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:51:32 by kjung             #+#    #+#             */
/*   Updated: 2024/07/01 20:54:51 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_gnl_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	char	*cp;

	if (!s)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	if (start >= ft_gnl_strlen(s))
	{
		*result = 0;
		return (result);
	}
	len = len + start;
	cp = result;
	while (start < len)
	{
		*cp = s[start];
		if (*cp == 0)
			return (result);
		cp++;
		start++;
	}
	*cp = 0;
	return (result);
}

char	*return_gnl_line(char **result)
{
	char	*temp;
	char	*new_line;
	int		d;

	d = ft_gnl_strchr(*result, '\n');
	if (d > -1)
	{
		temp = ft_gnl_substr(*result, 0, d + 1);
		new_line = ft_gnl_substr(*result, d + 1, ft_gnl_strlen(*result) - d);
		free(*result);
		*result = new_line;
		return (temp);
	}
	else
	{
		temp = ft_gnl_strdup(*result);
		free(*result);
		*result = NULL;
		return (temp);
	}
}

char	*read_gnl_line(char *result, int fd)
{
	char	*buf;
	int		i;
	char	*tmp;

	i = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (i > 0 && ft_gnl_strchr(result, '\n') == -1)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i < 0)
		{
			free (result);
			free(buf);
			return (NULL);
		}
		buf[i] = '\0';
		tmp = ft_gnl_strjoin(result, buf);
		free(result);
		result = tmp;
	}
	free(buf);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*result;
	char		*tmp;

	if (!(fd >= 0 && fd <= 1023))
		return (NULL);
	if (BUFFER_SIZE < 1)
		return (NULL);
	if (!result)
		result = ft_gnl_strdup("");
	result = read_gnl_line(result, fd);
	if (!result)
		return (NULL);
	tmp = return_gnl_line(&result);
	if (*tmp == '\0')
	{
		free(tmp);
		return (NULL);
	}
	return (tmp);
}
