/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:16:16 by kjung             #+#    #+#             */
/*   Updated: 2024/07/01 18:47:29 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_input_sort(t_stack *stack_a)
{
	if (stack_a->size == 1)
		return ;
	else if (stack_a->size == 2)
	{
		if (stack_a->head->rank > stack_a->head->next->rank)
			sa(stack_a);
		else
			return ;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_plst	p_lst;

	init_stack(&stack_a);
	init_stack(&stack_b);
	init_pivot(&p_lst);
	if (!check_all(argc, argv, &stack_a))
		return (0);
	update_rank(&stack_a);
	if (stack_a.size > 3)
		a_to_b(&stack_a, &stack_b, &p_lst);
	else if (stack_a.size == 3)
		min_a_sort(&stack_a);
	else
		two_input_sort(&stack_a);
	b_to_a(&stack_a, &stack_b);
	while (stack_a.head->rank > 1)
		ra(&stack_a);
	call_stack_free(&stack_a, &stack_b);
}
