src = Contact.cpp main.cpp Phonebook.cpp .utils.cpp
obj = $(src:.cpp=.o)
NAME = phonebook

all: $(NAME)

$(NAME): $(obj)
	g++ -Wall -Wextra -Werror -std=c++98 $(obj) -o $(NAME)

%.o: %.cpp
	g++ -Wall -Wextra -Werror -std=c++98 -c $< -o $@

clean:
	rm -f $(obj)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
