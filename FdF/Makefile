# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjung <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 14:50:49 by kjung             #+#    #+#              #
#    Updated: 2024/05/22 14:50:52 by kjung            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
HEADR = fdf.h
CC = arch -x86_64 gcc
CFLAGS = -g -Wall -Werror -Wextra -fsanitize=address

LIB = ./Libft/libft.a \

SUBDIR = ./Libft


SRCS = 	main.c

# MLX = ./minilibx-linux/
MLX = ./minilibx_macos/

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

%.o:%.(c)
	# $(CC) -g -I minilibx_macos -Imlx_linux -O3 -c $< -o $@
	$(CC) -g -I $(MLX) -03 -c $< -o $@

$(NAME): $(OBJS)
	@make re -C ./Libft
	# $(CC) $(CFLAGS) $(OBJS) -L$(MLX) -g -I$(MLX) -L$(SUBDIR) $(LIB) -lXext -framework OpenGL -framework Appkit -lm -lz -o $(NAME)
	# $(CC) $(CFLAGS) $(OBJS) -L$(MLX) -g -lmlx_Linux -I$(MLX) -L$(SUBDIR) $(LIB) -lXext -lX11 -lm -lz -o $(NAME)
	$(CC) $(CFLAGS) $(OBJS) -L$(MLX) -I$(MLX) -L$(SUBDIR) -framework OpenGL -framework Appkit -lm -lz -o $(NAME)
clean:
	@make clean -C ./Libft
	rm -rf $(OBJS)

fclean: clean
	@make fclean -C ./Libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re