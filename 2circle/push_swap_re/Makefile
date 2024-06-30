NAME = push_swap

CC = cc

CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address

LIB = ./Libft/libft.a

SUBDIR = ./Libft

SRCS = 	main.c \
		ps_a_to_b.c \
		ps_arg_check.c \
		ps_b_to_a.c \
		ps_cal_cost.c \
		ps_find_node.c \
		ps_go_a_utils.c \
		ps_list_utils.c \
		ps_list_utils2.c \
		ps_push.c \
		ps_r_rotate.c \
		ps_rotate.c \
		ps_stack_check.c \
		ps_stack_utils.c \
		ps_str_utils.c \
		ps_swap.c

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
