/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:52:48 by kjung             #+#    #+#             */
/*   Updated: 2024/11/04 18:52:53 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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