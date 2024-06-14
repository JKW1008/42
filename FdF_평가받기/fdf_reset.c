/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:04:23 by kjung             #+#    #+#             */
/*   Updated: 2024/06/12 15:50:41 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_initial_coordinates(t_vars *vars)
{
	t_point_list	*current;

	current = vars->head;
	while (current != NULL)
	{
		current->initial_xpoint = current->xpoint;
		current->initial_ypoint = current->ypoint;
		current->initial_zpoint = current->zpoint;
		current = current->next;
	}
}

void	reset_rotation(t_vars *vars)
{
	t_point_list	*current;

	current = vars->head;
	while (current != NULL)
	{
		current->xpoint = current->initial_xpoint;
		current->ypoint = current->initial_ypoint;
		current->zpoint = current->initial_zpoint;
		current = current->next;
	}
}
