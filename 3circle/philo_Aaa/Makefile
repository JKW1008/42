NAME = philosopher
CC = cc
CFLAGS = -g -Werror -Wextra -Wall

HEADER = philo.h

SRCS =	char_utils.c \
		check.c \
		free.c \
		get_time.c \
		init.c \
		main.c \
		print.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean reㅋ