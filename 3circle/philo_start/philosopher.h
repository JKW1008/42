/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:49:42 by kjung             #+#    #+#             */
/*   Updated: 2024/12/04 18:42:05 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHIOSOPHER_H
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
	int				is_dead;
	struct s_philo	*philo;
} t_args;

typedef	struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long long		last_eat_time;
	int				eat_count;
	t_args			*args;
} t_philo;


int	ft_atoi(const char *str);
int	init(int ac, char **av, t_args *args);

#endif