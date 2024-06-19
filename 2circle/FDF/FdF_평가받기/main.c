/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:44:06 by kjung             #+#    #+#             */
/*   Updated: 2024/06/13 16:11:15 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_point_list	*head;
	int				fd;
	int				colum;

	head = NULL;
	colum = 0;
	if (argc != 2)
	{
		ft_printf("no argument");
		return (0);
	}
	if (check_file_path(argv[1]) != 1)
		return (0);
	else
	{
		fd = open(argv[1], O_RDONLY);
		gnl_and_make_list(fd, &colum, &head);
	}
	mlxwindow(head, colum);
	return (0);
}
