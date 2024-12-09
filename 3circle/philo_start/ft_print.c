/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:13:34 by kjung             #+#    #+#             */
/*   Updated: 2024/12/09 18:15:49 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_print_status(t_philo *philo, char *message)
{
	long long	current_time;

	pthread_mutex_lock(&(philo->args->dead_mutex));
	if (!philo->args->is_dead)
	{
		pthread_mutex_lock(&(philo->args->print_mutex));
		current_time = ft_gettime();
		if (current_time != -1)
		{
			printf("%lld %d %s\n", current_time - \
			philo->args->start_time, philo->id, message);
		}
		pthread_mutex_unlock(&(philo->args->print_mutex));
	}
	pthread_mutex_unlock(&(philo->args->dead_mutex));
}