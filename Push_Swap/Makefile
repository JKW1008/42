NAME = push_swap

CC = cc

CFLAGS = -g  -Wall -Wextra -Werror -fsanitize=address

LIB = ./Libft/libft.a \

SUBDIR = ./Libft

SRCS = 	main.c \
		ps_arr_utils.c \
		ps_check_arg.c \
		ps_utils.c 

OBJS = $(SRCS: %.c=%.o)

all: $(NAME)

%.o:%.(c)
	$(CC) -g -O3 -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
	make -C ./Libft
	$(CC) $(CFLAGS) $(OBJS) -L$(SUBDIR) $(LIB) -o $(NAME)

clean:
	make clean -C ./Libft
	rm -rf $(OBJS)

fclean:
	make fclean -C ./Libft
	rm -rf $(NAME)

re: fclean all

.PHONEY: all clean fclean re
