/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_go_a_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:49:28 by kjung             #+#    #+#             */
/*   Updated: 2024/06/30 21:51:31 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_a_util(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->tail->rank > stack_b->head->rank)
	{
		if (stack_a->head->rank > stack_a->tail->rank)
		{
			if (!find_lower(stack_a, stack_b))
			{
				while (stack_a->tail->rank < stack_a->head->rank)
					rra(stack_a);
			}
			else
			{
				while (stack_a->tail->rank > stack_b->head->rank)
					rra(stack_a);
			}
			pa(stack_a, stack_b);
		}
		else if (stack_a->head->rank < stack_a->tail->rank)
			pa(stack_a, stack_b);
	}
	else if (stack_a->tail->rank < stack_b->head->rank)
		pa(stack_a, stack_b);
}

void	go_a_util2(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->tail->rank > stack_b->head->rank)
	{
		while (stack_a->head->rank < stack_b->head->rank)
		{
			if (!find_bigger(stack_a, stack_b))
				break ;
			ra(stack_a);
		}
		pa(stack_a, stack_b);
	}
	else if (stack_a->tail->rank < stack_b->head->rank)
	{
		go_a_util3(stack_a, stack_b);
	}
}

void	go_a_util3(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->tail->rank > stack_a->head->rank)
	{
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else if (stack_a->tail->rank < stack_a->head->rank)
	{
		if (!find_bigger(stack_a, stack_b))
		{
			while (stack_a->tail->rank < stack_a->head->rank)
				ra(stack_a);
		}
		else
		{
			while (stack_a->head->rank < stack_b->head->rank)
			{
				if (!find_bigger(stack_a, stack_b))
					break ;
				ra(stack_a);
			}
		}
		pa(stack_a, stack_b);
	}
}
