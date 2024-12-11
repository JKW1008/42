/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:16:28 by kjung             #+#    #+#             */
/*   Updated: 2024/12/11 18:20:58 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

static int	philo_actions(t_philo *philo)
{
	if (take_forks(philo))
	{
		ft_print_status(philo, "is thinking");
		return (1);
	}
	if (eating(philo))
		return (2);
	if (sleeping(philo))
		return (2);
	ft_print_status(philo, "is thinking");
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	int		act;

	philo = (t_philo *)arg;
	ft_print_status(philo, "is thinking");
	if (philo->id % 2 == 0)
		ft_usleep(10);
	pthread_mutex_lock(&philo->args->dead_mutex);
	while (!philo->args->is_dead && \
	(philo->args->must_eat_cnt == -1 || \
	philo->eat_count < philo->args->must_eat_cnt))
	{
		pthread_mutex_unlock(&philo->args->dead_mutex);
		act = philo_actions(philo);
		pthread_mutex_lock(&philo->args->dead_mutex);
		if (act == 2)
			break ;
	}
	pthread_mutex_unlock(&philo->args->dead_mutex);
	return (NULL);
}
