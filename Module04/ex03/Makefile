CC = c++ -g
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Source/AMateria.cpp Source/Character.cpp Source/Cure.cpp Source/Ice.cpp Source/MateriaSource.cpp Source/main.cpp
obj = $(SRC:.cpp=.o)

NAME = a

INC = -IInterfaces/ -IHeaders/

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
