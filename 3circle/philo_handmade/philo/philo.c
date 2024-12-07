/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:22:11 by kjung             #+#    #+#             */
/*   Updated: 2024/11/05 10:25:02 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo(t_arg *args)
{
	int	i;

	i = 0;
	if (args->philo_number == 1)
	{
		print_status(&args->philo[0], "has taken a fork");
		usleep(args->time_to_die * 1000);
		print_status(&args->philo[0], "died");
		chk_done(args->philo, 1);
		pthread_join(args->philo[0].thread, NULL);  // & 제거
		return (0);
	}
	while (i < args->philo_number)
	{
		if (pthread_create(&args->philo[i].thread, NULL, do_philos, &args->philo[i]))
			return (print_error("Thread Error : create fail"));
		usleep(10);
		i++;
	}
	return (0);
}