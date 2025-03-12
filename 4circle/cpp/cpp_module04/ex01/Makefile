NAME = Polymorphism
CC = clang++
CFLAG = -Wall -Wextra -Werror -std=c++98
SRCS =	Animal.cpp \
		main.cpp \
		Cat.cpp \
		Dog.cpp \
		Brain.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp
		
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