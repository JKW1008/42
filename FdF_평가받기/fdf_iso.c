/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_iso.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:59:12 by kjung             #+#    #+#             */
/*   Updated: 2024/06/09 21:51:48 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_vars *vars, float angle)
{
	t_point_list	*current;
	float			old_y;
	float			old_z;

	current = vars->head;
	while (current != NULL)
	{
		old_y = current->ypoint;
		old_z = current->zpoint * Z_SCALE;
		current->ypoint = old_y * cos(angle) - old_z * sin(angle);
		current->zpoint = old_y * sin(angle) + old_z * cos(angle);
		current = current->next;
	}
}

void	rotate_y(t_vars *vars, float angle)
{
	t_point_list	*current;
	float			old_x;
	float			old_z;

	current = vars->head;
	while (current != NULL)
	{
		old_x = current->xpoint;
		old_z = current->zpoint * Z_SCALE;
		current->xpoint = old_x * cos(angle) + old_z * sin(angle);
		current->zpoint = -old_x * sin(angle) + old_z * cos(angle);
		current = current->next;
	}
}

void	rotate_z(t_vars *vars, float angle)
{
	t_point_list	*current;
	float			old_x;
	float			old_y;

	current = vars->head;
	while (current != NULL)
	{
		old_x = current->xpoint;
		old_y = current->ypoint;
		current->xpoint = old_x * cos(angle) - old_y * sin(angle);
		current->ypoint = old_x * sin(angle) + old_y * cos(angle);
		current = current->next;
	}
}
