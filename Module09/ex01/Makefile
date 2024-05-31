CC = c++ -g
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =  Main.cpp RPN.cpp
ASM = $(SRC:.cpp=.asm)
OBJ = $(ASM:.s=.o)

NAME = RPN

INC = -I.

all: $(NAME)

$(NAME): $(ASM) $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(NAME)

%.asm: %.cpp
	$(CC) $(CFLAGS) $(INC) -S $< -o $@

%.o: %.s
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ) $(ASM)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re