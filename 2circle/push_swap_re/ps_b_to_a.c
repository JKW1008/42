/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_b_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:24:46 by kjung             #+#    #+#             */
/*   Updated: 2024/06/29 22:47:03 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rc_node_go_a(t_stack *stack_a, t_stack *stack_b)
{
	int	move_cnt;

	move_cnt = stack_b->head->a_cost;
	if (stack_a->size == 3)
	{
		pa(stack_a, stack_b);
		return ;
	}
	if (stack_a->head->rank > stack_b->head->rank)
	{
		if (stack_a->tail->rank > stack_b->head->rank)
		{
			if (stack_a->head->rank > stack_a->tail->rank)
			{
				while (stack_a->tail->rank > stack_b->head->rank)
					rra(stack_a);
				pa(stack_a, stack_b);
			}
			if (stack_a->head->rank < stack_a->tail->rank)
				pa(stack_a, stack_b);
		}
		else if (stack_a->tail->rank < stack_b->head->rank)
			pa(stack_a, stack_b);
	}
	else if (stack_a->head->rank < stack_b->head->rank)
	{
		if (stack_a->tail->rank > stack_b->head->rank)
		{
			while (stack_a->head->rank < stack_b->head->rank)
				ra(stack_a);
			pa(stack_a, stack_b);
		}
		else if (stack_a->tail->rank < stack_b->head->rank)
		{
			if (stack_a->tail->rank > stack_a->head->rank)
			{
				pa(stack_a, stack_b);
				ra(stack_a);
			}
			else if (stack_a->tail->rank < stack_a->head->rank)
			{
				while (stack_a->head->rank < stack_b->head->rank)
					ra(stack_a);
				pa(stack_a, stack_b);
			}
		}
	}
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