/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:25:42 by kjung             #+#    #+#             */
/*   Updated: 2024/06/24 17:06:26 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arguments_for_char(t_stack *stack, char *argv)
{
	long long		result;
	char			**divided;
	int				i;
	int				j;

	if (argv[0] == '\0' || argv[0] == ' ')
		return (0);
	divided = ft_split(argv, ' ');
	if (!divided)
		return (0);
	i = 0;
	while (divided[i] != NULL)
	{
		j = 0;
		while (divided[i][j] != '\0')
		{
			if (!(divided[i][j] >= '0' && divided[i][j] <= '9'))
			{
				free_split(divided);
				return (0);
			}
			j++;
		}
		result = ft_atol(divided[i]);
		if (result < INT_MIN || result > INT_MAX)
			return (0);
		i++;
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
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		result = ft_atol(argv[i]);
		if (result < INT_MIN || result > INT_MAX)
			return (0);
		i++;
	}
	parcing_list_for_digit(stack, argv);
	return (1);
}

int	check_list_for_duplication(t_stack *stack)
{
	t_lst	*cur;
	t_lst	*dup;

	cur = stack->head;
	while (cur != NULL)
	{
		dup = cur->next;
		while (dup != NULL)
		{
			if (cur->data == dup->data)
				return (0);
			dup = dup->next;
		}
		cur = cur->next;
	}
	return (1);
}

int	check_sorted(t_stack *stack)
{
	t_lst	*cur;
	t_lst	*next;

	cur = stack->head;
	while (cur != NULL)
	{
		next = cur->next;
		while (next != NULL)
		{
			if (cur->data > next->data)
				return (0);
			next = next->next;
		}
		cur = cur->next;
	}
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
		{
			ft_printf("Error\n");
			return (0);
		}
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
