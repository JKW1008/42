/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:26:01 by kjung             #+#    #+#             */
/*   Updated: 2024/10/29 23:26:54 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <memory.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	int				cnt_eat;
	int				last_eat;
	int				l_fork;
	int				r_fork;
	pthread_t		thread;
	struct s_arg	*arg;
}	t_philo;

typedef struct s_arg
{
	int				philo_number;
	int				time_to_die;
	int				eat_time;
	int				sleep_time;
	int				nof_eat;
	int				cnt_group_eat;
	int				time_stamp;
	int				chk_finish;
	t_philo			*philo;
	pthread_mutex_t	print;
	pthread_mutex_t	*fork;
	pthread_mutex_t	finish_mutex;
	pthread_mutex_t	eat_mutex;
}	t_arg;

//	char_utils.c
void	ft_putstr(char *str, int fd);
void	ft_putchar(char c, int fd);
void	ft_putnbr(int n, int fd);

//	check_args.c
int		ft_atoi(char *str);
int		is_digit(char **av);
int		check_input(char **av);

//	error.c
int		print_error(char *str);
void	print_status(t_philo *philo, char *str);

//	init.c
int		init_args(t_arg *arg, char **av, int ac);
int		init_philo(t_arg *arg);
int		init_mutex(t_arg *arg);

//	philo_utils.c
int		get_time(void);
int		chk_done(t_philo *philo, int status);

#endif