/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:12:00 by kjung             #+#    #+#             */
/*   Updated: 2024/10/18 01:53:10 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILO_H
# define PHILO_H

# include <stdio.h>
# include <memory.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_arg
{
	int	number;
	unsigned int	life_time;
	unsigned int	eat_time;
	unsigned int	sleep_time;
	unsigned int	eat_cnt;
	long long		start_time;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				finish;
	int				finish_eat;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
}	t_arg;

typedef struct s_philo
{
	t_arg			*arg;
	unsigned int	id;
	unsigned int	left;
	unsigned int	right;
	unsigned int	last_eat_time;
	unsigned int	eat_cnt;
	pthread_t		thread;
}	t_philo;


//	utils
void	init_arg(t_arg *arg, char **av, int ac);
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
