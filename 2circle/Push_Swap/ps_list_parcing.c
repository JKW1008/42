/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_parcing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:32:33 by kjung             #+#    #+#             */
/*   Updated: 2024/06/19 14:07:31 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void parcing_list_for_char(t_stack *stack, char **devided)
{	//	문자열일 경운
	t_lst *next;
	long long result;
	int i = 0;

	while (devided[i] != NULL)
	{
		next = (t_lst *)malloc(sizeof(t_lst));
		result = ft_atol(devided[i]);
		next->index = i;
		next->data = (int)result;
		next->next = NULL;
		ft_lstadd_ps_back(stack, next);
		i++;
	}
}

void	parcing_list_for_digit(t_stack *stack, char **argv)
{	//	숫자일 경우
	t_lst *next;
	long long result;
	int i = 1;

	while (argv[i] != NULL)
	{
		next = (t_lst *)malloc(sizeof(t_lst));
		result = ft_atol(argv[i]);
		next->index = i - 1;
		next->data = (int)result;
		next->next = NULL;
		ft_lstadd_ps_back(stack, next);
		i++;
	}
}
