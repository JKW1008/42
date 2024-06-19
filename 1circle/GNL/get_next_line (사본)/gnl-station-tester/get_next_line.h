/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:19:42 by kjung             #+#    #+#             */
/*   Updated: 2024/04/25 15:19:44 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size);
char	*ft_strjoin(char const *s1, char const *s2);
int ft_strchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char    *get_next_line(int fd);

#endif