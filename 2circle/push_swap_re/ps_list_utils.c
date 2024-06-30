/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:25:05 by kjung             #+#    #+#             */
/*   Updated: 2024/06/30 23:29:12 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **line)
{
	int	i;

	i = 0;
	if (!line)
		return ;
	while (line[i])
		free(line[i++]);
	free(line);
}

void	init_pivot(t_plst *p_lst)
{
	p_lst->l_pivot = 0;
	p_lst->h_pivot = 0;
}

void	parcing_list_for_char(t_stack *stack, char **devided)
{
	t_lst		*next;
	long long	result;
	int			i;

	i = 0;
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
	stack->input_size = i;
}

void	parcing_list_for_digit(t_stack *stack, char **argv)
{
	t_lst		*next;
	long long	result;
	int			i;

	i = 1;
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
	stack->input_size = i - 1;
}
