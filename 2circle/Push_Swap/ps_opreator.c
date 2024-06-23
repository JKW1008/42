/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opreator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:41:37 by kjung             #+#    #+#             */
/*   Updated: 2024/06/23 20:45:27 by kjung            ###   ########.fr       */
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

void	swap(t_stack *stack)
{
	t_lst	*tmp;

	if (!stack->head || !stack->head->next)
		return ;
	tmp = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	tmp->prev = stack->head;
	tmp->next = stack->head->next;
	stack->head->next = tmp;
	if (tmp->next)
		tmp->next->prev = tmp;
}

void	rotate(t_stack *stack)
{
	t_lst	*tmp;

	if (!stack->head || !stack->head->next)
		return ;
	tmp = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	stack->tail->next = tmp;
	tmp->prev = stack->tail;
	stack->tail = tmp;
	tmp->next = NULL;
}

void	reverse_rotate(t_stack *stack)
{
	t_lst	*tmp;

	if (!stack->head || !stack->head->next)
		return ;
	tmp = stack->tail;
	stack->tail = stack->tail->prev;
	stack->tail->next = NULL;
	tmp->prev = NULL;
	tmp->next = stack->head;
	stack->head->prev = tmp;
	stack->head = tmp;
}
