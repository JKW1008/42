/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_mutex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:08:41 by kjung             #+#    #+#             */
/*   Updated: 2024/12/09 19:49:10 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	reset_fork_mutex(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->number)
	{
		if(pthread_mutex_init(&(args->forks[i]), NULL))
		{
			cleanup_all_mutex(args, i);
			return (1);
		}
		printf("fork[%i] : %p\n", i, &(args->forks[i]));
		i++;
	}
	return (0);
}

static int	reset_print_mutex(t_args *args)
{
	if (pthread_mutex_init(&(args->print_mutex), NULL))
	{
		cleanup_all_mutex(args, args->number);
		return (1);
	}
	printf("print_mutex: %p\n", &(args->print_mutex));
	return (0);
}

static int	reset_eat_mutex(t_args *args)
{
	if (pthread_mutex_init(&(args->eat_mutex), NULL))
	{
		cleanup_all_mutex(args, args->number);
		return (1);
	}
	printf("eat_mutex: %p\n",&(args->eat_mutex));
	return (0);
}

static int	reset_dead_mutex(t_args *args)
{
	if (pthread_mutex_init(&(args->dead_mutex), NULL))
	{
		cleanup_all_mutex(args, args->number);
		return (1);
	}
	printf("dead_mutex: %p\n",&(args->dead_mutex));
	return (0);
}

int	reset_mutex(t_args *args)
{
	if (reset_fork_mutex(args))
		return (1);
	if (reset_print_mutex(args))
		return (1);
	if (reset_eat_mutex(args))
		return (1);
	if (reset_dead_mutex(args))
		return (1);
	return (0);
}