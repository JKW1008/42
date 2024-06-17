/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:25:42 by kjung             #+#    #+#             */
/*   Updated: 2024/06/17 18:59:36 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arguments_for_char(t_lst **a_list, char *argv)
{
	long long		result;
	char			**divided;
	int				i;
	int				j;

	divided = ft_split(argv, ' ');
	i = 0;
	while (divided[i] != NULL)
	{
		j = 0;
		while (divided[i][j] != '\0')
		{
			if (!(divided[i][j] > '0' && divided[i][j] < '9'))
				return (0);
			j++;
		}
		result = ft_atol(divided[i]);
		if (result < INT_MIN || result > INT_MAX)
			return (0);
		i++;
	}
	parcing_list_for_char(a_list, divided);
	free_split(divided);
	return (1);
}

int	check_arguments_for_digit(char **argv)
{
	long long	result;
	int			i;
	int			j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		result = ft_atol(argv[i]);
		if (result < INT_MIN || result > INT_MAX)
			return (0);
		printf("conversion divided = %lld\n", result);
		i++;
	}
	return (1);
}

int	check_arg(int argc, char **argv, t_lst **list_a)
{
	if (argc < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	else if (argc == 2)
	{
		if (check_arguments_for_char(list_a, argv[1]) == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
	}
	else
	{
		if (check_arguments_for_digit(argv) == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
	}
	return (1);
}
