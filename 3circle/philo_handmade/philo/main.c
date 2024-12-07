/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:12:22 by kjung             #+#    #+#             */
/*   Updated: 2024/11/04 17:30:25 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	call_init_ft(t_arg *arg, char **av, int ac)
{
	if (!init_args(arg, av, ac))
		return (0);
	if (!init_philo(arg))
		return (0);
	if (!init_mutex(arg))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_arg	arg;

	if (ac == 5 || ac == 6)
	{
		if (!check_input(av))
			return (1);
		if (!call_init_ft(&arg, av, ac))
			return (1);
		if (create_philo(&arg))
			return (1);
		call_chk(&arg);
	}
	else
		print_error("Input Error : must input arumetns 5 or 6");
}	
