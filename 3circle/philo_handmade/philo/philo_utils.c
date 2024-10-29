/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:25:46 by kjung             #+#    #+#             */
/*   Updated: 2024/10/29 22:48:04 by kjung            ###   ########.fr       */
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