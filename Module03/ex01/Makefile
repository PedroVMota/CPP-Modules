CC = c++ -g
CFLAGS = -Wall -Wextra -Werror

SRC = main.cpp ClapTrap/ClapTrap.cpp
obj = $(SRC:.cpp=.o)

NAME = a

INC = -IClapTrap/

all: $(NAME)

$(NAME): $(obj)
	$(CC) -Wall -Wextra -Werror $(INC) -std=c++98 $(obj) -o $(NAME)

%.o: %.cpp
	$(CC) -Wall -Wextra -Werror $(INC) -std=c++98 -c $< -o $@

clean:
	rm -f $(obj)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
