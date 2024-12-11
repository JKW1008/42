/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:06:24 by kjung             #+#    #+#             */
/*   Updated: 2024/12/11 18:19:36 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

static int	check_all_ate(t_args *args, int i, int *all_eat)
{
	if (args->must_eat_cnt != -1)
	{
		pthread_mutex_lock(&args->eat_mutex);
		if (args->philo[i].eat_count < args->must_eat_cnt)
			*all_eat = 0;
		pthread_mutex_unlock(&args->eat_mutex);
	}
	return (0);
}

static int	check_philosopher_status(t_args *args, int i)
{
	long long	current_time;

	pthread_mutex_lock(&args->philo[i].time_mutex);
	current_time = ft_gettime();
	if (current_time - args->philo[i].last_eat_time > args->time_to_die)
	{
		ft_print_status(&args->philo[i], "died");
		pthread_mutex_lock(&args->dead_mutex);
		args->is_dead = 1;
		pthread_mutex_unlock(&args->dead_mutex);
		pthread_mutex_unlock(&args->philo[i].time_mutex);
		return (1);
	}
	pthread_mutex_unlock(&args->philo[i].time_mutex);
	return (0);
}

static int	monitor_one_cycle(t_args *args)
{
	int	i;
	int	all_eat;

	i = 0;
	all_eat = 1;
	while (i < args->number)
	{
		if (check_philosopher_status(args, i))
			return (1);
		check_all_ate(args, i++, &all_eat);
	}
	if (args->must_eat_cnt != -1 && all_eat)
	{	
		pthread_mutex_lock(&args->dead_mutex);
		args->is_dead = 1;
		pthread_mutex_unlock(&args->dead_mutex);
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_args		*args;

	args = (t_args *)arg;
	pthread_mutex_lock(&args->dead_mutex);
	while (!args->is_dead)
	{
		pthread_mutex_unlock(&args->dead_mutex);
		if (monitor_one_cycle(args))
			return (NULL);
		pthread_mutex_lock(&args->dead_mutex);
	}
	pthread_mutex_unlock(&args->dead_mutex);
	return (NULL);
}
