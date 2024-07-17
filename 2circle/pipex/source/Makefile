NAME = pipex

CC = cc

CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address

LIB = ./Libft/libft.a

SUBDIR = ./Libft

SRCS =	main.c \
		px_utils.c

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

fclean:
	make fclean -C ./Libft
	rm -rf $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re