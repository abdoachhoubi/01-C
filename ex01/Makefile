SRC = list.c test.c

CC = clang

CFLAGS = -Wall -Wextra -Werror

NAME = list

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "Compilation done"

clean:
	@rm -f $(NAME)
	@echo "Clean done"

fclean: clean

re: fclean all
