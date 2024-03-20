CC = c++ -g
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = AForm/AForm.cpp Bureaucrat/Bureaucrat.cpp main.cpp ShrubberyCreationForm/ShrubberyCreationForm.cpp RobotomyRequestForm/RobotomyRequestForm.cpp
obj = $(SRC:.cpp=.o)

NAME = a

INC = -I./From -I./Bureaucrat/

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
