/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_top_view_draw.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 21:31:32 by kjung             #+#    #+#             */
/*   Updated: 2024/06/12 15:31:06 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	top_horizontal_lines(t_point_list *head, t_data *img, \
								t_transform transform, int row_length)
{
	t_point_list	*tmp;
	t_coord			coord0;
	t_coord			coord1;
	int				count;

	tmp = head;
	count = 0;
	while (tmp != NULL)
	{
		coord0 = transform_point_to_p(tmp, transform);
		if ((count + 1) % row_length != 0 && tmp->next != NULL)
		{
			coord1 = transform_point_to_p(tmp->next, transform);
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

void	top_vertical_lines(t_point_list *head, t_data *img, \
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
		coord0 = transform_point_to_p(tmp, t);
		below = tmp;
		while (count.i++ < r && below->next != NULL)
			below = below->next;
		if (below != tmp && count.count++ / r != (count.total_point - 1) / r)
		{
			coord1 = transform_point_to_p(below, t);
			draw_line(img, coord0, coord1, 1);
		}
		tmp = tmp->next;
	}
}
