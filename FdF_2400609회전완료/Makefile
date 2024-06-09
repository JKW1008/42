# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjung <kjung@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 14:50:49 by kjung             #+#    #+#              #
#    Updated: 2024/06/09 22:35:15 by kjung            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
# HEADR = fdf.h
CC = cc
CFLAGS = -g -Wall -Werror -Wextra -fsanitize=address

LIB = ./Libft/libft.a \

SUBDIR = ./Libft

SRCS = 	fdf_calculate.c \
		fdf_color_utils.c \
		fdf_draw_line.c \
		fdf_draw_utils.c \
		fdf_iso.c \
		fdf_keys_utils.c \
		fdf_keys.c \
		fdf_lst_utils.c \
		fdf_mlx_window.c \
		fdf_parsing_utils.c \
		fdf_parsing.c \
		fdf_redraw.c \
		fdf_reset.c \
		fdf_string_utils.c \
		fdf_top_view_draw.c \
		fdf_utils.c \
		main.c 

MLX = ./minilibx-linux/

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

%.o:%.(c)
	$(CC) -g -I minilibx-linux -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	@make re -C ./Libft
	$(CC) $(CFLAGS) $(OBJS) -L$(MLX) -g -lmlx_Linux -I$(MLX) -L$(SUBDIR) $(LIB) -lXext -lX11 -lm -lz -o $(NAME)
#$(CC) $(OBJS) -L$(MLX) -g -lmlx_Linux -I$(MLX) -L$(SUBDIR) $(LIB) -lXext -lX11 -lm -lz -o $(NAME)

clean:
	@make clean -C ./Libft
	rm -rf $(OBJS)

fclean: clean
	@make fclean -C ./Libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
