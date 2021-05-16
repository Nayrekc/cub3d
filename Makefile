NAME			=		Cub3D

INC_DIR			=		includes

HEADERS			=		includes/cub3d.h

CC				=		gcc

CFLAGS 			= 		-Wall -Wextra -Werror -g3

SRCS			=		main.c \
						$(addprefix parser/, parse_data.c parse.c parse_color.c parse_resolution.c parse_path.c parse_map.c) \
						$(addprefix utils/, exit.c utils.c) \
						$(addprefix game/, sprite.c sprite_init.c texture.c draw.c key_gestion.c move_cam.c move.c window.c init.c raycast.c) \

OBJS			= 		$(addprefix srcs/, $(SRCS:.c=.o))

LIB 			= 		libft/libft.a

all				: 		compilation $(NAME)

compilation		:
		@make -C libft
		@make -C mlx

$(NAME)		: $(OBJS)
		@mv ./mlx/libmlx.dylib .
		@$(CC) $(CFLAGS) $(OBJS) -I $(HEADERS) $(LIB) libmlx.dylib -o $(NAME)
		@echo "\033[34m[Cub3D] Compiled .Cub3D\033[0m"

%.o: %.c $(HEADERS)
		@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

bonus		:		$(NAME)

clean		:
		@rm -f $(OBJS)
		@rm -f libmlx.dylib
		@make clean -C libft
		@make clean -C mlx

fclean		:		clean
		@rm -f $(NAME)
		@rm -f libmlx.dylib
		@make fclean -C libft
		@make fclean -C mlx

re			:		fclean all

.PHONY: all bonus clean fclean re


