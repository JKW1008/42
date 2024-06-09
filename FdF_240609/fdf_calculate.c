/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_calculate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:42:11 by kjung             #+#    #+#             */
/*   Updated: 2024/06/08 16:02:52 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bounds	calculate_bounds(t_point_list *head)
{
	t_bounds		bounds;
	t_point_list	*current;

	current = head;
	bounds.min_x = head->xpoint;
	bounds.max_x = head->xpoint;
	bounds.min_y = head->ypoint;
	bounds.max_y = head->ypoint;
	while (current != NULL)
	{
		if (current->xpoint < bounds.min_x)
			bounds.min_x = current->xpoint;
		if (current->xpoint > bounds.max_x)
			bounds.max_x = current->xpoint;
		if (current->ypoint < bounds.min_y)
			bounds.min_y = current->ypoint;
		if (current->ypoint > bounds.max_y)
			bounds.max_y = current->ypoint;
		current = current->next;
	}
	return (bounds);
}

t_transform	calculate_offset(t_bounds bounds, float scale)
{
	t_transform	tmp;
	int			x;
	int			y;

	x = bounds.max_x - bounds.min_x;
	y = bounds.max_y - bounds.min_y;
	tmp.offset_x = (SCREEN_WIDTH - x * scale) / 2 - bounds.min_x * scale;
	tmp.offset_y = (SCREEN_HEIGHT - y * scale) / 2 - bounds.min_y * scale;
	tmp.scale = scale;
	return (tmp);
}

t_transform	calculate_scaling(t_bounds bounds, t_vars *vars)
{
	float	scale_x;
	float	scale_y;
	float	scale;

	scale_x = (float)SCREEN_WIDTH / (bounds.max_x - bounds.min_y);
	scale_y = (float)SCREEN_HEIGHT / (bounds.max_y - bounds.min_y);
	scale = return_ternary_operator_value(scale_x, scale_y);
	return (calculate_offset(bounds, scale * vars->scale));
}
