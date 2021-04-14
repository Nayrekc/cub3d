NAME			=		Cub3D

INC_DIR			=		includes

HEADERS			=		includes/cub3d.h

CC				=		gcc

CFLAGS 			= 		-Wall -Wextra -Werror -O3

SRCS			=		\
						main.c \
						$(addprefix parser/, parse_data.c parse.c parse_color.c parse_resolution.c parse_path.c parse_map.c) \
						$(addprefix utils/, exit.c utils.c aff_map_terminal.c) \

OBJS			= 		$(addprefix srcs/, $(SRCS:.c=.o))

LIB 			= 		libft/libft.a mlx/libmlx.dylib

all				: 		$(NAME)

$(NAME)		: $(OBJS)
		@make -C libft
		@make -C mlx
		cp mlx/libmlx.dylib .
		@$(CC) $(CFLAGS) $(OBJS) -I $(HEADERS) $(LIB) -o $(NAME) -Lmlx -lmlx -lm

%.o: %.c $(HEADERS)
		@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

bonus		:		$(NAME)

clean		:
		@/bin/rm -f $(OBJS)
		@/bin/rm -f libmlx.dylib
		@make clean -C libft
		@make clean -C mlx

fclean		:		clean
		@/bin/rm -f $(NAME)
		@/bin/rm -f libmlx.dylib
		@make fclean -C libft
		@make fclean -C mlx

re			:		fclean all




