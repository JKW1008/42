/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_first_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:22:11 by kjung             #+#    #+#             */
/*   Updated: 2024/06/23 21:24:43 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_b(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	t_lst	*tmp;

	tmp = stack_a->head;

	while (tmp)
	{
		if (tmp->rank <= pivot)
		{
			
		}
	}
}