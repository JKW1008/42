/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:00:25 by kjung             #+#    #+#             */
/*   Updated: 2024/06/19 14:50:42 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(t_lst *head)
{
	t_lst	*tmp;
	t_lst	*tmp2;

	tmp = head;
	while (tmp != NULL)
	{
		printf("index = %d\n", tmp->index);
		printf("data = %d\n", tmp->data);
		tmp = tmp->next;
	}
	tmp = head;
	while (tmp != NULL)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free (tmp2);
	}
}

void	print_stack(t_stack *stack)
{
	printf("head index = %d, tail index = %d\n", stack->head->index, stack->tail->index);
	printf("head data = %d, tail data = %d\n", stack->head->data, stack->tail->data);

	t_lst	*tmp;
	t_lst	*tmp2;
	tmp = stack->head;
	while (tmp != NULL)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free (tmp2);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	int		return_value;

	init_stack(&stack_a);
	return_value = check_arg(argc, argv, &stack_a);
	if (!return_value)
		return (0);
	print_stack(&stack_a);
}
