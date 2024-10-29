/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:12:00 by kjung             #+#    #+#             */
/*   Updated: 2024/10/25 19:27:54 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>

typedef struct s_arg
{
    int             number;
    long long       time_to_die;
    long long       time_to_eat;
    long long       time_to_sleep;
    long long       eat_cnt;
    long long       start_time;
    int             finish;
    int             finish_eat;
    pthread_mutex_t print;
    pthread_mutex_t *forks;
    pthread_mutex_t finish_mutex;
    pthread_mutex_t eat_mutex;
}   t_arg;


typedef struct s_philo
{
    t_arg       *arg;
    int         id;
    int         left;
    int         right;
    long long   last_eat_time;
    long long   eat_cnt;
    pthread_t   thread;
}   t_philo;

//	utils
int    init_arg(t_arg *arg, char **av, int ac);
void	init_philo(t_philo **philo, t_arg *arg);
int		philo_start(t_arg *arg, t_philo *philo);

//		ph_atoi.c
int		ft_atoi(char *str);

//		ph_char_utilis.c
int		is_digit(char **av);

//		ph_struct_utils.c
void	init_arg(t_arg *philo, char **av, int ac);

long long	get_time(void);

#endif
