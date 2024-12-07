/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine_sleep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:57:11 by kjung             #+#    #+#             */
/*   Updated: 2024/12/07 22:00:17 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	sleeping(t_philo *philo)
{
	ft_print_status(philo, "is sleeping");
	if (usleep(philo->args->time_to_sleep * 1000) == -1)
		return (1);
	return (0);
}