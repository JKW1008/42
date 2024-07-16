NAME = pipex

CC = cc

CFLAGS = -g #-Wall -Wextra -Werror

LIB = ./Libft/libft.a

SUBDIR = ./Libft

SRCS =	main.c \
		px_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o:%.cc
	$(CC) -g -c $(CFLAGS) $< -o $@

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

.PHONY: all clean fclean re