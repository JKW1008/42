/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_string_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:59:44 by kjung             #+#    #+#             */
/*   Updated: 2024/06/05 23:22:23 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned long long	hex_string_to_int(char c)
{
	if ('0' <= c && '9' >= c)
		return (c - '0');
	if ('a' <= c && 'f' >= c)
		return (10 + (c - 'a'));
	if ('A' <= c && 'F' >= c)
		return (10 + (c - 'A'));
	return (0);
}

unsigned long long	string_to_hex(char *hex_string)
{
	unsigned long long	result;
	const char			*p;

	p = hex_string;
	result = 0;
	if (p[0] == '0' && (p[1] == 'x' || p[1] == 'X'))
		p += 2;
	while (*p)
	{
		result = result * 16 + hex_string_to_int(*p);
		p++;
	}
	return (result);
}
