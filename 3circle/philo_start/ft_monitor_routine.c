/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:06:24 by kjung             #+#    #+#             */
/*   Updated: 2024/12/09 19:11:47 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void    *monitor_routine(void *arg)
{
	t_args		*args;
	int			i;
	long long	current_time;
	int			all_eat;

	args = (t_args *)arg;
	pthread_mutex_lock(&args->dead_mutex);
	while (!args->is_dead)
	{
		pthread_mutex_unlock(&args->dead_mutex);
		i = 0;
		all_eat = 1;
		while (i < args->number)
		{
			// 죽음 체크
			pthread_mutex_lock(&args->philo[i].time_mutex);
			current_time = ft_gettime();
			if (current_time - args->philo[i].last_eat_time > args->time_to_die)
			{
				// pthread_mutex_unlock(&args->philo[i].left_fork);
				// pthread_mutex_unlock(&args->philo[i].right_fork);
				ft_print_status(&args->philo[i], "died");
				pthread_mutex_lock(&args->dead_mutex);
				args->is_dead = 1;
				pthread_mutex_unlock(&args->dead_mutex);
				pthread_mutex_unlock(&args->philo[i].time_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(&args->philo[i].time_mutex);

			// 식사 횟수 체크
			if (args->must_eat_cnt != -1)
			{
				pthread_mutex_lock(&args->eat_mutex);
				if (args->philo[i].eat_count < args->must_eat_cnt)
					all_eat = 0;
				pthread_mutex_unlock(&args->eat_mutex);
			}
			i++;
		}
		// 모든 철학자가 충분히 먹었는지 확인
		if (args->must_eat_cnt != -1 && all_eat)
		{
			args->is_dead = 1;
			return (NULL);
		}
		pthread_mutex_lock(&args->dead_mutex);
	}
	pthread_mutex_unlock(&args->dead_mutex);
	return (NULL);
}