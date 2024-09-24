/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_struct_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:15:02 by kjung             #+#    #+#             */
/*   Updated: 2024/09/24 22:52:56 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	init_arg(t_arg *arg, char **av, int ac)
{
	int	i = 1;

	while (av[i])
	{
		printf("av[%d] = %s after atoi %d\n", i, av[i], ft_atoi(av[i]));
		i++;
	}
	arg->number = ft_atoi(av[1]);
	arg->life_time = ft_atoi(av[2]);
	arg->eat_time = ft_atoi(av[3]);
	arg->sleep_time = ft_atoi(av[4]);
	if (ac == 5)
		arg->eat_cnt = 0;
	else
		arg->eat_cnt = ft_atoi(av[5]);
	arg->start_time = get_time();
}

void	init_philo(t_philo **philo, t_arg *arg)
{
	
}

