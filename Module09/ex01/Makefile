CC = c++ -g
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =  Main.cpp RPN.cpp
obj = $(SRC:.cpp=.o)

NAME = rpn

INC = -I.

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
