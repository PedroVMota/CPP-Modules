CC = c++ -g
CFLAGS = -Wall -Wextra -Werror

SRC = main.cpp ClapTrap.cpp
obj = $(SRC:.cpp=.o)

NAME = a

all: $(NAME)

$(NAME): $(obj)
	$(CC) -Wall -Wextra -Werror -std=c++98 $(obj) -o $(NAME)

%.o: %.cpp
	$(CC) -Wall -Wextra -Werror -std=c++98 -c $< -o $@

clean:
	rm -f $(obj)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
