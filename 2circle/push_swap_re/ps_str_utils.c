/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:26:49 by kjung             #+#    #+#             */
/*   Updated: 2024/06/30 23:13:36 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(long long neg, long long result)
{
	if (neg == -1)
	{
		if (result * neg < -2147483648)
		{
			printf("result == %lld\n", result);
			ft_printf("HError\n");
			exit (1);
		}
	}
	else
	{
		if (!(result >= -2147483648 && result <= 2147483647))
		{
			ft_printf("Error\n");
			exit(1);
		}
	}
}

long long	ft_atol(const char *str)
{
	long long	result;
	long long	neg;

	result = 0;
	neg = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' \
			|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		result = result * 10 + (*str - '0');
		ft_error(neg, result);
		str++;
	}
	return (result * neg);
}
