/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:20:20 by kjung             #+#    #+#             */
/*   Updated: 2024/06/28 18:04:16 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cal_input_size(t_stack *stack)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = stack->head;
	stack->input_size = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	stack->input_size = i;
}

void	init_in_stack_move(t_stack *stack_b, t_stack *stack_a)
{
	t_lst	*tmp;

	tmp = stack_b->head;
	while (tmp)
	{
		top_or_bottom(tmp);
		move_a_cost(tmp, stack_a);
		tmp = tmp->next;
	}
}

void	sort_push_for_a(t_stack *stack_a, t_stack *stack_b, t_pivot *pivot)
{
	real_sort_for_a(stack_a, stack_b, pivot->highest_pivot);
	real_sort_for_a(stack_a, stack_b, pivot->lowest_pivot);
	real_sort_for_a(stack_a, stack_b, 0);
}

t_lst	*find_row_cost_node(t_stack *stack_b, int pivot)
{
	int		min_cost = INT_MAX;
	int		cost;
	t_lst	*tmp;
	t_lst	*min_node;

	tmp = stack_b->head;
	min_node = NULL;
	while (tmp && tmp->rank >= pivot)
	{
		cost = tmp->a_cost + tmp->b_cost;
		if (min_cost > cost)
		{
			min_cost = cost;
			min_node = tmp;
		}
		tmp = tmp->next;
	}
	return (min_node);
}

int	min_node_go_head(t_stack *stack_b, t_stack *stack_a, t_lst *min_node, t_recovery *rc_cost)
{
	int	move_cost;
	if (min_node->b_or_t == 'b')
	{	
		move_cost = min_node->a_cost;
		while (stack_b->head != min_node)
		{
			rrb(stack_b);
			rc_cost->rrb_cost++;
		}
		while (move_cost--)
		{
			ra(stack_a);
			rc_cost->ra_cost++;
		}
		return (-1);
	}
	else if (min_node->b_or_t == 't' && min_node->a_cost >= min_node->b_cost)
	{
		move_cost = min_node->a_cost - min_node->b_cost;
		while (min_node != stack_b->head)
		{
			rr(stack_a, stack_b);
			rc_cost->rr_cost++;
		}
		while (move_cost--)
		{
			ra(stack_a);
			rc_cost->ra_cost++;
		}
		return (0);
	}
	else if (min_node->b_or_t == 't' && min_node->a_cost < min_node->b_cost)
	{
		move_cost = min_node->a_cost;
		while (move_cost--)
		{
			rr(stack_a, stack_b);
			rc_cost->rr_cost++;
		}
		while (min_node != stack_b->head)
		{
			rb(stack_b);
			rc_cost->rb_cost++;
		}
		return (1);
	}
	return (2);
}

void	recovery_stack(t_stack *stack_a, t_stack *stack_b, int checker, t_recovery *rc_cost)
{
	int i;
	if (checker == -1)
	{
		i = rc_cost->rrb_cost;
		while (i--)
			rb(stack_b);
		i = rc_cost->ra_cost;
		while (i--)
			rra(stack_a);
	}
	else if (checker == 0)
	{
		i = rc_cost->rr_cost;
		while (i--)
			rrr(stack_a, stack_b);
		i = rc_cost->ra_cost;
		while (i--)
			rra(stack_a);
	}
	else if (checker == 1)
	{
		i = rc_cost->rr_cost;
		while (i--)
			rrr(stack_a, stack_b);
		i = rc_cost->rb_cost;
		while (i--)
			rrb(stack_b);
	}
}

void	stack_a_smallnode(t_lst *min_node, t_stack *stack_a)
{
	t_lst	*tmp;
	int		i;
	int		size;

	i = 0;
	tmp = stack_a->head;
	size = stack_a->size;
	while (tmp && tmp != min_node)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < size / 2)
		while (min_node != stack_a->head)
			rra(stack_a);
	else
		while (min_node != stack_a->head)
			ra(stack_a);
}

void	real_sort_for_a(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	t_lst	*min_node;
	int		check_move;
	t_recovery	rc_cost;

	min_node = NULL;
	check_move = 0;
	while (stack_b->head && stack_b->head->rank >= pivot)
	{
		rc_cost.ra_cost = 0;
		rc_cost.rb_cost = 0;
		rc_cost.rr_cost = 0;
		rc_cost.rra_cost = 0;
		rc_cost.rrb_cost = 0;
		init_in_stack_move(stack_b, stack_a);
		min_node = find_row_cost_node(stack_b, pivot);
		check_move = min_node_go_head(stack_b, stack_a, min_node, &rc_cost);
		pa(stack_a, stack_b);
		min_node = find_row_cost_node(stack_a, 0);
		recovery_stack(stack_a, stack_b, check_move, &rc_cost);
		// stack_a_smallnode(min_node, stack_a);
	}
}

