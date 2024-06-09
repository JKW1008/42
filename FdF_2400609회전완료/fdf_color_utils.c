/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:24:25 by kjung             #+#    #+#             */
/*   Updated: 2024/06/07 15:39:35 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_differences(t_diff *diff, t_coord coord0, t_coord coord1)
{
	diff->dx = return_absolute_value(coord1.x, coord0.x);
	diff->dy = -return_absolute_value(coord1.y, coord0.y);
	diff->sx = return_bool(coord1.x, coord0.x);
	diff->sy = return_bool(coord1.y, coord0.y);
	diff->err = diff->dx + diff->dy;
}

void	update_positions(t_coord *coord, t_diff *diff)
{
	int	err;

	err = 2 * diff->err;
	if (err >= diff->dy)
	{
		diff->err += diff->dy;
		coord->x += diff->sx;
	}
	if (err <= diff->dx)
	{
		diff->err += diff->dx;
		coord->y += diff->sy;
	}
}

int	lerp(int start, int end, float t)
{
	return ((int)(start + t * (end - start)));
}

int	get_gradient_color(int col0, int col1, float t)
{
	int	r;
	int	g;
	int	b;

	r = lerp((col0 >> 16) & 0xFF, (col1 >> 16) & 0xFF, t);
	g = lerp((col0 >> 8) & 0xFF, (col1 >> 8) & 0xFF, t);
	b = lerp(col0 & 0xFF, col1 & 0xFF, t);
	return ((r << 16) | (g << 8) | b);
}
