/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:25:39 by kjung             #+#    #+#             */
/*   Updated: 2024/12/10 16:59:36 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	main(int ac, char **av)
{
	t_args	args;

	if (ac == 5 || ac == 6)
	{
		if (check_args(ac, av))
		{
			printf("Error: Invalid argument value must be a positive number\n");
			return (1);
		}
		if (init(ac, av, &args))
		{
			printf("Error: init faild\n");
			return (1);
		}
		if (ft_create_philo(&args))
		{
			cleanup_thread(&args);
			cleanup_all_mutex(&args, args.number);
			return (1);
		}
		cleanup_thread(&args);
		cleanup_all_mutex(&args, args.number);
	}
	return (0);
}
