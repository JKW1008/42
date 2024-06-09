/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:10:39 by kjung             #+#    #+#             */
/*   Updated: 2024/06/09 18:41:56 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	press_esc_key(int key, t_vars *vars)
{
	if (!vars)
		return (0);
	if (key == 65307)
		mlx_close(vars);
	else if (key == 65451 || key == 61)
		adjust_scale(vars, 1.1);
	else if (key == 65453 || key == 45)
		adjust_scale(vars, 0.9);
	else if (key == 114)
	{	
		vars->offset_x = 0;
		vars->offset_y = 0;
		vars->is_top_view = 0;
		vars->is_iso_view = 1;
		// vars->angle_x = 0;
        // vars->angle_y = 0;
        // vars->angle_z = 0;
		adjust_scale(vars, 0);
	}
	else if (key == 65361)
	{
		vars->offset_x -= 10;
		redraw(vars);
	}
	else if (key == 65362)
	{
		vars->offset_y -= 10;
		redraw(vars);
	}
	else if (key == 65363)
	{
		vars->offset_x += 10;
		redraw(vars);
	}
	else if (key == 65364)
	{
		vars->offset_y += 10;
		redraw(vars);
	}
	else if (key == 116)
	{
		vars->is_top_view = 1;
		vars->is_iso_view = 0;
		redraw(vars);
	}
	else if (key == 120)
		ft_printf("key is = %d\n", key);
	else if (key == 121)
		ft_printf("key is = %d\n", key);
	else if (key == 122)
		ft_printf("key is = %d\n", key);
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
