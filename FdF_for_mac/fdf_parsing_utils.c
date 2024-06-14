/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:16:40 by kjung             #+#    #+#             */
/*   Updated: 2024/06/08 18:05:49 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_min_values	find_min_values(t_point_list *head)
{
	t_min_values	min_values;
	t_point_list	*current;

	current = head;
	min_values.min_x = INT_MAX;
	min_values.min_y = INT_MAX;
	while (current)
	{
		if (current->xpoint < min_values.min_x)
			min_values.min_x = current->xpoint;
		if (current->ypoint < min_values.min_y)
			min_values.min_y = current->ypoint;
		current = current->next;
	}
	return (min_values);
}

void	adjust_points(t_point_list *head, t_min_values min_values)
{
	t_point_list	*current;

	current = head;
	while (current)
	{
		current->xpoint -= min_values.min_x;
		current->ypoint -= min_values.min_y;
		current = current->next;
	}
}

int	get_total_points(t_point_list *head)
{
	int	total;

	total = 0;
	while (head != NULL)
	{
		total++;
		head = head->next;
	}
	return (total);
}
