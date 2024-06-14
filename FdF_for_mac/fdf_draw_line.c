/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:41:42 by kjung             #+#    #+#             */
/*   Updated: 2024/06/12 15:30:53 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_data *img, t_coord coord0, \
t_coord coord1, int i)
{
	t_diff	diff;
	int		step;
	int		steps;
	float	t;
	int		color;

	calculate_differences(&diff, coord0, coord1);
	step = 0;
	if (diff.dx > -diff.dy)
		steps = return_abs(diff.dx);
	else
		steps = return_abs(diff.dy);
	while (step <= steps)
	{
		t = (float)step / steps;
		if (coord0.c != coord1.c && i == 1)
		{
			color = get_gradient_color(coord0.c, coord1.c, t);
		}
		else
			color = coord0.c;
		my_mlx_pixel_put(img, coord0.x, coord0.y, color);
		update_positions(&coord0, &diff);
		step++;
	}
}

t_coord	transform_point(t_point_list *point, t_transform transform)
{
	t_coord	coord;

	coord.x = point->xpoint * transform.scale + transform.offset_x;
	coord.y = point->ypoint * transform.scale + transform.offset_y;
	coord.c = point->color_point;
	return (coord);
}

t_coord	transform_point_to_p(t_point_list *point, t_transform transform)
{
	t_coord	coord;

	coord.x = point->x * transform.scale + transform.offset_x;
	coord.y = point->y * transform.scale + transform.offset_y;
	coord.c = point->color_point;
	return (coord);
}

void	draw_horizontal_lines(t_point_list *head, t_data *img, \
								t_transform transform, int row_length)
{
	t_point_list	*tmp;
	t_coord			coord0;
	t_coord			coord1;
	int				count;

	tmp = head;
	count = 0;
	while (tmp != NULL && tmp->next != NULL)
	{
		coord0 = transform_point(tmp, transform);
		if ((count + 1) % row_length != 0 && row_length != tmp->x)
		{
			coord1 = transform_point(tmp->next, transform);
			draw_line(img, coord0, coord1, 1);
		}
		else
		{
			coord1 = coord0;
			draw_line(img, coord0, coord1, 0);
		}
		count++;
		tmp = tmp->next;
	}
}

void	draw_vertical_lines(t_point_list *head, t_data *img, \
t_transform t, int r)
{
	t_point_list	*tmp;
	t_point_list	*below;
	t_coord			coord0;
	t_coord			coord1;
	t_count			count;

	tmp = head;
	count.count = 0;
	count.total_point = get_total_points(head);
	while (tmp != NULL)
	{
		count.i = 0;
		coord0 = transform_point(tmp, t);
		below = tmp;
		while (count.i++ < r && below->next != NULL)
			below = below->next;
		if (below != tmp && count.count++ / r != (count.total_point - 1) / r)
		{
			coord1 = transform_point(below, t);
			draw_line(img, coord0, coord1, 1);
		}
		tmp = tmp->next;
	}
}
