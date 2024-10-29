/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:31:16 by kjung             #+#    #+#             */
/*   Updated: 2024/10/28 18:35:04 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 0);
		i++;
	}
	return (res * neg);
}

int	is_digit(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_input(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) <= 0)
		{
			print_error("Input error : arguments must bigger then 0");
			return (0);
		}
		j = 0;
		while (av[i][j])
		{
			if (is_digit(av[i][j]) == 0)
			{
				print_error("Input error : arguments must digit");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
