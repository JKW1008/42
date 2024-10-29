/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_struct_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:15:02 by kjung             #+#    #+#             */
/*   Updated: 2024/10/25 19:28:09 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

long long    get_time(void)
{
    struct timeval    tv;
    
    if (gettimeofday(&tv, NULL) == -1)
        return (-1);
    return ((long long)tv.tv_sec * 1000 + tv.tv_usec / 1000);
}


int		arg_mutex(t_arg *arg)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&(arg->print), NULL) != 0)
		return (1);
	arg->forks = malloc(sizeof(pthread_mutex_t) * arg->number);
	if (!(arg->forks))
		return (1);
	while (i < arg->number)
	{
		if (pthread_mutex_init(&(arg->forks[i]), NULL))
			return (1);
		i++;
	}
	return (0);
}

int    init_arg(t_arg *arg, char **av, int ac)
{
    int     i;

    i = 1;
    while (av[i])
    {
        printf("av[%d] = %s after atoi %d\n", i, av[i], ft_atoi(av[i]));
        i++;
    }
    arg->number = ft_atoi(av[1]);
    arg->time_to_die = ft_atoi(av[2]);
    arg->time_to_eat = ft_atoi(av[3]);
    arg->time_to_sleep = ft_atoi(av[4]);
    if (arg->number <= 0 || arg->time_to_die < 0 || 
        arg->time_to_eat < 0 || arg->time_to_sleep < 0)
        return (1);
    if (ac == 5)
        arg->eat_cnt = 0;
    else
    {
        arg->eat_cnt = ft_atoi(av[5]);
        if (arg->eat_cnt < 0)
            return (1);
    }
    arg->start_time = get_time();
    arg->finish = 0;
    arg->finish_eat = 0;
    if (pthread_mutex_init(&(arg->print), NULL))
        return (1);
    if (pthread_mutex_init(&(arg->finish_mutex), NULL))
    {
        pthread_mutex_destroy(&(arg->print));
        return (1);
    }
    if (pthread_mutex_init(&(arg->eat_mutex), NULL))
    {
        pthread_mutex_destroy(&(arg->print));
        pthread_mutex_destroy(&(arg->finish_mutex));
        return (1);
    }
    if (arg_mutex(arg))
    {
        pthread_mutex_destroy(&(arg->print));
        pthread_mutex_destroy(&(arg->finish_mutex));
        pthread_mutex_destroy(&(arg->eat_mutex));
        return (1);
    }
    return (0);  // 성공 시 0 반환
}

void	init_philo(t_philo **philo, t_arg *arg)
{
	int	i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * arg->number);
	if (!(philo))
		return ;
	while (i < arg->number)
	{
		(*philo)[i].arg = arg;
		(*philo)[i].id = i;
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % arg->number;
		(*philo)[i].last_eat_time = get_time();
		(*philo)[i].eat_cnt = 0;
		i++;
	}
}

