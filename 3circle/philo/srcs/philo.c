/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 22:12:09 by kjung             #+#    #+#             */
/*   Updated: 2024/10/25 19:25:26 by kjung            ###   ########.fr       */
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

void    ft_pass_time(long long wait_time, t_arg *arg)
{
    long long    start;
    long long    now;

    start = get_time();
    while (1)
    {
        pthread_mutex_lock(&arg->finish_mutex);
        if (arg->finish)
        {
            pthread_mutex_unlock(&arg->finish_mutex);
            break;
        }
        pthread_mutex_unlock(&arg->finish_mutex);
        
        now = get_time();
        if ((now - start) >= wait_time)
            break;
        usleep(100);
    }
}

int    ft_philo_print(t_arg *arg, int id, char *msg)
{
    long long    now;

    pthread_mutex_lock(&arg->finish_mutex);
    if (arg->finish)
    {
        pthread_mutex_unlock(&arg->finish_mutex);
        return (1);
    }
    pthread_mutex_unlock(&arg->finish_mutex);

    now = get_time();
    pthread_mutex_lock(&arg->print);
    printf("%lld %d %s\n", now - arg->start_time, id + 1, msg);
    pthread_mutex_unlock(&arg->print);
    return (0);
}


int    ft_philo_action(t_arg *arg, t_philo *philo)
{
    pthread_mutex_lock(&(arg->forks[philo->left]));
    ft_philo_print(arg, philo->id, "has taken a fork");
    if (arg->number == 1)
    {
        ft_pass_time(arg->time_to_die, arg);
        pthread_mutex_unlock(&(arg->forks[philo->left]));
        return (1);
    }
    pthread_mutex_lock(&(arg->forks[philo->right]));
    ft_philo_print(arg, philo->id, "has taken a fork");
    ft_philo_print(arg, philo->id, "is eating");
    
    pthread_mutex_lock(&arg->eat_mutex);
    philo->last_eat_time = get_time();
    philo->eat_cnt++;
    pthread_mutex_unlock(&arg->eat_mutex);
    
    ft_pass_time(arg->time_to_eat, arg);
    pthread_mutex_unlock(&(arg->forks[philo->right]));
    pthread_mutex_unlock(&(arg->forks[philo->left]));
    return (0);
}

void    *ft_thread(void *argv)
{
    t_philo    *philo;
    t_arg      *arg;

    philo = (t_philo *)argv;
    arg = philo->arg;
    if (philo->id % 2)
        usleep(1000);
    
    while (1)
    {
        pthread_mutex_lock(&arg->finish_mutex);
        if (arg->finish)
        {
            pthread_mutex_unlock(&arg->finish_mutex);
            break;
        }
        pthread_mutex_unlock(&arg->finish_mutex);

        if (ft_philo_action(arg, philo))
            break;
            
        pthread_mutex_lock(&arg->eat_mutex);
        if (arg->eat_cnt > 0 && philo->eat_cnt >= arg->eat_cnt)
        {
            arg->finish_eat++;
            pthread_mutex_unlock(&arg->eat_mutex);
            break;
        }
        pthread_mutex_unlock(&arg->eat_mutex);

        ft_philo_print(arg, philo->id, "is sleeping");
        ft_pass_time(arg->time_to_sleep, arg);
        ft_philo_print(arg, philo->id, "is thinking");
    }
    return (NULL);
}

void    ft_check_death(t_arg *arg, t_philo *philo)
{
    int         i;
    long long   now;

    while (1)
    {
        i = -1;
        while (++i < arg->number)
        {
            pthread_mutex_lock(&arg->eat_mutex);
            now = get_time();
            if ((now - philo[i].last_eat_time) >= arg->time_to_die)
            {
                pthread_mutex_lock(&arg->finish_mutex);
                arg->finish = 1;
                pthread_mutex_unlock(&arg->finish_mutex);
                pthread_mutex_lock(&arg->print);
                printf("%lld %d died\n", now - arg->start_time, i + 1);
                pthread_mutex_unlock(&arg->print);
                pthread_mutex_unlock(&arg->eat_mutex);
                return;
            }
            if (arg->eat_cnt > 0 && arg->finish_eat >= arg->number)
            {
                pthread_mutex_lock(&arg->finish_mutex);
                arg->finish = 1;
                pthread_mutex_unlock(&arg->finish_mutex);
                pthread_mutex_unlock(&arg->eat_mutex);
                return;
            }
            pthread_mutex_unlock(&arg->eat_mutex);
        }
        usleep(100);
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