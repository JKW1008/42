/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:43:57 by kjung             #+#    #+#             */
/*   Updated: 2024/04/09 14:40:27 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*result;

	result = dest;
	if (!dest && !src)
		return (NULL);
	if (dest <= src)
	{
		while (n--)
			*(unsigned char *)dest++ = *(unsigned char *)src++;
	}
	else
	{
		while (n--)
			*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
	}
	return (result);
}
