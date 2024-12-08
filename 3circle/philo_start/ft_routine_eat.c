/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine_eat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:47:11 by kjung             #+#    #+#             */
/*   Updated: 2024/12/09 18:20:25 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int    eating(t_philo *philo)
{
	long long	current_time;
	
	pthread_mutex_lock(&philo->time_mutex);
	current_time = ft_gettime();
	if (current_time == -1)
	{
		pthread_mutex_unlock(&philo->time_mutex);
		return (1);
	}
	philo->last_eat_time = current_time;
	pthread_mutex_unlock(&philo->time_mutex);
	pthread_mutex_lock(&philo->args->dead_mutex);
	if (philo->args->is_dead)
	{
		pthread_mutex_unlock(&philo->args->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->args->dead_mutex);
	ft_print_status(philo, "is eating");
	ft_usleep(philo->args->time_to_eat);
	pthread_mutex_lock(&philo->args->eat_mutex);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->args->eat_mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}
