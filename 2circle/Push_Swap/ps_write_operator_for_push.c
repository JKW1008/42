/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_write_operator_for_push.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:44:30 by kjung             #+#    #+#             */
/*   Updated: 2024/06/23 20:50:11 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{	
	push(stack_a, stack_b);
	write(1, "pa", 2);
}

void	pb(t_stack *stack_b, t_stack *stack_a)
{
	push(stack_b, stack_b);
	write(1, "pb", 2);
}