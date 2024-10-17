/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 22:12:09 by kjung             #+#    #+#             */
/*   Updated: 2024/10/18 01:53:26 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void ft_free_thread(t_arg *arg, t_philo *philo)
{
    int i;

	i = 0;
    pthread_mutex_destroy(&(arg->print));
    while (i < arg->number)
        pthread_mutex_destroy(&(arg->forks[i++]));
    if (arg->forks)
    {
        free(arg->forks);
        arg->forks = NULL;
    }
    if (philo)
    {
        free(philo);
        philo = NULL;
    }
}

void	ft_pass_time(long long wait_time, t_arg *arg)
{
	long long	start;
	long long	now;

	start = get_time();
	while (!(arg->finish))
	{
		now = get_time();
		if ((now - start) >= wait_time)
			break ;
		usleep(10);
	}
}

int	ft_philo_print(t_arg *arg, int id, char *msg)
{
	long long	now;

	now = get_time();
	if (now == -1)
		return (-1);
	pthread_mutex_lock(&(arg->print));
	if (!(arg->finish))
		printf("%lld %d %s \n", now - arg->start_time, id + 1, msg);
	pthread_mutex_unlock(&(arg->print));
	return (0);
}

int	ft_philo_action(t_arg *arg, t_philo *philo)
{
	pthread_mutex_lock(&(arg->forks[philo->left]));
	ft_philo_print(arg, philo->id, "has taken a fork");
	if (arg->number != 1)
	{
		pthread_mutex_lock(&(arg->forks[philo->right]));
		ft_philo_print(arg, philo->id, "has taken a fork");
		ft_philo_print(arg, philo->id, "is eating");
		philo->last_eat_time = get_time();
		philo->eat_cnt = philo->eat_cnt + 1;
		ft_pass_time((long long)arg->time_to_eat, arg);
		pthread_mutex_unlock(&(arg->forks[philo->right]));
	}
	pthread_mutex_unlock(&(arg->forks[philo->left]));
	return (0);
}

int	ft_thread(void *argv)
{
	t_arg	*arg;
	t_philo	*philo;

	philo = argv;
	arg = philo->arg;
	if (philo->id % 2)
		usleep(1000);
	while (!arg->finish)
	{
		ft_philo_action(arg, philo);
		if (arg->eat_time == philo->eat_cnt)
		{
			arg->finish_eat++;
			break ;
		}
		ft_philo_print(arg, philo->id, "is sleeping");
		ft_pass_time((long long)arg->time_to_sleep, arg);
		ft_philo_print(arg, philo->id, "is thinking");
	}
	return (0);
}

void	ft_philo_check_finish(t_arg *arg, t_philo *philo)
{
	int			i;
	long long	now;

	while (!arg->finish)
	{
		if ((arg->eat_time != 0) && (arg->number == arg->finish_eat))
		{
			arg->finish = 1;
			break ;
		}
		i = 0;
		while (i < arg->number)
		{
			now = get_time();
			if ((now - philo[i].last_eat_time) >= arg->time_to_die)
			{
				ft_philo_print(arg, i, "died");
				arg->finish = 1;
				break ;
			}
			i++;
		}
	}
}

int	philo_start(t_arg *arg, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < arg->number)
	{
		philo[i].last_eat_time = get_time();
		if (pthread_create(&(philo[i].thread), NULL, (void *)ft_thread, &(philo[i])))
			return (1);
		i++;
	}
	ft_philo_check_finish(arg, philo);
	i = 0;
	while (i < arg->number)
		pthread_join(philo[i++].thread, NULL);
	ft_free_thread(arg, philo);
	return (0);
}