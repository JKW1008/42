/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:16:28 by kjung             #+#    #+#             */
/*   Updated: 2024/12/09 18:55:29 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*philo_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	ft_print_status(philo, "is thinking");
	if (philo->id % 2 == 0)
		ft_usleep(10);
	pthread_mutex_lock(&philo->args->dead_mutex);
	while (!philo->args->is_dead && \
	(philo->args->must_eat_cnt == -1 || philo->eat_count < philo->args->must_eat_cnt))
	{
		pthread_mutex_unlock(&philo->args->dead_mutex);
		philo->last_eat_time = ft_gettime();
		if (take_forks(philo))
		{
			ft_print_status(philo, "is thinking");
			pthread_mutex_lock(&philo->args->dead_mutex);
			continue ;
		}
		if (eating(philo))
		{
			pthread_mutex_lock(&philo->args->dead_mutex);
			break ;
		}
		if (sleeping(philo))
		{
			pthread_mutex_lock(&philo->args->dead_mutex);
			break ;
		}
		// if (philo->id % 2)
		// 	usleep(500);
		ft_print_status(philo, "is thinking");
		pthread_mutex_lock(&philo->args->dead_mutex);
	}
	
	pthread_mutex_unlock(&philo->args->dead_mutex);
	return (NULL);
}