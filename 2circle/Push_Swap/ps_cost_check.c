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

	printf("lowest_pivot = %d\n", pivot_list.lowest_pivot);
	printf("middle_pivot = %d\n", pivot_list.middle_pivot);
	printf("highest_pivot = %d\n", pivot_list.highest_pivot);

	printf("l_rank = %d\n", pivot_list.l_rank);
	printf("m_rank = %d\n", pivot_list.m_rank);
	printf("h_rank = %d\n", pivot_list.h_rank);

	return;
}