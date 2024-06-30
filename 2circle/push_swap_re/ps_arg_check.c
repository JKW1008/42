/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_arg_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:22:40 by kjung             #+#    #+#             */
/*   Updated: 2024/06/30 23:40:46 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg_char_while(char **div)
{
	int			i;
	int			j;
	long long	result;

	i = 0;
	while (div[i] != NULL)
	{
		j = 0;
		if (div[i][j] == '-')
			j++;
		while (div[i][j] != '\0')
		{
			if (!(div[i][j] >= '0' && div[i][j] <= '9'))
			{
				printf("Error\n");
				return (0);
			}
			j++;
		}
		result = ft_atol(div[i]);
		if (result < -2147483648 || result > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	check_arguments_for_char(t_stack *stack, char *argv)
{
	char			**divided;

	if (argv[0] == '\0' || argv[0] == ' ' || \
	(argv[0] == '-' && !ft_isdigit(argv[1])))
	{
		ft_printf("Error\n");
		return (0);
	}
	divided = ft_split(argv, ' ');
	if (!divided)
		return (0);
	if (!check_arg_char_while(divided))
	{
		free_split(divided);
		return (0);
	}
	parcing_list_for_char(stack, divided);
	free_split(divided);
	return (1);
}

int	check_arguments_for_digit(t_stack *stack, char **argv)
{
	long long	result;
	int			i;
	int			j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		result = ft_atol(argv[i]);
		if (result < -2147483648 || result > 2147483647)
			return (0);
		i++;
	}
	parcing_list_for_digit(stack, argv);
	return (1);
}

int	check_arg(int argc, char **argv, t_stack *stack)
{
	if (argc < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	else if (argc == 2)
	{
		if (check_arguments_for_char(stack, argv[1]) == 0)
			return (0);
	}
	else
	{
		if (check_arguments_for_digit(stack, argv) == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
	}
	return (1);
}

int	check_all(int argc, char *argv[], t_stack *stack)
{
	if (argc == 1)
		return (0);
	if (!check_arg(argc, argv, stack))
	{
		free_list(stack);
		return (0);
	}
	if (!check_list_for_duplication(stack))
	{
		ft_printf("Error\n");
		free_list(stack);
		return (0);
	}
	if (check_sorted(stack))
	{
		free_list(stack);
		return (0);
	}
	return (1);
}
