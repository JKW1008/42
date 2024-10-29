/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:22:11 by kjung             #+#    #+#             */
/*   Updated: 2024/10/29 23:43:33 by kjung            ###   ########.fr       */
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
		usleep(args->time_to_die * 100);
		print_status(&args->philo[0], "died");
		chk_done(&args->philo[0], 1);
		pthread_join(&args->philo[0].thread, NULL);
		return (1);
	}
	while
}