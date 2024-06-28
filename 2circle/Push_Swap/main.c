/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:00:25 by kjung             #+#    #+#             */
/*   Updated: 2024/06/28 20:22:04 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(t_lst *head)
{
	t_lst	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		printf("index = %d\n", tmp->index);
		printf("data = %d\n", tmp->data);
		tmp = tmp->next;
	}
}

// void	print_stack(t_stack *stack)
// {
// 	t_lst	*tmp;

// 	tmp = stack->head;
// 	printf("head index = %d, tail index = %d\n", \
// 	stack->head->index, stack->tail->index);
// 	printf("head data = %d, tail data = %d\n", \
// 	stack->head->data, stack->tail->data);
// 	while (tmp != NULL)
// 	{
// 		printf("value is %d, rank is %d, index is %d\n", \
// 		tmp->data, tmp->rank, tmp->index);
// 		tmp = tmp->next;
// 	}
// }

// void print_stack(t_stack *stack)
// {
// 	t_lst *temp = stack->head;
// 	while (temp)
// 	{	
// 		printf("%d ", temp->rank);
// 		temp = temp->next;
// 	}
// 	printf("\n\n");
// }

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack stack_b;
	int		return_value;

	init_stack(&stack_a);
	init_stack(&stack_b);
	return_value = check_arg(argc, argv, &stack_a);
	if (!return_value)
	{
		free_list(&stack_a);
		return (0);
	}
	if (!check_list_for_duplication(&stack_a))
	{
		ft_printf("Error\n");
		free_list(&stack_a);
		return (0);
	}
	if (check_sorted(&stack_a))
	{
		ft_printf("sorted\n");
		free_list(&stack_a);
		return (0);
	}
	update_rank(&stack_a);
	// print_stack(&stack_a);
	move_b(&stack_a, &stack_b);
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}
