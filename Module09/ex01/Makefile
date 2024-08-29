CC = c++ -g
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =  Main.cpp RPN.cpp
OBJ = $(SRC:.cpp=.o)

NAME = RPN

INC = -I.

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ) 
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re