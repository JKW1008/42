/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_redraw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:17:45 by kjung             #+#    #+#             */
/*   Updated: 2024/06/09 18:26:39 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_draw_black(t_data *img)
{
	ft_memset(img->addr, 0, SCREEN_HEIGHT * img->line_length);
}

void	redraw(t_vars *vars)
{
	t_bounds	bounds;
	t_transform	transform;

	fdf_draw_black(&vars->img);
	bounds = calculate_bounds(vars->head);
	transform = calculate_scaling(bounds, vars);
	transform.offset_x += vars->offset_x;
	transform.offset_y += vars->offset_y;
	if (vars->is_iso_view)
	{
		draw_horizontal_lines(vars->head, &vars->img, transform, vars->colum);
		draw_vertical_lines(vars->head, &vars->img, transform, vars->colum);
	}
	else if (vars->is_top_view)
	{
		top_horizontal_lines(vars->head, &vars->img, transform, vars->colum);
		top_vertical_lines(vars->head, &vars->img, transform, vars->colum);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

// void redraw(t_vars *vars)
// {
//     t_bounds bounds;
//     t_transform transform;

//     fdf_draw_black(&vars->img);
//     bounds = calculate_bounds(vars->head);
//     transform = calculate_scaling(bounds, vars);
//     transform.offset_x += vars->offset_x;
//     transform.offset_y += vars->offset_y;
//     transform.angle_x = vars->angle_x; // 각도 값 설정
//     transform.angle_y = vars->angle_y; // 각도 값 설정
//     transform.angle_z = vars->angle_z; // 각도 값 설정

//     if (vars->is_iso_view)
//     {
//         draw_horizontal_lines(vars->head, &vars->img, transform, vars->colum);
//         draw_vertical_lines(vars->head, &vars->img, transform, vars->colum);
//     }
//     else if (vars->is_top_view)
//     {
//         top_horizontal_lines(vars->head, &vars->img, transform, vars->colum);
//         top_vertical_lines(vars->head, &vars->img, transform, vars->colum);
//     }

//     mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
// }
