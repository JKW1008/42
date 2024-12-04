/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:32:27 by kjung             #+#    #+#             */
/*   Updated: 2024/12/04 18:39:35 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	reset_mutex(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->number)
	{
		if(pthread_mutex_init(&(args->forks[i]), NULL))
		{
			while (--i >= 0)
				pthread_mutex_destroy(&(args->forks[i]));
			free(args->forks);
			free(args->philo);
			return (1);
		}
	}
	if (pthread_mutex_init(&(args->print_mutex), NULL))
	{
		i = 0;
		while (i < args->number)
			pthread_mutex_destroy(&(args->forks[i++]));
		free(args->forks);
		free(args->philo);
		return (1);
	}
	return (0);
}

static int	init_args(int ac, char **av, t_args *args)
{
	int	i;

	i = 0;
	args->number = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		args->must_eat_cnt = ft_atoi(av[5]);
	else
		args->must_eat_cnt = -1;
	args->is_dead = 0;
	args->forks = malloc(sizeof(pthread_mutex_t) * args->number);
	if (!args->forks)
		return (1);
	args->philo = malloc(sizeof(t_philo) * args->number);
	if (!args->philo)
	{
		free(args->forks);
		return (1);
	}
	if (reset_mutex(args))
		return (1);
	return (0);
}

static int	init_philo(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->number)
	{
		args->philo[i].id = i + 1;
		args->philo[i].eat_count =0;
		args->philo[i].last_eat_time = 0;
		args->philo[i].args = args;
		args->philo[i].left_fork = &(args->forks[i]);
		args->philo[i].left_fork = &(args->forks[(i + 1) % args->number]);
		i++;
	}
	return (0);
}

int	init(int ac, char **av, t_args *args)
{
	if (init_args(ac, av, args))
		return (1);
	if (init_philo(args))
		return (1);
	return (0);
}