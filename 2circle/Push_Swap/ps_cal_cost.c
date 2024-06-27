/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cal_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:07:50 by kjung             #+#    #+#             */
/*   Updated: 2024/06/26 21:45:18 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_or_bottom(t_lst *node)
{
	t_lst	*top;
	t_lst	*bot;
	int		t_count;
	int		b_count;

	top = node;
	bot = node;
	t_count = 0;
	b_count = 1;
	while (top->prev)
	{
		t_count++;
		top = top->prev;
	}
	while (bot->next)
	{
		b_count++;
		bot = bot->next;
	}
	input_cost(node, t_count, b_count);
}

void	input_cost(t_lst *node, int t_count, int b_count)
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

void	move_a_cost(t_lst *node, t_stack *stack_a)
{
	t_lst	*tmp;
	int		i;

	tmp = stack_a->head;
	i = 0;
	while(tmp)
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