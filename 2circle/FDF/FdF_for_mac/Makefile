CC = cc
CFLAGS = -g

NAME = fdf
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
OBJS = $(SRCS:.c=.o)


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@make re -C ./mlx 
	@make re -C ./libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./libft/libft.a -I. -Lmlx -lmlx -framework OpenGL -framework Appkit


clean:
	@make clean -C ./libft
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re re_bonus dance