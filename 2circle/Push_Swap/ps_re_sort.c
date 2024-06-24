/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_re_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:28:17 by kjung             #+#    #+#             */
/*   Updated: 2024/06/24 21:56:11 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_to_a(t_stack *stack_a, t_stack *stack_b, t_pivot p_lst)
{
	while (stack_b->size)
	{
		if (value_in_stack(p_lst.h_rank, stack_a->input_size, stack_b))
			move_to_a_for_fivot(stack_b, stack_a, stack_a->input_size);
		else if (value_in_stack(p_lst.m_rank, p_lst.h_rank, stack_b))
			move_to_a_for_fivot(stack_b, stack_a, p_lst.h_rank);
		else if (value_in_stack(p_lst.l_rank, p_lst.m_rank, stack_b))
			move_to_a_for_fivot(stack_b, stack_a, p_lst.m_rank);
		else if (value_in_stack(0, p_lst.l_rank, stack_b))
			move_to_a_for_fivot(stack_b, stack_a, p_lst.l_rank);
	}
}

void	move_to_a_for_fivot(t_stack *stack_b, t_stack *stack_a, int pivot_value)
{
	int		data;
	int		cost;
	t_lst	*tmp;

	cost = 0;
	data = find_min_cost(stack_b, pivot_value);
	tmp = stack_b->head;
	while (tmp)
	{
		if (tmp->rank == data)
			break ;
		tmp = tmp->next;
	}
	if (b_or_t(tmp))
		cost = go_t(tmp);
	else
		cost = go_b(tmp);
	if (b_or_t(tmp))
		while (cost--)
			rb(stack_b);
	else
		while (cost--)
			rrb(stack_b);
	pa(stack_a, stack_b);
	return ;
}

