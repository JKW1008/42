#include "Libft/libft.h"

#ifndef FDF_H
# define FDF_H

# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_point_list
{
	int	xpoint;
	int ypoint;
	int zpoint;
	int color_point;
	struct s_point_list *next;
}					t_point_list;

typedef struct s_shape
{
	int width;
	int height;
}	t_shape;


#endif