SRC = plaindrome.c
NAME= is_plaindrome
CC = clang
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)
	@echo "Compiled is_plaindrome"

clean:
	@rm -rf $(NAME)
	@echo "Removed is_plaindrome"

fclean: clean
