CC = c++ -g
CFLAGS = --std=c++98 #-Wall -Wextra -Werror 
SRC =  main.cpp BitcoinExchange.cpp
obj = $(SRC:.cpp=.o)

NAME = btc

INC = 

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
