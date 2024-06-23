/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cost_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:54:30 by kjung             #+#    #+#             */
/*   Updated: 2024/06/24 00:11:55 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_rank_pivot(t_stack *stack, int pivot_value)
{
	t_lst	*tmp;

	tmp = stack->head;
	while (tmp)
	{
		if (tmp->rank == pivot_value)
			return (tmp->rank);
		tmp = tmp->next;
	}
	return (-1);
}

void check_pivot(t_stack *stack)
{
	t_pivot pivot_list;
	t_stack	stack_b;

	init_stack(&stack_b);
	pivot_list.lowest_pivot = (stack->size / 4) - 1;
	pivot_list.middle_pivot = (stack->size / 4 * 2) - 1;
	pivot_list.highest_pivot = (stack->size / 4 * 3) - 1;

	pivot_list.l_rank = check_rank_pivot(stack, pivot_list.lowest_pivot);
	pivot_list.m_rank = check_rank_pivot(stack, pivot_list.middle_pivot);
	pivot_list.h_rank = check_rank_pivot(stack, pivot_list.highest_pivot);

	move_to_b_for_fivot(stack, &stack_b, pivot_list.l_rank);
	move_to_b_for_fivot(stack, &stack_b, pivot_list.m_rank);
	move_to_b_for_fivot(stack, &stack_b, pivot_list.h_rank);
	return;
}

void	move_to_b_for_fivot(t_stack *stack_a, t_stack *stack_b, int pivot_value)
{
	t_lst	*min_node;

	while ((min_node = find_min_cost(stack_a, pivot_value)) != NULL)
	{
		// 최적의 노드를 top으로 올리기 위해 rotate 또는 reverse_rotate를 수행
		while (stack_a->head != min_node)
		{
			if (min_node->index <= (stack_a->size / 2))
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_b, stack_a);
	}
	// print_stack(stack_b);
	free_list(stack_b);
}

t_lst	*find_min_cost(t_stack* stack_a, int pivot)
{
	t_lst	*tmp;
	t_lst	*min_node;
	int		min_cost;
	int		cost;

	tmp = stack_a->head;
	min_node = NULL;
	min_cost = INT_MAX;
	cost = 0;
	while (tmp) {
		if (tmp->rank <= pivot) {
			if (stack_a->size - tmp->index < tmp->index)
				cost = stack_a->size - tmp->index;
			else
				cost = tmp->index;
			if (cost < min_cost) {
				min_cost = cost;
				min_node = tmp;
			}
		}
		tmp = tmp->next;
	}
	return min_node;
}
