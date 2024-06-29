/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:15:25 by kjung             #+#    #+#             */
/*   Updated: 2024/06/29 15:22:20 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_list_for_duplication(t_stack *stack)
{
	t_lst	*cur;
	t_lst	*dup;

	cur = stack->head;
	while (cur != NULL)
	{
		dup = cur->next;
		while (dup != NULL)
		{
			if (cur->data == dup->data)
				return (0);
			dup = dup->next;
		}
		cur = cur->next;
	}
	return (1);
}

int	check_sorted(t_stack *stack)
{
	t_lst	*cur;
	t_lst	*next;

	cur = stack->head;
	while (cur != NULL)
	{
		next = cur->next;
		while (next != NULL)
		{
			if (cur->data > next->data)
				return (0);
			next = next->next;
		}
		cur = cur->next;
	}
	return (1);
}
