/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:49:01 by kjung             #+#    #+#             */
/*   Updated: 2024/11/04 19:27:37 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_args(t_arg *arg, char **av, int ac)
{
	arg->philo_number = ft_atoi(av[1]);
	arg->philo_number = ft_atoi(av[1]);
	arg->time_to_die = ft_atoi(av[2]);
	arg->eat_time = ft_atoi(av[3]);
	arg->sleep_time = ft_atoi(av[4]);
	arg->time_stamp = get_time();
	arg->chk_finish = 0;
	if (arg->time_stamp == 1)
	{
		print_error("Time error : error gettimeofday()");
		return (1);
	}
	if (ac == 6)
		arg->nof_eat = ft_atoi(av[5]);
	else
		arg->nof_eat = -1;
	return (0);
}

int	init_mutex(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->philo_number)
	{
		if (pthread_mutex_init(&arg->fork[i], NULL) == -1)
			return (print_error("Mutex Error : mutex init error"));
		i++;
	}
	if (pthread_mutex_init(&arg->print, NULL) == -1)
		return (print_error("Mutex Error : mutex init error"));
	if (pthread_mutex_init(&arg->finish_mutex, NULL) == -1)
		return (print_error("Mutex Error : mutex init error"));
	if (pthread_mutex_init(&arg->eat_mutex, NULL) == -1)
		return (print_error("Mutex Error : mutex init error"));
	return (0);
}

int	init_philo(t_arg *arg)
{
	int	i;

	i = 0;
	arg->philo = malloc(sizeof(t_philo) * arg->philo_number);
	if (!arg->philo)
	{
		free_arg(arg);
		return (print_error("Alloc Error : memory allocation error"));
	}
	arg->fork = malloc(sizeof(pthread_mutex_t) * arg->philo_number);
	if (!arg->fork)
	{
		free_arg(arg);
		return (print_error("Alloc Error : memory allocation error"));
	}
	while (i < arg->philo_number)
	{
		arg->philo[i].id = i + 1;
		arg->philo[i].cnt_eat = 0;
		arg->philo[i].l_fork = i;
		arg->philo[i].r_fork = (i + 1) % arg->philo_number;
		arg->philo[i].last_eat = arg->time_stamp;
		arg->philo[i++].arg = arg;
	}
	return (0);
}
