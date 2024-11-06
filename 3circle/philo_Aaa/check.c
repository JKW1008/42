/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:22:21 by kjung             #+#    #+#             */
/*   Updated: 2024/11/04 18:23:50 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_input(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) <= 0)
		{
			print_error("Input error : arguments must bigger then 0\n");
			return (1);
		}
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]))
			{
				print_error("Input error : arguments must digit\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
