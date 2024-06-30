/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cal_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:11:32 by kjung             #+#    #+#             */
/*   Updated: 2024/06/30 21:36:33 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	input_b_cost(t_lst *node, int t_count, int b_count)
{
	if (t_count <= b_count)
	{
		node->b_cost = t_count;
		node->b_or_t = 't';
	}
	else
	{
		node->b_cost = b_count;
		node->b_or_t = 'b';
	}
}

void	cal_b_cost(t_lst *node)
{
	t_lst	*tmp;
	int		t_count;
	int		b_count;

	tmp = node;
	t_count = 0;
	b_count = 0;
	while (tmp->prev)
	{
		t_count++;
		tmp = tmp->prev;
	}
	tmp = node;
	while (tmp->next)
	{
		b_count++;
		tmp = tmp->next;
	}
	input_b_cost(node, t_count, b_count);
}

void	cal_a_cost(t_lst *node, t_stack *stack_a)
{
	t_lst	*tmp;
	int		i;

	if (node == NULL || stack_a == NULL)
		return ;
	tmp = stack_a->head;
	i = 0;
	while (tmp)
	{
		if (node->rank > tmp->rank)
		{
			i++;
			tmp = tmp->next;
		}
		else
			break ;
	}
	node->a_cost = i;
}

void	cal_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_lst	*tmp;

	tmp = stack_b->head;
	while (tmp)
	{
		cal_b_cost(tmp);
		cal_a_cost(tmp, stack_a);
		tmp = tmp->next;
	}
}
