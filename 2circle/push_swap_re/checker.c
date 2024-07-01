/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:51:53 by kjung             #+#    #+#             */
/*   Updated: 2024/07/01 20:58:51 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char *)str1;
	st2 = (unsigned char *)str2;
	while (*st1 && *st2)
	{
		if (*st1 != *st2)
			return (*st1 - *st2);
		st1++;
		st2++;
	}
	return (0);
}


void	do_op_r_rr(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(str, "ra\n") == 0)
		rotate(stack_a);
	else if (ft_strcmp(str, "rb\n") == 0)
		rotate(stack_b);
	else if (ft_strcmp(str, "rr\n") == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (ft_strcmp(str, "rra\n") == 0)
		reverse_rotate(stack_a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		reverse_rotate(stack_b);
	else if (ft_strcmp(str, "rrr\n") == 0)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
	else
	{
		ft_printf("Error\n");
		exit(1);
	}
}

void	do_op_ps(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(str, "pa\n") == 0)
		push(stack_a, stack_b);
	else if (ft_strcmp(str, "pb\n") == 0)
		push(stack_b, stack_a);
	else if (ft_strcmp(str, "sa\n") == 0)
		swap(stack_a);
	else if (ft_strcmp(str, "sb\n") == 0)
		swap(stack_b);
	else if (ft_strcmp(str, "ss\n") == 0)
	{
		swap(stack_a);
		swap(stack_b);
	}
	else
		do_op_r_rr(str, stack_a, stack_b);
}

void	input_operator(t_stack *stack_a, t_stack *stack_b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
		{
			if (check_sorted(stack_a) == 1 && stack_b->size == 0)
				ft_printf("OK\n");
			else
				ft_printf("KO\n");
			free(str);
			exit(0);
		}
		do_op_ps(str, stack_a, stack_b);
		free(str);
	}
}


int		main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_plst	p_lst;

	if (argc < 2)
		exit(1);
	init_stack(&stack_a);
	init_stack(&stack_b);
	init_pivot(&p_lst);
	if (!check_all(argc, argv, &stack_a))
		return (0);
	input_operator(&stack_a, &stack_b);
	call_stack_free(&stack_a, &stack_b);
}
