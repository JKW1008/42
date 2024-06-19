/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:19:47 by kjung             #+#    #+#             */
/*   Updated: 2024/04/16 13:17:10 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	count;

	if (!*little)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (*big && len > 0)
	{
		count = 0;
		while (big[count] == little[count] && count < len)
		{
			count++;
			if (little[count] == 0)
				return ((char *)big);
		}
		big++;
		len--;
	}
	return (NULL);
}
