/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:06:24 by kjung             #+#    #+#             */
/*   Updated: 2024/12/07 22:13:32 by kjung            ###   ########.fr       */
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
	while (!args->is_dead)
	{
		i = 0;
		all_eat = 1;
		while (i < args->number)
		{
			// 죽음 체크
			pthread_mutex_lock(&args->philo[i].time_mutex);
			current_time = ft_gettime();
			if (current_time - args->philo[i].last_eat_time > args->time_to_die)
			{
				ft_print_status(&args->philo[i], "died");
				args->is_dead = 1;
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
			return (NULL);
		usleep(100);
	}
	return (NULL);
}