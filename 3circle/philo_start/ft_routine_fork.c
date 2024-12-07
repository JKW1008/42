/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:21:38 by kjung             #+#    #+#             */
/*   Updated: 2024/12/07 22:43:12 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	take_left_fork(t_philo *philo)
{
	if (pthread_mutex_lock(philo->left_fork) != 0)
		return (1);
	if (philo->args->is_dead)
	{
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	ft_print_status(philo, "has taken a fork");
	return (0);
}

static int	take_right_fork(t_philo *philo)
{
	if (pthread_mutex_lock(philo->right_fork) != 0)
		return (1);
	if (philo->args->is_dead)
	{
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	ft_print_status(philo, "has taken a fork");
	return (0);
}

int	take_forks(t_philo *philo)
{
	// if (philo->id % 2)
	// {
		if (take_left_fork(philo))
			return (1);
		if (take_right_fork(philo))
		{
			pthread_mutex_unlock(philo->left_fork);
			return (1);
		}
	// }
	// else
	// {
	// 	// if (usleep(100) == -1)
	// 	// 	return (1);
	// 	if (take_right_fork(philo))
	// 		return (1);
	// 	if (take_left_fork(philo))
	// 	{
	// 		pthread_mutex_unlock(philo->right_fork);
	// 		return (1);
	// 	}
	// }
	return (0);
}
