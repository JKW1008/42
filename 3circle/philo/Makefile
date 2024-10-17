NAME = philosopher
CC = cc
CFLAGS = -g -Wall -Wextra -Werror

HEADER = ./includes/philo.h

SRCS_DIR = ./srcs
OBJS_DIR = ./objs

SRCS = 	utils/ph_atoi.c \
		utils/ph_char_utils.c \
		utils/ph_struct_utils.c \
		main.c \
		philo.c

SRCS := $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS := $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))
OBJS = $(SRCS:%.c=%.o)

all: $(OBJS_DIR) $(NAME)

%.o:%.(c)
		$(CC) -g -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADR) | $(OBJS_DIR)
		mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -I./includes -c $< -o $@

$(OBJS_DIR):
		mkdir -p $(OBJS_DIR)

clean:
		rm -rf $(OBJS_DIR)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re