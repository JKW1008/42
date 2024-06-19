/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keys_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:17:16 by kjung             #+#    #+#             */
/*   Updated: 2024/06/09 18:22:53 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_close(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	exit(0);
}

void	adjust_scale(t_vars *vars, float factor)
{
	if (factor == 0)
		vars->scale = vars->initial_scale;
	else
		vars->scale *= factor;
	redraw(vars);
}

void	initialize_vars(t_vars *vars)
{
	vars->scale = 0.7;
	vars->initial_scale = vars->scale;
	vars->offset_x = 0;
	vars->offset_y = 0;
	// vars->angle_x = 0.0;
	// vars->angle_y = 0.0;
	// vars->angle_z = 0.0;
}