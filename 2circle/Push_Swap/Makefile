NAME = push_swap

CC = cc

CFLAGS = -g #-Wall -Wextra -Werror -fsanitize=address

LIB = ./Libft/libft.a

SUBDIR = ./Libft

SRCS = 	main.c \
		ps_arr_utils.c \
		ps_calculate_move.c \
		ps_check_arg.c \
		ps_list_parcing.c \
		ps_lst_utils.c \
		ps_move_b.c \
		ps_operator.c \
		ps_stack_utils.c \
		ps_utils.c \
		ps_write_operator_for_push.c \
		ps_write_operator_for_swap.c \
		ps_write_operator_for_rotate.c \
		ps_write_operator_for_r_rotate.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o:%.c
	$(CC) -g -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
	make -C ./Libft
	$(CC) $(CFLAGS) $(OBJS) -L$(SUBDIR) $(LIB) -o $(NAME)

clean:
	make clean -C ./Libft
	rm -rf $(OBJS)

fclean:	clean
	make fclean -C ./Libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
