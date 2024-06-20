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
	if (key == 24)
		adjust_scale(vars, 1.1);
	else if (key ==27)
		adjust_scale(vars, 0.9);
}

void	press_arrow(int key, t_vars *vars)
{
	if (!vars)
		return ;
	if (key == 123)
		vars->offset_x -= 10;
	else if (key == 126)
		vars->offset_y -= 10;
	else if (key == 124)
		vars->offset_x += 10;
	else if (key == 125)
		vars->offset_y += 10;
	redraw(vars);
}

void	press_rotate(int key, t_vars *vars)
{
	if (!vars)
		return ;
	if (key == 7)
		rotate_x(vars, M_PI / 30);
	else if (key == 16)
		rotate_y(vars, M_PI / 30);
	else if (key == 6)
		rotate_z(vars, M_PI / 30);
	redraw(vars);
}

int	press_key_hook(int key, t_vars *vars)
{
	ft_printf("key = %d\n", key);
	if (key == 53)
		mlx_close(vars);
	if (key == 24 || key == 27)
		press_plus_minus(key, vars);
	else if (key >= 123 && key <= 126)
		press_arrow(key, vars);
	else if (key == 7 || key == 16 || key == 6)
		press_rotate(key, vars);
	else if (key == 15)
	{	
		vars->offset_x = 0;
		vars->offset_y = 0;
		vars->is_top_view = 0;
		vars->is_iso_view = 1;
		reset_rotation(vars);
		adjust_scale(vars, 0);
	}
	else if (key == 17)
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
