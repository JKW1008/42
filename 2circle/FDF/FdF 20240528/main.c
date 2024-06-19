/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:39:54 by kjung             #+#    #+#             */
/*   Updated: 2024/05/27 23:56:06 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include "fdf.h"
// ========================================mlx=======================================================
int mouse_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void mlxwindow()
{
	void	*mlx;
	void	*mlx_win;

	t_data	img;
	t_vars 	vars;


	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello, world!");
	img.img = mlx_new_image(vars.mlx, 640, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 100, 100, 0x00FFFFFF);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);

	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx_42");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);

	mlx_loop(mlx_ptr);
}

// ========================================utils=======================================

int check_file_path(char *file_path)
{
	char	**path_divided;
	int	divided_length;
	int	answer;

	answer = 0;
	divided_length = 0;
	path_divided = ft_split(file_path, '.');
	if (!path_divided)
		return (ft_printf("split error"));
	while (path_divided[divided_length] != 0)
		divided_length++;
	if (ft_strncmp(path_divided[divided_length - 1], "fdf", 4) == 0)
		answer = 1;
	while (divided_length >= 0)
	{
		free(path_divided[divided_length]);
		divided_length--;
	}
	free(path_divided);
	return (answer);
}

void	free_split(char **line)
{
	int	i;
	
	i = 0;
	if (!line)
		return ;
	while (line[i] != NULL)
	{
		free(line[i]);
		i++;
	}
	free(line);
}

int check_comma(char *comma_line)
{
	int i;

	i = 0;
	while (comma_line[i])
	{
		if (comma_line[i] == ',')
			return (i);
		i++;
	}
	return (-1);
}

unsigned long long hex_string_to_int(char c)
{
	if ('0' <= c && '9' >= c)
		return (c -'0');
	if ('a' <= c && 'f' >= c)
		return (10 + (c - 'a'));
	if ('A' <= c && 'F' >= c)
		return (10 + (c - 'A'));
	return (0);
}

unsigned long long	string_to_hex(char *hex_string)
{
	unsigned long long result;
	const char *p;

	p = hex_string;
	result = 0;

	if (p[0] == '0' && (p[1] == 'x' || p[1] == 'X'))
		p += 2;
	while (*p)
	{
		result = result * 16 + hex_string_to_int(*p);
		p++;
	}
	return (result);
}


// ======================================================================================

t_point_list	*ft_fdf_lstlast(t_point_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_fdf_back(t_point_list **lst, t_point_list *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_fdf_lstlast(*lst)->next = new;
}

void 	insert_to_point(char *line, int x, int y, t_point_list *lst)
{
	t_point_list *next;
	char	**divided_comma;

	next = (t_point_list *)malloc(sizeof(t_point_list));
	(next)->xpoint = x;
	(next)->ypoint = y;
	if (check_comma(line) > -1)
	{
		divided_comma = ft_split(line, ',');
		(next)->zpoint = ft_atoi(divided_comma[0]);
		(next)->color_point = string_to_hex(divided_comma[1]);
		ft_printf("%d\n", (next)->color_point);
		free_split(divided_comma);
	}
	else
	{
		(next)->zpoint = ft_atoi(line);
		(next)->color_point = DEFAULT_COLOR;
	}	
	ft_lstadd_fdf_back(&lst, next);
	free(next);
	next = NULL;
}


void	make_to_array(char *line, int y, t_point_list *head)
{
	char	**divided;
	int	i;

	i = 0;
	divided = ft_split(line, ' ');
	while (divided[i] != NULL)
	{
		insert_to_point(divided[i], i, y, head);
		i++;
	}
	free_split(divided);
}


int	main(int argc, char *argv[])
{
	int	fd;
	char *line;
	int	y;
	t_point_list	*head;

	head = NULL;
	y = 0;
	if (argc != 2)
	{
		ft_printf("파일을 넣어주세요");
		return (0);
	}
	if (check_file_path(argv[1]) != 1)
		return (0);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_printf("Error, cannot open file");
			return (0);
		}
		line = get_next_line(fd);
		while (line)
		{
			make_to_array(line, y, head);
			y++;
			free(line);
			line = get_next_line(fd);
		}
	}
}