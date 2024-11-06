/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:25:46 by kjung             #+#    #+#             */
/*   Updated: 2024/10/31 21:09:07 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 - time.tv_sec / 1000);
}

int	chk_done(t_philo *philo, int status)
{
	pthread_mutex_lock(&philo->arg->finish_mutex);
	if (status)
		philo->arg->chk_finish = 1;
	if (philo->arg->chk_finish)
	{
		pthread_mutex_unlock(&philo->arg->finish_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->arg->finish_mutex);
	return (0);
}

int	chk_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->arg->eat_mutex);
	if (get_time() - philo->last_eat >= philo->arg->time_to_die)
	{
		print_status(philo, "died");
		chk_done(philo, 1);
		pthread_mutex_unlock(&philo->arg->eat_mutex);
		return (1);
	}
	else if (philo->arg->nof_eat != -1 && philo->cnt_eat >= philo->arg->nof_eat)
	{
		philo->arg->cnt_group_eat++;
		if (philo->arg->cnt_group_eat >= philo->arg->nof_eat)
		{
			chk_done(philo, 1);
			pthread_mutex_unlock(&philo->arg->eat_mutex);
			return (1);
		}
	}
	pthread_mutex_unlock(&philo->arg->eat_mutex);
	return (0);
}

int	free_arg(t_arg *arg)
{
	int	i;

	if (arg->fork)
	{
		i = 0;
		while (i < arg->philo_number)
		{
			pthread_mutex_destroy(&arg->fork[i]);
			i++;
		}
		free(arg->fork);
		arg->fork = NULL;
	}
	if (arg->philo)
	{
		free(arg->philo);
		arg->philo = NULL;
	}
	pthread_mutex_destroy(&arg->print);
	pthread_mutex_destroy(&arg->finish_mutex);
	pthread_mutex_destroy(&arg->eat_mutex);
	return (0);
}

int	call_chk(t_arg *arg)
{
	int	i;
	int	status;

	status = 1;
	while (status)
	{
		i = 0;
		arg->nof_eat = 0;
		while (i < arg->philo_number)
		{
			if (chk_dead(&arg->philo[i]))
				status = 0;
			i++;
		}
	}
	i = 0;
	while (i < arg->philo_number)
	{
		pthread_join(arg->philo[i].thread, NULL);
		i++;
	}
	return (free_arg(arg));
}
