CC = c++ -g
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =  AMateria/AMateria.cpp Ice/Ice.cpp Cure/Cure.cpp main.cpp
obj = $(SRC:.cpp=.o)

NAME = a

INC = -I./AMateria -I./Ice/ -I./Cure/

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
