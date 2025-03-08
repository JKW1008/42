NAME = UnnecessaryViolence
CC = clang++
CFLAG = -Wall -Wextra -Werror -std=c++98
SRCS =	HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp \
		main.cpp \
		
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
		$(CC) $(CFLAGS) -c $< -o $@

clean :
		rm -rf $(OBJS)

fclean : clean
		rm -rf $(NAME)
	
re : fclean all

.PHONY : all clean fclean re