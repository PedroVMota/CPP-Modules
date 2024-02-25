CC = c++ -g
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =  Animal/Animal.cpp Dog/Dog.cpp Cat/Cat.cpp main.cpp
obj = $(SRC:.cpp=.o)

NAME = a

INC = -I./Animal/ -I./Dog/ -I./Cat/ 

all: $(NAME)

$(NAME): $(obj)
	$(CC) $(CFLAGS) $(INC) $(obj) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
clean:
	rm -f $(obj)

fclean: clean
	rm -f $(NAME) $(obj)

re: fclean all

.PHONY: clean fclean all re
