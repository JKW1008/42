/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:20:42 by kjung             #+#    #+#             */
/*   Updated: 2024/06/28 23:42:53 by kjung            ###   ########.fr       */
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

void	call_stack_free(t_stack *stack_a, t_stack *stack_b)
{
	free_list(stack_a);
	free_list(stack_b);
}
