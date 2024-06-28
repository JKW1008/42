/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:31:39 by kjung             #+#    #+#             */
/*   Updated: 2024/06/28 22:54:40 by kjung            ###   ########.fr       */
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

void	ft_lstadd_ps_back(t_stack *stack, t_lst *new)
{
	if (!stack || !new)
		return ;
	if (!stack->head)
	{
		stack->head = new;
		stack->tail = new;
		new->prev = NULL;
		new->next = NULL;
	}
	else
	{
		stack->tail->next = new;
		new->prev = stack->tail;
		stack->tail = new;
		new->next = NULL;
	}
	stack->size++;
}
