NAME = phonebook
CC = clang++
CFLAG = -Wall -Wextra -Werror -std=c++98
SRCS =	PhoneBook.cpp \
		Contact.cpp \
		ex01.cpp \
		Utils.cpp \

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