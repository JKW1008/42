/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 22:35:59 by kjung             #+#    #+#             */
/*   Updated: 2024/06/30 21:00:31 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *dst, t_stack *src)
{
	t_lst	*tmp;

	if (!src->head)
		return ;
	tmp = src->head;
	src->head = src->head->next;
	if (src->head)
		src->head->prev = NULL;
	dst->size++;
	src->size--;
	if (!dst->head)
	{
		dst->head = tmp;
		dst->tail = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->next = dst->head;
		dst->head->prev = tmp;
		dst->head = tmp;
	}
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{	
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_b, t_stack *stack_a)
{
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
}
