/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:56:18 by kjung             #+#    #+#             */
/*   Updated: 2024/06/08 00:29:34 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	return_ternary_operator_value(float scale_x, float scale_y)
{
	if (scale_x < scale_y)
		return (scale_x);
	return (scale_y);
}

int	return_absolute_value(int a1, int a2)
{
	if (a1 - a2 < 0)
		return ((a1 - a2) * -1);
	else
		return (a1 - a2);
	return (0);
}

int	return_bool(int a1, int a2)
{
	if (a1 > a2)
		return (1);
	else
		return (-1);
	return (0);
}

int	return_abs(int a)
{
	if (a < 0)
		return (a *= -1);
	return (a);
}

t_data	create_image(t_vars *vars)
{
	t_data	img;

	img.bits_per_pixel = 0;
	img.line_length = 0;
	img.endian = 0;
	img.img = mlx_new_image(vars->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, \
	&img.bits_per_pixel, &img.line_length, &img.endian);
	vars->img = img;
	return (img);
}
