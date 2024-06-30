/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_b_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:24:46 by kjung             #+#    #+#             */
/*   Updated: 2024/06/30 21:49:57 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rc_node_go_a(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 3)
	{
		pa(stack_a, stack_b);
		return ;
	}
	if (stack_a->head->rank > stack_b->head->rank)
		go_a_util(stack_a, stack_b);
	else if (stack_a->head->rank < stack_b->head->rank)
		go_a_util2(stack_a, stack_b);
}

void	rc_node_go_head(t_stack *stack_a, t_stack *stack_b, t_lst *node)
{
	while (stack_b->head != node)
	{
		if (node->b_or_t == 't')
			rb(stack_b);
		else
			rrb(stack_b);
	}
	rc_node_go_a(stack_a, stack_b);
}

void	find_rc_node(t_stack *stack_a, t_stack *stack_b)
{
	t_lst	*tmp;
	t_lst	*min_node;
	int		min_cost;
	int		cur_cost;

	tmp = stack_b->head;
	min_node = NULL;
	min_cost = INT_MAX;
	while (tmp)
	{
		cur_cost = tmp->a_cost + tmp->b_cost;
		if (min_cost > cur_cost)
		{
			min_cost = cur_cost;
			min_node = tmp;
		}
		tmp = tmp->next;
	}
	if (min_node)
		rc_node_go_head(stack_a, stack_b, min_node);
}

void	b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->head)
	{
		cal_cost(stack_a, stack_b);
		find_rc_node(stack_a, stack_b);
	}
}
