/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:49:42 by kjung             #+#    #+#             */
/*   Updated: 2024/12/17 11:57:45 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_args
{
	int				number;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_cnt;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	dead_mutex;
	int				is_dead;
	struct s_philo	*philo;
	long long		start_time;
	pthread_t		monitor;
}	t_args;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	time_mutex;
	long long		last_eat_time;
	int				eat_count;
	t_args			*args;
}	t_philo;

int			ft_atoi(const char *str);
int			init(int ac, char **av, t_args *args);
long long	ft_gettime(void);
void		ft_print_status(t_philo *philo, char *message);
int			take_forks(t_philo *philo);
int			reset_mutex(t_args *args);
void		cleanup_all_mutex(t_args *args, int philo_count);
int			eating(t_philo *philo);
int			sleeping(t_philo *philo);
void		*philo_routine(void *arg);
void		*monitor_routine(void *arg);
int			cleanup_thread(t_args *args);
int			ft_create_philo(t_args *args);
void		ft_usleep(int time, t_philo *philo);
int			check_args(int ac, char **av);
int			eating_die(t_philo *philo);
#endif