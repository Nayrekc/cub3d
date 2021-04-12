CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a
SRCS=	./allocations/ft_bzero.c \
		./allocations/ft_calloc.c \
		./allocations/ft_memccpy.c \
		./allocations/ft_memchr.c \
		./allocations/ft_memcmp.c \
		./allocations/ft_memcpy.c \
		./allocations/ft_memmove.c \
		./allocations/ft_memset.c \
		./allocations/ft_strdup.c \
		./checker/ft_isascii.c \
		./checker/ft_isalpha.c \
		./checker/ft_isdigit.c \
		./checker/ft_isalnum.c \
		./checker/ft_isprint.c \
		./checker/ft_strchr.c \
		./checker/ft_strrchr.c \
		./converters/ft_atoi.c \
		./converters/ft_itoa.c \
		./list_functions/ft_lstadd_back.c \
		./list_functions/ft_lstadd_front.c \
		./list_functions/ft_lstclear.c \
		./list_functions/ft_lstdelone.c \
		./list_functions/ft_lstiter.c \
		./list_functions/ft_lstlast.c \
		./list_functions/ft_lstmap.c \
		./list_functions/ft_lstnew.c \
		./list_functions/ft_lstsize.c \
		./printers/ft_putchar_fd.c \
		./printers/ft_putstr_fd.c \
		./printers/ft_putendl_fd.c \
		./printers/ft_putnbr_fd.c \
		./printers/ft_putchar.c \
		./printers/ft_putstr.c \
		./printers/ft_putnbr.c \
		./string_functions/ft_toupper.c \
		./string_functions/ft_tolower.c \
		./string_functions/ft_strlen.c \
		./string_functions/ft_strncmp.c \
		./string_functions/ft_strlcpy.c \
		./string_functions/ft_strlcat.c \
		./string_functions/ft_strnstr.c \
		./string_functions/ft_substr.c \
		./string_functions/ft_strjoin.c \
		./string_functions/ft_strtrim.c \
		./string_functions/ft_split.c \
		./string_functions/ft_strmapi.c
OBJS=$(SRCS:.c=.o)
INC=libft.h
RM=@rm -f

%.c%.o:
	$(CC) $(CFLAGS) -c $< -o $@ $(INC) -g

all:		$(NAME)

$(OBJS):	$(INC)

$(NAME): 	$(INC) $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) libft.ghc.h

fclean: 	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all bonus clean fclean re
