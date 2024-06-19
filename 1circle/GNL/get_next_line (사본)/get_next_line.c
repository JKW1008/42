/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:51:32 by kjung             #+#    #+#             */
/*   Updated: 2024/04/25 16:13:20 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

#include <stdio.h>

int ft_strchr(const char *str, int c)
{
    int i;

    i = 0;
	while (str[i] != '\0')
	{
        if (str[i] == c)
            return (i);
        i++;
	}
    return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	char	*cp;

	if (!s)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	if (start >= ft_strlen(s))
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

char    *return_line(char **result)
{
    char    *temp;
    char    *new_line;

    int d = ft_strchr(*result, '\n');
    if (d > -1)
    {
        temp = ft_substr(*result, 0, d + 1);
        new_line = ft_substr(*result, d + 1, ft_strlen(*result) - d);
        free(*result);
        *result = new_line;
        return (temp);
    }
    else
    {
        temp = ft_strdup(*result);
        free(*result);
        *result = NULL;
        return (temp);
    }
}

char    *read_line(char *result, int fd)
{
    char    buf[BUFFER_SIZE + 1];
    int     i;
    char    *tmp;

    i = 1;
    if (!result)
        result = ft_strdup("");
    while (i > 0 && ft_strchr(result, '\n') == -1)
    {
		i = read(fd, buf, BUFFER_SIZE);
        buf[i] = '\0';
        if (i < 0)
            return (NULL);
        tmp = ft_strjoin(result, buf);
        free(result);
        result = tmp;
    }
    return (result);
}


char    *get_next_line(int fd)
{
    static char *result; //0x1234 result -> 0x4567 x []
    char    *copy;
    char    *tmp;

    copy = read_line(result, fd); //0x4567
    result = copy;
    if (!result)
        return (NULL);
    tmp = return_line(&result);
    if (*tmp == '\0')
    {
        free(tmp);
        return (NULL);
    }
    return (tmp);
}
