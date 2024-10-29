/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:12:22 by kjung             #+#    #+#             */
/*   Updated: 2024/10/29 22:21:51 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	call_init_ft(t_arg *arg, char **av, int ac)
{
	if (!init_args(arg, av, ac))
		return (1);
	if (!init_philo(arg))
		return (1);
	if (!init_mutex(arg))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_arg	arg;

	if ((ac == 5 || ac == 6) && is_digit(av))
	{
		if (!check_input(av))
			return (1);
		if (!call_init_ft(&arg, av, ac))
			return (1);
	}
}	
