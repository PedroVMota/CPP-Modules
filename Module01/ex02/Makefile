CC = c++
CFLAGS = -Wall -Wextra -Werror

SRC = newZombie.cpp randomChump.cpp Zombie.cpp zombieHorder.cpp
obj = $(src:.cpp=.o)

NAME = Zombie

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
