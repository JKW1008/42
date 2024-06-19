/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:10:39 by kjung             #+#    #+#             */
/*   Updated: 2024/06/09 22:31:10 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	press_plus_minus(int key, t_vars *vars)
{
	if (!vars)
		return ;
	if (key == 65451 || key == 61)
		adjust_scale(vars, 1.1);
	else if (key == 65453 || key == 45)
		adjust_scale(vars, 0.9);
}

void	press_arrow(int key, t_vars *vars)
{
	if (!vars)
		return ;
	if (key == 65361)
		vars->offset_x -= 10;
	else if (key == 65362)
		vars->offset_y -= 10;
	else if (key == 65363)
		vars->offset_x += 10;
	else if (key == 65364)
		vars->offset_y += 10;
	redraw(vars);
}

void	press_rotate(int key, t_vars *vars)
{
	if (!vars)
		return ;
	if (key == 120)
		rotate_x(vars, M_PI / 30);
	else if (key == 121)
		rotate_y(vars, M_PI / 30);
	else if (key == 122)
		rotate_z(vars, M_PI / 30);
	redraw(vars);
}

int	press_key_hook(int key, t_vars *vars)
{
	if (key == 65307)
		mlx_close(vars);
	if ((key == 65451 || key == 61) || (key == 65453 || key == 45))
		press_plus_minus(key, vars);
	else if (key >= 65361 && key <= 65364)
		press_arrow(key, vars);
	else if (key >= 120 && key <= 122)
		press_rotate(key, vars);
	else if (key == 114)
	{	
		vars->offset_x = 0;
		vars->offset_y = 0;
		vars->is_top_view = 0;
		vars->is_iso_view = 1;
		reset_rotation(vars);
		adjust_scale(vars, 0);
	}
	else if (key == 116)
	{
		vars->is_top_view = 1;
		vars->is_iso_view = 0;
		redraw(vars);
	}
	return (1);
}

int	press_distroy_btn(int key, t_vars *vars)
{
	if (!vars)
		return (0);
	if (key)
		exit(0);
	return (1);
}
