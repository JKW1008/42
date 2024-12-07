/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:16:28 by kjung             #+#    #+#             */
/*   Updated: 2024/12/07 22:44:12 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*philo_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	// if (philo->id % 2 == 0)
	// {
	// 	if(usleep(100) == -1)
	// 		return (NULL);
	// }
	while (!philo->args->is_dead && \
	(philo->args->must_eat_cnt == -1 || philo->eat_count < philo->args->must_eat_cnt))
	{
		if (take_forks(philo))
		{
			ft_print_status(philo, "is thinking");
			continue ;
		}
		if (eating(philo))
			break ;
		if (sleeping(philo))
			break ;
		ft_print_status(philo, "is thinking");
	}
	return (NULL);
}