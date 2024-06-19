/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:19:03 by kjung             #+#    #+#             */
/*   Updated: 2024/04/08 17:19:04 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int value, size_t size)
{
	while (size-- > 0)
	{
		if (*(unsigned char *)str == (unsigned char)value)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
