#include "Libft/libft.h"

#ifndef FDF_H
# define FDF_H

# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef DEFAULT_COLOR
#  define DEFAULT_COLOR 0x00FFFFFF
# endif


typedef struct s_point_list
{
	int	xpoint;
	int ypoint;
	int zpoint;
	int color_point;
	struct s_point_list *next;
}					t_point_list;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bit;
	int		line_length;
	int		endian;
}			t_data;
#endif