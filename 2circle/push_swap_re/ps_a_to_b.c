/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_a_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:27:02 by kjung             #+#    #+#             */
/*   Updated: 2024/06/30 21:35:26 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_a_sort(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->head->rank;
	second = stack_a->head->next->rank;
	third = stack_a->head->next->next->rank;
	if (first < second && third < second && first < third)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (second < first && first < third)
		sa(stack_a);
	else if (first < second && second > third && first > third)
		rra(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (second < third && first > third && first > second)
		ra(stack_a);
}

void	a_to_b(t_stack *stack_a, t_stack *stack_b, t_plst *p_lst)
{
	t_lst	*cur;
	int		i;

	i = stack_a->size;
	p_lst->l_pivot = stack_a->size / 3;
	p_lst->h_pivot = (stack_a->size / 3) * 2;
	cur = stack_a->head;
	while (i != 0 && cur && stack_a->size > 3)
	{
		if (cur->rank < p_lst->l_pivot)
		{
			pb(stack_b, stack_a);
			rb(stack_b);
		}
		else if (cur->rank >= p_lst->l_pivot && cur->rank < p_lst->h_pivot)
			pb(stack_b, stack_a);
		else if (cur->rank >= p_lst->h_pivot)
			ra(stack_a);
		cur = stack_a->head;
		i--;
	}
	while (stack_a->size > 3)
		pb(stack_b, stack_a);
	min_a_sort(stack_a);
}
