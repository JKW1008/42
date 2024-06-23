/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cost_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:54:30 by kjung             #+#    #+#             */
/*   Updated: 2024/06/21 20:12:25 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_pivot(t_stack *stack)
{
	t_pivot pivot_list;

	pivot_list.lowest_fivot = stack->size / 3;
	pivot_list.middle_fivot = stack->size / 3 * 2;
	pivot_list.highest_fivot = stack->size;

	printf("l_rank = %d\n", pivot_list.lowest_fivot);
	printf("m_rank = %d\n", pivot_list.middle_fivot);
	printf("h_rank = %d\n", pivot_list.highest_fivot);

	return ;
}