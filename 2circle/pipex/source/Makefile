NAME = pipex
B_NAME = pipex_bonus

CC = cc

CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address

LIB = ./Libft/libft.a

SUBDIR = ./Libft

SRCS =	pipex.c \
		px_utils.c \
		px_error.c

B_SRCS =	./bonus/pipex_bonus.c \
			./bonus/px_utils_bonus.c \
			px_utils.c \
			px_error.c

OBJS = $(SRCS:.c=.o)
BOBJS = $(B_SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
	make -C $(SUBDIR)
	$(CC) $(CFLAGS) $(OBJS) -L$(SUBDIR) $(LIB) -o $(NAME)

$(B_NAME): $(BOBJS)
	make -C $(SUBDIR)
	$(CC) $(CFLAGS) $(BOBJS) -L$(SUBDIR) $(LIB) -o $(B_NAME)

bonus: $(B_NAME)

clean:
	make clean -C $(SUBDIR)
	rm -rf $(OBJS) $(BOBJS)

fclean: clean
	make fclean -C $(SUBDIR)
	rm -rf $(NAME) $(B_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
