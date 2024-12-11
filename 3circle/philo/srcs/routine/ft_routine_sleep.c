/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine_sleep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:57:11 by kjung             #+#    #+#             */
/*   Updated: 2024/12/11 18:21:32 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

int	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->dead_mutex);
	if (philo->args->is_dead)
	{
		pthread_mutex_unlock(&philo->args->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->args->dead_mutex);
	ft_print_status(philo, "is sleeping");
	ft_usleep(philo->args->time_to_sleep);
	return (0);
}
