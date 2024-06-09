/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:15:24 by kjung             #+#    #+#             */
/*   Updated: 2024/06/09 18:21:31 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point_list *isometric_projection(t_prv_point prv_point, int color)
{
    t_point_list *point2d;

    point2d = (t_point_list *)malloc(sizeof(t_point_list));
    if (!point2d)
        return (NULL);
    point2d->xpoint = (prv_point.x - prv_point.y) * cos(0.523599);
    point2d->ypoint = (prv_point.x + prv_point.y) * sin(0.523599) - prv_point.z * Z_SCALE;
    point2d->zpoint = prv_point.z;
    point2d->x = (int)prv_point.x;
    point2d->y = (int)prv_point.y;
    point2d->color_point = color;
    point2d->next = NULL;
    return (point2d);
}
void	insert_to_isometric_point(char *line, t_prv_point prv_point, \
t_point_list **iso_head)
{
	t_point_list	*iso_point;
	char			**divided_comma;
	int				color_point;

	if (check_comma(line) > -1)
	{
		divided_comma = ft_split(line, ',');
		prv_point.z = ft_atoi(divided_comma[0]);
		color_point = string_to_hex(divided_comma[1]);
		free_split(divided_comma);
	}
	else
	{
		prv_point.z = ft_atoi(line);
		if (prv_point.z >= 1)
			color_point = DEFAULT_HIGH_COLOR;
		else
			color_point = DEFAULT_COLOR;
	}
	iso_point = isometric_projection(prv_point, color_point);
	ft_lstadd_fdf_back((t_point_list **)iso_head, (t_point_list *)iso_point);
}

void	make_to_array(char *line, int y, t_point_list **head)
{
	char	**divided;
	t_prv_point	prv_point;
	int		i;

	i = 0;
	divided = ft_split(line, ' ');
	prv_point.y = y;
	while (divided[i] != NULL)
	{
		prv_point.x = i;
		insert_to_isometric_point(divided[i], prv_point, head);
		i++;
	}
	free_split(divided);
}

void	gnl_and_make_list(int fd, int *colum, t_point_list **head)
{
	char			*line;
	int				y;
	t_min_values	min_values;

	y = 0;
	if (fd == -1)
	{
		ft_printf("Error, cannot open file");
		return ;
	}
	line = get_next_line(fd);
	*colum = check_colum(line);
	while (line)
	{
		make_to_array(line, y, head);
		y++;
		free(line);
		line = get_next_line(fd);
	}
	min_values = find_min_values(*head);
	adjust_points(*head, min_values);
	close(fd);
}
