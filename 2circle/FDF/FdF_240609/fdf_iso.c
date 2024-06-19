/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_iso.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 22:49:22 by kjung             #+#    #+#             */
/*   Updated: 2024/06/09 18:15:16 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void rotate_x(t_point *point, double angle)
{
    double rad = angle * M_PI / 180.0;
    double y = point->y;
    double z = point->z;
    point->y = y * cos(rad) - z * sin(rad);
    point->z = y * sin(rad) + z * cos(rad);
}

void rotate_y(t_point *point, double angle)
{
    double rad = angle * M_PI / 180.0;
    double x = point->x;
    double z = point->z;
    point->x = x * cos(rad) + z * sin(rad);
    point->z = -x * sin(rad) + z * cos(rad);
}

void rotate_z(t_point *point, double angle)
{
    double rad = angle * M_PI / 180.0;
    double x = point->x;
    double y = point->y;
    point->x = x * cos(rad) - y * sin(rad);
    point->y = x * sin(rad) + y * cos(rad);
}

t_point apply_transform(t_point_list *point2d, t_transform transform)
{
    t_point point;
    point.x = point2d->xpoint;
    point.y = point2d->ypoint;
    point.z = point2d->zpoint;

    // Apply rotation using pointers
    rotate_x(&point, transform.angle_x);
    rotate_y(&point, transform.angle_y);
    rotate_z(&point, transform.angle_z);

    // Apply isometric projection
    t_point transformed;
    transformed.x = (point.x - point.y) * cos(0.523599) + transform.offset_x;
    transformed.y = (point.x + point.y) * sin(0.523599) - point.z * Z_SCALE + transform.offset_y;
    transformed.z = point.z;

    return transformed;
}



