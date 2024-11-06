NAME = philosopher
CC = cc
CFLAGS = -g -Werror -Wextra -Wall

HEADER = philo.h

SRCS =	char_utils.c \
		check_args.c \
		error.c \
		init.c \
		main.c \
		philo_utils.c \
		philos_do.c \
		philo.c

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