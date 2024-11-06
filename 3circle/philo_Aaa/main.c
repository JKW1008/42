/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 21:11:35 by kjung             #+#    #+#             */
/*   Updated: 2024/11/05 10:17:56 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	print_args(t_arg *arg)
{
	printf("philo_num is = %d\n", arg->philo_number);
	printf("time to die is = %d\n", arg->time_to_die);
	printf("eat time is = %d\n", arg->eat_time);
	printf("sleep time is = %d\n", arg->sleep_time);
	printf("nof_eat is %d\n", arg->nof_eat);
}

void	print_philos(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->philo_number)
	{
		printf("philo[%d].id = %d\n", i, arg->philo[i].id);
		printf("philo[%d].cnt_eat = %d\n", i, arg->philo[i].cnt_eat);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_arg	arg;

	if (ac == 5 || ac == 6)
	{
		if (check_input(av))
			return (1);
		if (init_args(&arg, av, ac))
			return (1);
		if (init_philo(&arg))
		{		
			free_arg(&arg);
			return (1);
		}
		if (init_mutex(&arg))
		{
			free_arg(&arg);
			return (1);
		}
		
		print_args(&arg);
		print_philos(&arg);
		free_arg(&arg);
	}
	else
		print_error("Input Error : must input arumetns 5 or 6");
	return (0);
}
