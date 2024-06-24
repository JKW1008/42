/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cost_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:54:30 by kjung             #+#    #+#             */
/*   Updated: 2024/06/24 21:57:00 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_a_sort(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->head->rank;
	second = stack_a->head->next->rank;
	third = stack_a->head->next->next->rank;
	if (first < second && third < second && first < third)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (second < first && first < third) 
		sa(stack_a);
	else if (first < second && second > third && first > third)
		rra(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (second < third && first > third && first > second)
		ra(stack_a);
}

void	move_b_a_be_min(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 3)
		pb(stack_b, stack_a);
	min_a_sort(stack_a);
}

void	move_b(t_stack *stack_a, t_stack *stack_b)
{
	t_pivot	p_lst;
	int 	i;
	t_lst	*current;

	i = stack_a->size;
	p_lst.lowest_pivot = stack_a->size / 3;
	p_lst.highest_pivot = (stack_a->size / 3) * 2;
	current = stack_a->head;
	while (i != 0 && current)
	{
		if (current->rank < p_lst.lowest_pivot)
		{
			pb(stack_b, stack_a);
			rb(stack_b);
		}
		else if (current->rank >= p_lst.lowest_pivot && current->rank < p_lst.highest_pivot)
			pb(stack_b, stack_a);
		else if (current->rank >= p_lst.highest_pivot)
			ra(stack_a);
		current = stack_a->head;
		i--;
	}
	move_b_a_be_min(stack_a, stack_b);
    return ;
}

