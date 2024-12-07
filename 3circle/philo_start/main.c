/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:25:39 by kjung             #+#    #+#             */
/*   Updated: 2024/12/07 22:17:22 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (0);
	return (1);
}

int	check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]))
				return (1);
			j++;
		}
		if (ft_atoi(av[i]) < 0)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_args	args;

	if (ac == 5 || ac == 6)
	{
		if (check_args(ac, av))
		{
			printf("Error: Invalid argument value must be a positive number\n");
			return (1);
		}
		if (init(ac, av, &args))
		{
			printf("Error: init faild\n");
			return (1);
		}
		if (ft_create_philo(&args))
		{
			return (1);
		}
	}
	return (0);
}
