/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:24:13 by kjung             #+#    #+#             */
/*   Updated: 2024/06/19 16:21:47 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_ps_lstlast(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_ps_back(t_stack *stack, t_lst *ne)
{
	if (!stack || !ne)
		return;
	if (!stack->head)
	{
		stack->head = ne;
		stack->tail = ne;
		ne->prev = NULL;
		ne->next = NULL;
	}
	else
	{
		stack->tail->next = ne;
		ne->prev = stack->tail;
		stack->tail = ne;
		ne->next = NULL;
	}
	stack->size++;
}