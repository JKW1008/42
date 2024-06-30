/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_find_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:37:05 by kjung             #+#    #+#             */
/*   Updated: 2024/06/30 21:43:10 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_lower(t_stack *stack_a, t_stack *stack_b)
{
	t_lst	*tmp;

	tmp = stack_a->head;
	while (tmp)
	{
		if (stack_b->head->rank > tmp->rank)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	find_bigger(t_stack *stack_a, t_stack *stack_b)
{
	t_lst	*tmp;

	tmp = stack_a->head;
	while (tmp)
	{
		if (stack_b->head->rank < tmp->rank)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
