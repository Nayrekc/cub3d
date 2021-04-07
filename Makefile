NAME			=		Cub3D

INC_DIR			=		includes

HEADERS			=		includes/cub3d.h

CC				=		gcc

CFLAGS 			= 		-Wall -Wextra -Werror -O3

SRCS			=		\
						main.c \
						$(addprefix parser/, parse_data.c parse.c parse_color.c parse_resolution.c parse_path.c parse_map.c) \
						$(addprefix utils/, errors.c utils.c) \

OBJS			= 		$(addprefix srcs/, $(SRCS:.c=.o))

LIB 			= 		libft/libft.a

all				: 		$(NAME)

$(NAME)		: $(OBJS)
		@make -C libft
		@$(CC) $(CFLAGS) $(OBJS) -I $(HEADERS) $(LIB) -o $(NAME)

%.o: %.c $(HEADERS)
		@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

bonus		:		$(NAME)

clean		:
		@/bin/rm -f $(OBJS)
		@make clean -C libft

fclean		:		clean
		@/bin/rm -f $(NAME)
		@make fclean -C libft

re			:		fclean all




