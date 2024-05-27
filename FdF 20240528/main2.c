#include <unistd.h>
#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include "fdf.h"

// void ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// int deal_key(int key, void *param)
// {
// 	ft_putchar('X');
// 	// mlx_pixel_put(mlx_ptr, win_ptr);
// 	return (0);
// }

// typedef struct s_vars
// {
// 	void	*mlx;
// 	void	*win;
// }	t_vars;




// typedef struct s_data
// {
// 	void	*img;
// 	char	*addr;
// 	int		bit#include "ft_printf/ft_printf.h"s_per_pixel;
// 	int		line_length;
// 	int		endian;
// }			t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int mouse_hook(int keycode, t_vars *vars)
// {
// 	printf("Hello from key_hook!\n");
// 	return (0);
// }

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

t_point_list	*insert_to_point(char *line, int y)
{
	t_point_list	*point_list;
	t_point_list	*cur;
	t_point_list	*new;
	char	**divided_comma;
	int	i;

	i = 0;
	point_list = NULL;
	cur = NULL;

	while(line[i] != '\n' && line[i])
	{	
		new = (t_point_list *)malloc(sizeof(t_point_list));
		if (!new)
			return (NULL);
		new->xpoint = i;
		new->ypoint = y;
		if (check_comma(&line[i]) > -1)
		{
			divided_comma = ft_split(&line[i], ',');
			new->zpoint = ft_atoi(divided_comma[0]);
			new->color_point = string_to_hex(divided_comma[1]);
			free_split(divided_comma);
		}
		else
		{
			new->zpoint = ft_atoi(&line[i]);
			new->color_point = DEFAULT_COLOR;
		}
		new->next = NULL;

		if (!point_list)
			point_list = new;
		else
			cur->next = new;
		cur = new;
		i++;
	}
	return (point_list);
}

void	make_two_array(char *line, int y, t_point_list **head)
{
	char	**path_divided;
	int i;
	t_point_list	*new_points;
	t_point_list	*cur;

	i = 0;
	path_divided = ft_split(line, ' ');
	while (path_divided[i] != 0)
	{
		new_points = insert_to_point(path_divided[i], y);
		ft_printf("%s", path_divided[i]);
		ft_printf("\n");
		if (!*head)
			*head = new_points;
		else
		{
			cur = *head;
			while (cur->next)
				cur = cur->next;
			cur->next = new_points;
		}
		i++;
	}
	free_split(path_divided);
}


// void	input_value_struct(char **line)
// {
// 	t_point_list point_list;
	
// 	point_list = (t_point_list *)malloc(sizeof(t_point_list));
// }

int main(int argc, char *argv[])
{
	// void	*mlx;

	// mlx = mlx_init();
	// mlx_loop(mlx);

	// void	*mlx;
	// void	*mlx_win;

	int fd;
	int y;
	char *line;
	t_point_list *head;

	head = NULL;

	y = 0;
	if (argc != 2)
	{
		ft_printf("파일을 넣어주세요");
		return (0);
	}
	if (check_file_path(argv[1]) != 1)
	{
		return (0);
	} else {
		ft_printf("success\n");
		ft_printf(argv[1]);
		ft_printf("\n");
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_printf("Error, cannot open file\n");
			return (0);
		}
		line = get_next_line(fd);
		while (line)
		{
			// ft_printf("%s", line);
			make_two_array(line, y, &head);
			free(line);
			line = get_next_line(fd);
			y++;
		}
	}
	// t_data	img;
	// t_vars 	vars;


	// vars.mlx = mlx_init();	result[i] = NULL;
	// vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello, world!");
	// img.img = mlx_new_image(vars.mlx, 640, 480);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 100, 100, 0x00FFFFFF);
	// mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	// mlx_mouse_hook(vars.win, mouse_hook, &vars);
	// mlx_loop(vars.mlx);

	// void *mlx_ptr;
	// void *win_ptr;

	// mlx_ptr = mlx_init();
	// win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx_42");
	// mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	// // mlx_key_hook(win_ptr, deal_key, (void *)0);

	// mlx_loop(mlx_ptr);
}