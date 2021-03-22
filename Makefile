NAME = cub3d
H =	includes/cub3d.h
SRC =
CC=gcc
CFLAGS=-Wall -Wextra -Werror
OBJ=$(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c $(H)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
