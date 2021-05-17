/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:36:53 by ketaouki          #+#    #+#             */
/*   Updated: 2021/05/17 10:25:02 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

typedef struct s_data
{
	int		resolution;
	int		floor;
	int		ceil;
	int		resolution_x;
	int		resolution_y;
	int		floor_r;
	int		floor_g;
	int		floor_b;
	int		floor_a;
	int		ceil_r;
	int		ceil_g;
	int		ceil_b;
	int		ceil_a;
	char	*texture_NO_path;
	char	*texture_SO_path;
	char	*texture_WE_path;
	char	*texture_EA_path;
	char	*texture_S_path;
	char	*str;
	char	**map;
	int		start_parse_map;
	char	spawn;
	int		spawn_x;
	int		spawn_y;
	int		nb_sprite;
}				t_data;

typedef struct s_player
{
	double	position_x;
	double	position_y;
	double	direction_x;
	double	direction_y;
	double	cam_plane_x;
	double	cam_plane_y;
}				t_player;

typedef struct s_raycast
{
	double		raydir_x;
	double		raydir_y;
	double		camera_x;
	int			map_x;
	int			map_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			x;
	int			wall_height;
}				t_raycast;

typedef struct s_texture_init
{
	int		texture_width;
	int		texture_height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*img;
	int		*addr;
}				t_texture_init;

typedef struct s_texture
{
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		position;
	int			texture_direction;
}				t_texture;

typedef struct s_sprite_x_y
{
	double		x;
	double		y;

}				t_sprites_x_y;

typedef struct s_sprite
{
	int		i;
	double	*dist;
	int		*order;
	double	x;
	double	y;
	double	inv_det;
	double	transform_x;
	double	transform_y;
	double	screen_x;
	int		height;
	int		width;
	int		draw_start_x;
	int		draw_start_y;
	int		draw_end_x;
	int		draw_end_y;
	int		stripe;
	double	*buffer;
	int		text_x;
	int		text_y;
}				t_sprite;

typedef struct s_cub
{
	int					index;
	t_data				data;
	void				*mlx;
	void				*win;
	void				*img;
	int					*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	t_player			player;
	t_raycast			raycast;
	t_texture			te;
	t_texture_init		t;
	t_texture_init		t_no;
	t_texture_init		t_ea;
	t_texture_init		t_we;
	t_texture_init		t_so;
	t_texture_init		t_sprite;
	t_sprite			sprite;
	t_sprite			*sprite_x_y;
	int					width;
	int					height;
	double				moveSpeed;
	double				rotSpeed;
	double				old_direction_x;
	double				old_plane_x;
	int					key_up;
	int					key_down;
	int					key_right;
	int					key_left;
	int					arrow_right;
	int					arrow_left;
	int					save;
}				t_cub;

//			UTILS.c		//
int		ft_atoi(t_cub *s, const char *str);

//			MAIN.C					//
void	init_structure(t_cub *s);

//			PARSER					//
void	parse_argc(t_cub *s, int argc, char **argv);
void	parse_file(t_cub *s, char *file);
void	parse_data(t_cub *s, int fd);
void	parse_type(t_cub *s, char *line);
int		data_full(t_cub *s);
void	parse_data_map(t_cub *s, char *line);

//			PARSER_MAP.C			//
void	do_map(t_cub *s, char *line);
void	spawn_map(t_cub *s, char *line);
void	ft_check_map(t_cub *s, char *line, int y, int x);
void	clean_map(t_cub *s);

//			PARSER_RESOLUTION.c		//
void	parse_data_reso(t_cub *s, char *line);
void	parse_data_reso_max_min(t_cub *s, char *line);

//			PARSER_COLOR.C			//
void	parse_data_floor(t_cub *s, char *line);
void	parse_data_ceil(t_cub *s, char *line);
void	parse_data_color_add(t_cub *s, char *line, int state);
void	parse_data_color_ceil(t_cub *s, char *line);
void	parse_data_color_floor(t_cub *s, char *line);

//			PARSER_PATH.C			//
void	parse_data_path_no(t_cub *s, char *line);
void	parse_data_path_so(t_cub *s, char *line);
void	parse_data_path_we(t_cub *s, char *line);
void	parse_data_path_ea(t_cub *s, char *line);
void	parse_data_path_s(t_cub *s, char *line);

//			EXIT.C				//
void	error_exit(t_cub *s, char *line, char *str);
void	error_exit_msg(char *str);
void	clean_exit(t_cub *s);
void	free_sprite(t_cub *s);
void	bmp(t_cub *s);

//			MOVE.C				//
void	move_front(t_cub *s);
void	move_back(t_cub *s);
void	move_right(t_cub *s);
void	move_left(t_cub *s);

//			MOVE_CAM.C			//
void	move_cam_right(t_cub *s);
void	move_cam_left(t_cub *s);

//			KEY_GESTION.C		//
int		red_cross(t_cub *s);
int		key_release(int key, t_cub *s);
void	check_move(t_cub *s);
int		key_press(int key, t_cub *s);

//			INIT.C				//
void	init_raycast_value(t_cub *s);
void	initialize_dir_and_cam(t_cub *s);
void	init_raycast_mlx(t_cub *s);

//			WINDOW.C			//
void	size_screen(t_cub *s);
void	window(t_cub *s);

//			RAYCAST.C			//
int		raycast(t_cub *s);
void	sky_floor_raycast(t_cub *s);
void	hit_raycast(t_cub *s);
void	step_raycast(t_cub *s);
void	init_raycast(t_cub *s);

//			TEXTURE.C			//
void	init_texture_NO(t_cub *s);
void	init_texture_SO(t_cub *s);
void	init_texture_WE(t_cub *s);
void	init_texture_EA(t_cub *s);
void	init_texture(t_cub *s);

//			DRAW.C				//
void	draw_raycast(t_cub *s);
void	draw_wall(t_cub *s);
void	check_wall_pos(t_cub *s);

//			SPRITE_INIT.C		//
void	init_variable_sprite(t_cub *s);
void	get_position_sprite(t_cub *s);
void	init_texture_sprite(t_cub *s);
void	sprite_dist(t_cub *s);
void	sprite_order(t_cub *s);

//			SPRITE				//
void	sprite_calcul(t_cub *s, int i);
void	sprite_calcul_2(t_cub *s);
void	sprite_aff(t_cub *s);
void	sprite_aff_2(t_cub *s);
void	sprite(t_cub *s);

#endif
