/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:49:15 by kjung             #+#    #+#             */
/*   Updated: 2024/10/29 23:23:23 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	print_error(char *str)
{
	ft_putstr(str, 1);
	return (0);
}

void	print_status(t_philo *philo, char *str)
{
	chk_done(philo, 0);
	ft_putnbr(get_time() - philo->last_eat, 1);
	ft_putstr(" ", 1);
	ft_putnbr(philo->id, 1);
	ft_putstr(" ", 1);
	ft_putstr(str, 1);
}