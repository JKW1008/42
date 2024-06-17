/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_parcing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:32:33 by kjung             #+#    #+#             */
/*   Updated: 2024/06/17 19:12:39 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parcing_list_for_char(t_lst **list_a, char **devided)
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
		printf("%d\n", i);
		ft_lstadd_ps_back(list_a, next);
		i++;
	}
}
