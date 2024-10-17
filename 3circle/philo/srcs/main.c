/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:04:15 by kjung             #+#    #+#             */
/*   Updated: 2024/10/18 01:48:40 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// void	print_struct(t_philo *philo)
// {
// 	printf("number is = %d\n", philo->number);
// 	printf("life_time is = %d\n", philo->life_time);
// 	printf("eat_time is = %d\n", philo->eat_time);
// 	printf("sleep_time is = %d\n", philo->sleep_time);
// 	printf("eat_cnt is = %d\n", philo->eat_cnt);
// }



int	main(int ac, char **av)
{
	t_arg	arg;
	t_philo	*philo;

	if ((ac != 5 && ac != 6) || !is_digit(av))
		return (0);
	memset(&arg, 0, sizeof(t_arg));
	init_arg(&arg, av, ac);
	init_philo(&philo, &arg);
	philo_start(&arg, philo);
}