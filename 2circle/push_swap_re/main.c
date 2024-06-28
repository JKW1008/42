/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:16:16 by kjung             #+#    #+#             */
/*   Updated: 2024/06/28 23:32:05 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	init_stack(&stack_a);
	init_stack(&stack_b);
	if (!check_all(argc, argv, &stack_a))
		return (0);
	update_rank(&stack_a);
	a_to_b(&stack_a, &stack_b);
	call_stack_free(&stack_a, &stack_b);
}
