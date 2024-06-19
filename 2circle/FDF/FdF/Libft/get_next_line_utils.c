/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:17:24 by kjung             #+#    #+#             */
/*   Updated: 2024/04/25 15:17:26 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_gnl_strdup(const char *src)
{
	char	*str;
	char	*result;

	str = (char *)malloc((ft_gnl_strlen(src) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	result = str;
	while (*src)
		*str++ = *src++;
	*str = '\0';
	return (result);
}

size_t	ft_gnl_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	if (!dst && !size)
		return (0);
	i = 0;
	dst_len = ft_gnl_strlen(dst);
	src_len = ft_gnl_strlen(src);
	if (size < dst_len + 1)
		return (size + src_len);
	while (*src && dst_len + i + 1 < size)
	{
		*(dst + dst_len + i) = *src++;
		i++;
	}
	*(dst + dst_len + i) = '\0';
	return (dst_len + src_len);
}

size_t	ft_gnl_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	i;

	i = 0;
	if (dst_size == 0)
		return (ft_gnl_strlen(src));
	while (src[i] && i < dst_size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_gnl_strlen(src));
}

char	*ft_gnl_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_gnl_strlen(s1);
	s2_len = ft_gnl_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!result)
		return (NULL);
	ft_gnl_strlcpy(result, s1, s1_len + 1);
	ft_gnl_strlcat(result + s1_len, s2, s2_len + 1);
	return (result);
}
