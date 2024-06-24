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

int	check_rank_pivot(t_stack *stack, int pivot_value)
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

void	check_pivot(t_stack *stack_a, t_stack *stack_b)
{
	t_pivot	p_lst;

	p_lst.lowest_pivot = stack_a->size / 3;
	// p_lst.middle_pivot = stack_a->size / 2;
	p_lst.highest_pivot = (stack_a->size / 3) * 2;
	p_lst.l_rank = check_rank_pivot(stack_a, p_lst.lowest_pivot);
	// p_lst.m_rank = check_rank_pivot(stack_a, p_lst.middle_pivot);
	p_lst.h_rank = check_rank_pivot(stack_a, p_lst.highest_pivot);
	while (stack_a->size > 3)
	{
		if (value_in_stack(0, p_lst.l_rank, stack_a))
			move_to_b_for_fivot(stack_a, stack_b, p_lst.l_rank);
		else if (value_in_stack(p_lst.l_rank, p_lst.m_rank, stack_a))
			move_to_b_for_fivot(stack_a, stack_b, p_lst.m_rank);
		else if (value_in_stack(p_lst.m_rank, p_lst.h_rank, stack_a))
			move_to_b_for_fivot(stack_a, stack_b, p_lst.h_rank);
		else if (value_in_stack(p_lst.h_rank, stack_a->input_size, stack_a))
			move_to_b_for_fivot(stack_a, stack_b, stack_a->input_size);
	}
	min_a_sort(stack_a);
	b_to_a(stack_a, stack_b, p_lst);
	return ;
}

void	move_to_b_for_fivot(t_stack *stack_a, t_stack *stack_b, int pivot_value)
{
	int		data;
	int		cost;
	t_lst	*tmp;

	cost = 0;
	data = find_min_cost(stack_a, pivot_value);
	tmp = stack_a->head;
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
			ra(stack_a);
	else
		while (cost--)
			rra(stack_a);
	pb(stack_b, stack_a);
	return ;
}

int	find_min_cost(t_stack *stack_a, int pivot)
{
	t_lst	*tmp;
	int		min_cost;
	int		cost;
	int		rank;

	tmp = stack_a->head;
	min_cost = INT_MAX;
	cost = 0;
	while (tmp)
	{
		if (tmp->rank < pivot)
		{
			if (b_or_t(tmp))
				cost = go_t(tmp);
			else
				cost = go_b(tmp);
			if (cost < min_cost)
			{
				min_cost = cost;
				rank = tmp->rank;
			}
		}
		tmp = tmp->next;
	}
	return (rank);
}
