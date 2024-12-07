/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:28:04 by kjung             #+#    #+#             */
/*   Updated: 2024/12/07 22:48:40 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	ft_create_monitor(t_args *args)
{
	if (pthread_create(&(args->monitor), NULL, monitor_routine, args))
		return (1);
	return (0);
}

int	ft_create_philo(t_args *args)
{
	int	i;

	i = 0;
	args->start_time = ft_gettime();
	while (i < args->number)
	{
		if (args->philo[i].id % 2)
		{
			if (pthread_create(&(args->philo[i].thread), NULL, philo_routine, &(args->philo[i])))
				return (1);
		}
		else
		{
			usleep(100);
			if (pthread_create(&(args->philo[i].thread), NULL, philo_routine, &(args->philo[i])))
				return (1);
		}
		i++;
	}
	if (ft_create_monitor(args))
		return (1);
	return (0);
}
