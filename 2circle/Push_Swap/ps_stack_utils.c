/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:11:03 by kjung             #+#    #+#             */
/*   Updated: 2024/06/24 17:09:59 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

void	update_rank(t_stack *stack)
{
	t_lst	*cur;
	t_lst	*dup;

	cur = stack->head;
	while (cur != NULL)
	{
		cur->rank = 0;
		dup = stack->head;
		while (dup != NULL)
		{
			if (cur->data > dup->data)
				cur->rank += 1;
			dup = dup->next;
		}
		cur = cur->next;
	}
	return ;
}

int	value_in_stack(int start, int end, t_stack *stack)
{
	t_lst	*tmp;

	tmp = stack->head;
	while (tmp)
	{
		if (start <= tmp->rank && tmp->rank < end)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
