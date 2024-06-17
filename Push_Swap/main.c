/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:00:25 by kjung             #+#    #+#             */
/*   Updated: 2024/06/17 19:11:19 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(t_lst *head)
{
	t_lst	*tmp;
	t_lst	*tmp2;

	tmp = head;
	while (tmp != NULL)
	{
		printf("index = %d\n", tmp->index);
		printf("data = %d\n", tmp->data);
		tmp = tmp->next;
	}
	tmp = head;
	while (tmp != NULL)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free (tmp2);
	}
}

int	main(int argc, char *argv[])
{
	t_lst	*list_a;
	t_lst	*list_b;
	int		return_value;

	list_a = NULL;
	list_b = NULL;
	return_value = check_arg(argc, argv, &list_a);
	if (!return_value)
		return (0);
	print_lst(list_a);
}
