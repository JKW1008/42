/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:04:15 by kjung             #+#    #+#             */
/*   Updated: 2024/10/25 19:29:02 by kjung            ###   ########.fr       */
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

void    ft_free_all(t_arg *arg, t_philo *philo)
{
    int    i;

    i = 0;
    while (i < arg->number)
    {
        pthread_mutex_destroy(&(arg->forks[i]));
        i++;
    }
    pthread_mutex_destroy(&arg->print);
    pthread_mutex_destroy(&arg->finish_mutex);
    pthread_mutex_destroy(&arg->eat_mutex);
    free(arg->forks);
    free(philo);
}

int    main(int ac, char **av)
{
    t_arg    arg;
    t_philo    *philo;

    if ((ac != 5 && ac != 6) || !is_digit(av))
        return (1);
    memset(&arg, 0, sizeof(t_arg));
	if (init_arg(&arg, av, ac))
	{
		
	}
    if (init_philo(&philo, &arg))
    {
        ft_free_all(&arg, NULL);
        return (1);
    }
    if (start_simulation(&arg, philo))
    {
        ft_free_all(&arg, philo);
        return (1);
    }
    ft_free_all(&arg, philo);
    return (0);
}