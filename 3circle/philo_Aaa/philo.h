/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:41:57 by kjung             #+#    #+#             */
/*   Updated: 2024/11/04 18:53:18 by kjung            ###   ########.fr       */
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
int	ft_atoi(char *s);
int	ft_isdigit(char c);

//	check.c
int	check_input(char **av);

//	get_time.c
int	get_time(void);

//	free.c
int	free_arg(t_arg *arg);

//	init.c
int		init_args(t_arg *arg, char **av, int ac);
int		init_mutex(t_arg *arg);
int		init_philo(t_arg *arg);

//	print.c
void	ft_putchar(char c, int fd);
void	ft_putstr(char *str, int fd);
void	ft_putnbr(int n, int fd);
int		print_error(char *str);

#endif
