/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:51:32 by kjung             #+#    #+#             */
/*   Updated: 2024/04/24 16:46:21 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*str;
	char	*result;

	str = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	result = str;
	while (*src)
		*str++ = *src++;
	*str = '\0';
	return (result);
}


size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	if (!dst && !size)
		return (0);
	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
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

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	i;

	i = 0;
	if (dst_size == 0)
		return (ft_strlen(src));
	while (src[i] && i < dst_size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, s1_len + 1);
	ft_strlcat(result + s1_len, s2, s2_len + 1);
    free((char *)s1);
	return (result);
}

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


// char    *get_next_line(int fd)
// {
//     static char *result;
//     char    a[BUFFER_SIZE + 1];
//     char    *temp;
//     char    *new_line;
//     int i;
//     int d;

//     i = read(fd, a, BUFFER_SIZE);
//     if (i <= 0)
//         return (NULL);
//     a[i] = '\0';
//     if (!result)
//         result = ft_strdup("");
//     // while (i > 0)
//     // {
//     //     i = read(fd, a, BUFFER_SIZE);
//     //     if (i == 0)
//     //         return (result);
//     //     result = ft_strjoin(result, a);
//     //     d = ft_strchr(result, '\n');
//     //     if (d > -1)
//     //         break ;
//     // }
//     // temp = (char *)malloc(sizeof(char) * (d + 1));
//     // ft_strlcpy(temp, result, d + 1);    // while ((line = get_next_line(fd)))
    // {
//     // new_line = ft_substr(result, d, ft_strlen(result));
//     // free(result);
//     // result = new_line;
//     // return (temp);
// }

// void	program_done(int buff, char *result, char *temp)
// {
// 	if (buff == 0)
// 	{
// 		free(result);
// 		free(temp);
// 		*result = '\0';
// 		*temp = '\0';
// 	}
// } kjung@c2r17s3  ~/Desktop/get_next_line  ./a.out 

char    *get_next_line(int fd)
{
    static char *result;
    char    a[BUFFER_SIZE + 1];
    char    *temp;
    char    *new_line;
    int i;
    int d;

    i = read(fd, a, BUFFER_SIZE);
    if (i <= 0)
        return (NULL);
    a[i] = '\0';
    if (!result)
        result = ft_strdup("");
    while (i > 0) 
    {
		// printf("a = %s\n", a);
        result = ft_strjoin(result, a);
		// printf("result = %s\n", result);
		if (ft_strchr(result, '\n') > -1)
            break ;
		i = read(fd, a, BUFFER_SIZE);
		a[i] = '\0';
		// if (i < BUFFER_SIZE || i == 0)
		// {
		// 	printf("%s\n", a);
		// 	break ;
		// }
		// printf("I : %d", i);
    }
    d = ft_strchr(result, '\n');
    if (d > -1)
    {
        temp = ft_substr(result, 0, d + 1);
        new_line = ft_substr(result, d + 1, ft_strlen(result) - d);
        free(result);
        result = new_line;
		// printf("temp = %s\n", temp);
        return (temp);
    }
    else
    {
		// printf("%s\n", result);
        temp = ft_strdup(result);
        free(result);
        result = NULL;
		// printf("temp = %s\n", temp);
        return (temp);
    }
}

int main(void)
{
    int fd;
    char *line;

    fd = open("hello.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("file open fail");
        return (1);
    }
// line = get_next_line(fd);
// printf("%s",line);
// free(line);
	while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
	// printf("%s", line);
	// free(line);
    close(fd);
    return (0);
}
