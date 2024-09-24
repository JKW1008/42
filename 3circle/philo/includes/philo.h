/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:12:00 by kjung             #+#    #+#             */
/*   Updated: 2024/09/24 22:50:35 by kjung            ###   ########.fr       */
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
	unsigned int	number;
	unsigned int	life_time;
	unsigned int	eat_time;
	unsigned int	sleep_time;
	unsigned int	eat_cnt;
	unsigned int	start_time;
}	t_arg;

typedef struct s_philo
{
	t_arg			arg;
	unsigned int	id;
	unsigned int	left;
	unsigned int	right;
	unsigned int	last_eat_time;
	unsigned int	eat_cnt;
}	t_philo;


//	utils
//		ph_atoi.c
int		ft_atoi(char *str);

//		ph_char_utilis.c
int		is_digit(char **av);

//		ph_struct_utils.c
void	init_arg(t_arg *philo, char **av, int ac);

#endif
