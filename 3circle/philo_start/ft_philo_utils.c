/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:54:17 by kjung             #+#    #+#             */
/*   Updated: 2024/12/07 22:10:55 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long long	ft_gettime()
{
	struct timeval	tv;
	long long		time;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

void	cleanup_all_mutex(t_args *args, int philo_count)
{
	int	i;

	i = 0;
	while (i < philo_count)
		pthread_mutex_destroy(&(args->philo[i++].time_mutex));
	pthread_mutex_destroy(&(args->eat_mutex));
	pthread_mutex_destroy(&(args->print_mutex));
	i = 0;
	while (i < args->number)
		pthread_mutex_destroy(&(args->forks[i++]));
	free(args->forks);
	free(args->philo);
}

int	cleanup_thread(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->number)
	{
		if (pthread_join(args->philo[i].thread, NULL))
			return (1);
		i++;
	}
	if (pthread_join(args->monitor, NULL))
		return (1);
	return (0);
}