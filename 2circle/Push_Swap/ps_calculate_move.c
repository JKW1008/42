/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_calculate_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:59:07 by kjung             #+#    #+#             */
/*   Updated: 2024/06/24 17:15:32 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	b_or_t(t_lst *node)
{
	t_lst	*top;
	t_lst	*bot;
	int		t_cost;
	int		b_cost;

	top = node;
	bot = node;
	t_cost = 0;
	b_cost = 0;
	while (top->prev)
	{
		t_cost++;
		top = top->prev;
	}
	while (bot->next)
	{
		b_cost++;
		bot = bot->next;
	}
	if (t_cost <= b_cost)
		return (1);
	else
		return (0);
}

int	go_t(t_lst *node)
{
	t_lst	*top;
	int		t_cost;

	top = node;
	t_cost = 0;
	while (top->prev)
	{
		t_cost++;
		top = top->prev;
	}
	return (t_cost);
}

int	go_b(t_lst *node)
{
	t_lst	*bot;
	int		b_cost;

	bot = node;
	b_cost = 1;
	while (bot->next)
	{
		b_cost++;
		bot = bot->next;
	}
	return (b_cost);
}
