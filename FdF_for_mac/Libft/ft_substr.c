/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:20:06 by kjung             #+#    #+#             */
/*   Updated: 2024/04/16 12:35:58 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
