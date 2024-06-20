/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keys_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:17:16 by kjung             #+#    #+#             */
/*   Updated: 2024/06/14 12:03:24 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	list_free(t_point_list *head)
{
	t_point_list	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	mlx_close(t_vars *vars)
{
	// mlx_destroy_image(vars->mlx, vars->img.img);
	// mlx_destroy_window(vars->mlx, vars->win);
	// mlx_destroy_display(vars->mlx);
	// free(vars->mlx);
	// list_free(vars->head);
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
}
