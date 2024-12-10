CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS_DEBUG = -fsanitize=address -g
MAKE = make --no-print-directory
NAME = philosopher

HEADER = ./includes/philosopher.h

SRCS_DIR = ./srcs
OBJS_DIR = ./objs

SRCS =	ft_philo.c \
		main.c \
		./routine/ft_monitor_routine.c \
		./routine/ft_philo_routine.c \
		./routine/ft_routine_eat.c \
		./routine/ft_routine_fork.c \
		./routine/ft_routine_sleep.c \
		./utils/ft_atoi.c \
		./utils/ft_check.c \
		./utils/ft_init.c \
		./utils/ft_philo_utils.c \
		./utils/ft_print.c \
		./utils/ft_reset_mutex.c

SRCS := $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS := $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
OBJS_DEBUG := $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%_debug.o, $(SRCS))

all: $(OBJS_DIR) $(NAME)

debug: CFLAGS += $(CFLAGS_DEBUG)

debug: $(OBJS_DIR) $(OBJS_DEBUG)
	@$(CC) $(CFLAGS) $(OBJS_DEBUG) -o $(NAME)
	@echo "philosopher (with fsnaitize=address) is ready!"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "philosopher is ready!"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER) | $(OBJS_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I./includes -c $< -o $@

$(OBJS_DIR)/%_debug.o: $(SRCS_DIR)/%.c $(HEADER) | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(CFLAGS_DEBUG) -I./includes -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@rm -rf $(OBJS_DIR)
	@echo "Cleaning..."

fclean: clean
	@rm -f $(NAME)
	@echo "Full Cleaning..."

re: fclean all

.PHONY: all clean fclean re