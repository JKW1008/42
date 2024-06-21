/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:24:13 by kjung             #+#    #+#             */
/*   Updated: 2024/06/21 14:47:54 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_stack *stack)
{
	t_lst	*tmp;
	t_lst	*tmp2;

	tmp = stack->head;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

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
		return ;
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
