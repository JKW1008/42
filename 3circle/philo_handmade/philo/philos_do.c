/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_do.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:52:53 by kjung             #+#    #+#             */
/*   Updated: 2024/11/05 10:49:07 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	take_a_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->arg->fork[philo->l_fork]);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->arg->fork[philo->r_fork]);
	print_status(philo, "has taken a fork");
}

void	drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->arg->fork[philo->l_fork]);
	pthread_mutex_unlock(&philo->arg->fork[philo->r_fork]);
}

void	do_eat(t_philo *philo)
{
	print_status(philo, "is eating");
	philo->last_eat = get_time();
	usleep(philo->arg->eat_time * 1000);
	pthread_mutex_lock(&philo->arg->eat_mutex);
	philo->cnt_eat++;
	pthread_mutex_unlock(&philo->arg->eat_mutex);
	drop_fork(philo);
	do_sleep(philo);
}

void	do_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping");
	usleep(philo->arg->sleep_time * 1000);
}

void	*do_philos(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	print_status(philo, "is thinking");
	if (philo->id % 2 == 0)
		usleep(philo->arg->eat_time /2);
	while (1)
	{
		if (chk_done(philo, 0))
			return (NULL);
		take_a_fork(philo);
		do_eat(philo);
		// drop_fork(philo);
		// do_sleep(philo);
		print_status(philo, "is thinking");
	}
	return (NULL);
}