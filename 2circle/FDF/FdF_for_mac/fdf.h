/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:38:29 by kjung             #+#    #+#             */
/*   Updated: 2024/06/14 12:04:57 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>

# ifndef DEFAULT_COLOR
#  define DEFAULT_COLOR 0x0000FF00
# endif

# ifndef DEFAULT_HIGH_COLOR
#  define DEFAULT_HIGH_COLOR 0x00FF00FF
# endif

# ifndef SCREEN_WIDTH
#  define SCREEN_WIDTH 1200
# endif

# ifndef SCREEN_HEIGHT
#  define SCREEN_HEIGHT 900
# endif

# ifndef Z_SCALE
#  define Z_SCALE 1
# endif

# ifndef INT_MAX
#  define INT_MAX 2147483648
# endif

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_transform
{
	float	scale;
	int		offset_x;
	int		offset_y;
	float	re_scale;
	int		re_offset_x;
	int		re_offset_y;
	double	angle_x;
	double	angle_y;
	double	angle_z;
}	t_transform;

typedef struct s_vars
{
	void				*mlx;
	void				*win;
	float				scale;
	float				initial_scale;
	int					colum;
	float				offset_x;
	float				offset_y;
	int					is_top_view;
	int					is_iso_view;
	struct s_point_list	*head;
	t_data				img;
	t_transform			transform;
}	t_vars;

typedef struct s_info
{
	int	width;
	int	height;
	int	gap;
}	t_info;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_prv_point
{
	float	x;
	float	y;
	float	z;
}	t_prv_point;

typedef struct s_point_list
{
	float				xpoint;
	float				ypoint;
	float				zpoint;
	float				initial_xpoint;
	float				initial_ypoint;
	float				initial_zpoint;
	int					x;
	int					y;
	int					color_point;
	struct s_point_list	*next;
}					t_point_list;

typedef struct s_bounds
{
	long long	min_x;
	long long	max_x;
	long long	min_y;
	long long	max_y;
}	t_bounds;

typedef struct s_coord
{
	int	x;
	int	y;
	int	c;
}	t_coord;

typedef struct s_min_values
{
	double	min_x;
	double	min_y;
}	t_min_values;

typedef struct s_diff
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}	t_diff;

typedef struct s_count
{
	int	i;
	int	count;
	int	total_point;
}	t_count;

unsigned long long	string_to_hex(char *hex_string);
unsigned long long	hex_string_to_int(char c);

void				ft_lstadd_fdf_back(t_point_list **lst, t_point_list *ne);
t_point_list		*ft_fdf_lstlast(t_point_list *lst);

void				print_point_list(t_point_list *head);
void				free_split(char **line);
int					check_file_path(char *file_path);
int					check_colum(char *line);
int					check_comma(char *comma_line);

t_point_list		*isometric_projection(t_prv_point prv_point, int color);
void				insert_to_isometric_point(char *line, \
t_prv_point prv_point, t_point_list **iso_head);
void				make_to_array(char *line, int y, int col, \
t_point_list **head);
int					get_total_points(t_point_list *head);
void				gnl_and_make_list(int fd, int *colum, t_point_list **head);

t_min_values		find_min_values(t_point_list *head);
void				adjust_points(t_point_list *head, t_min_values min_values);

void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
void				mlxwindow(t_point_list *head, int colum);

t_bounds			calculate_bounds(t_point_list *head);
t_transform			calculaet_offset(t_bounds bounds, float scale);
t_transform			calculate_scaling(t_bounds bounds, t_vars *vars);

float				return_ternary_operator_value(float scale_x, float scale_y);
int					return_absolute_value(int a1, int a2);
int					return_bool(int a1, int a2);
int					return_abs(int a);
t_data				create_image(t_vars *vars);

void				draw_line(t_data *img, t_coord coord0, \
t_coord coord1, int i);
t_coord				transform_point(t_point_list *point, t_transform transform);
t_coord				transform_point_to_p(t_point_list *point, \
t_transform transform);
void				draw_horizontal_lines(t_point_list *tmp, t_data *img, \
t_transform transform, int row_length);
void				draw_vertical_lines(t_point_list *head, t_data *img, \
t_transform transform, int row_length);

void				calculate_differences(t_diff *diff, \
t_coord coord0, t_coord coord1);
void				update_positions(t_coord *coord, t_diff *diff);
int					get_gradient_color(int col0, int col1, float t);
int					lerp(int start, int end, float t);

void				press_plus_minus(int key, t_vars *vars);
void				press_arrow(int key, t_vars *vars);
void				press_rotate(int key, t_vars *vars);
int					press_key_hook(int key, t_vars *vars);
int					press_distroy_btn(int key, t_vars *vars);

void				redraw(t_vars *vars);
void				fdf_draw_black(t_data *img);

void				mlx_close(t_vars *vars);
void				adjust_scale(t_vars *vars, float factor);
void				initialize_vars(t_vars *vars);

void				top_vertical_lines(t_point_list *head, t_data *img, \
t_transform t, int r);
void				top_horizontal_lines(t_point_list *head, t_data *img, \
								t_transform transform, int row_length);

void				rotate_x(t_vars *vars, float angle);
void				rotate_y(t_vars *vars, float angle);
void				rotate_z(t_vars *vars, float angle);

void				set_initial_coordinates(t_vars *vars);
void				reset_rotation(t_vars *vars);

int					main(int argc, char *argv[]);

#endif
