/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cost_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:54:30 by kjung             #+#    #+#             */
/*   Updated: 2024/06/23 20:23:20 by kjung            ###   ########.fr       */
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

	pivot_list.lowest_pivot = (stack->size / 4) - 1;
	pivot_list.middle_pivot = (stack->size / 4 * 2) - 1;
	pivot_list.highest_pivot = (stack->size / 4 * 3) - 1;

	pivot_list.l_rank = check_rank_pivot(stack, pivot_list.lowest_pivot);
	pivot_list.m_rank = check_rank_pivot(stack, pivot_list.middle_pivot);
	pivot_list.h_rank = check_rank_pivot(stack, pivot_list.highest_pivot);
	
	find_min_cost(stack, pivot_list.lowest_pivot);
	printf("size = %d\n", stack->size);
	return;
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
				printf("min_node->index = %d\n", min_node->index);
				printf("min_node->data = %d\n", min_node->data);
				printf("min_node->rank = %d\n", min_node->rank);
				printf("min_cost = %d\n", min_cost);
			}
		}
		tmp = tmp->next;
	}
	printf("min_cost = %d\n", min_cost);
	return min_node;
}
