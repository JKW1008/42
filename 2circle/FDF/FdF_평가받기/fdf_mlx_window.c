/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:52:32 by kjung             #+#    #+#             */
/*   Updated: 2025/02/12 19:48:51 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x * \
		(data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	mlxwindow(t_point_list *head, int colum)
{
	t_bounds		bounds;
	t_transform		transform;
	t_point_list	*tmp;
	t_data			img;
	t_vars			vars;

	vars.head = head;
	vars.colum = colum;
	initialize_vars(&vars);
	bounds = calculate_bounds(head);
	transform = calculate_scaling(bounds, &vars);
	tmp = head;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, SCREEN_WIDTH, \
	SCREEN_HEIGHT, "Hello, World!");
	img = create_image(&vars);
	draw_horizontal_lines(head, &img, transform, colum);
	draw_vertical_lines(head, &img, transform, colum);
	set_initial_coordinates(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, &press_key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 0, &press_distroy_btn, &vars);
	mlx_loop(vars.mlx);
}
