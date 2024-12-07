/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:03:20 by kjung             #+#    #+#             */
/*   Updated: 2024/12/07 18:05:29 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_close_thread(t_args *args)
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