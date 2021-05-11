/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:36:53 by ketaouki          #+#    #+#             */
/*   Updated: 2021/05/11 13:47:40 by ketaouki         ###   ########lyon.fr   */
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

typedef struct	s_raycast
{
	double		raydir_x; //calcul de direction x du rayon
	double		raydir_y; //calcul de direction y du rayon
	double		camera_x; //point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
	int			map_x; // coordonée x du carré dans lequel est pos
	int			map_y; // coordonnée y du carré dans lequel est pos
	double		sidedist_x; //distance que le rayon parcours jusqu'au premier point d'intersection vertical (=un coté x)
	double		sidedist_y; //distance que le rayon parcours jusqu'au premier point d'intersection horizontal (= un coté y)
	double		deltadist_x; //distance que rayon parcours entre chaque point d'intersection vertical
	double		deltadist_y; //distance que le rayon parcours entre chaque point d'intersection horizontal
	int			step_x; // -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
	int			step_y; // -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
	int			hit; // 1 si un mur a ete touche, 0 sinon
	int			side; // 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
	double		wall_dist; // distance du joueur au mur
	int			line_height; //hauteur de la ligne a dessiner
	int			draw_start; //position de debut ou il faut dessiner
	int			draw_end; //position de fin ou il faut dessiner
	int			x; //permet de parcourir tous les rayons
	int			wall_height;
}				t_raycast;

typedef struct	s_texture_init
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
	int			texture_x;
	int			texture_y;
	double		step;
	double		texture_position;
	int			texture_direction;
}				t_texture;


typedef struct s_cub
{
	int			index;
	t_data		data;
	void		*mlx;
	void		*win;
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_player	player;
	t_raycast	raycast;
	t_texture		te;
	t_texture_init	t;
	t_texture_init	t_no;
	t_texture_init	t_ea;
	t_texture_init	t_we;
	t_texture_init	t_so;
	int			width;
	int			height;
	double		moveSpeed;
	double		rotSpeed;
	double		old_direction_x;
	double		old_plane_x;
	int			key_up;
	int			key_down;
	int			key_right;
	int			key_left;
	int			arrow_right;
	int			arrow_left;
}				t_cub;

//			UTILS.c		//
int		ft_atoi(t_cub *s, const char *str);
//			UTILS		//

//			MAIN.C					//
void	init_structure(t_cub *s);
//			MAIN.C					//

//			PARSER					//
void	parse_argc(int argc, char **argv);
void	parse_file(t_cub *s, char *file);
void	parse_data(t_cub *s, int fd);
void	parse_type(t_cub *s, char *line);
int		data_full(t_cub *s);
void	parse_data_map(t_cub *s, char *line);
//			PARSER					//

//			PARSER_MAP.C			//
void	do_map(t_cub *s, char *line);
void	spawn_map(t_cub *s, char *line);
void	ft_check_map(t_cub *s, char *line, int y, int x);
void	clean_map(t_cub *s);

//			PARSER_RESOLUTION.c		//
void	parse_data_reso(t_cub *s, char *line);
void	parse_data_reso_max_min(t_cub *s, char *line);
//			PARSER_RESOLUTION.c		//

//			PARSER_COLOR.C			//
void	parse_data_floor(t_cub *s, char *line);
void	parse_data_ceil(t_cub *s, char *line);
void	parse_data_color_add(t_cub *s, char *line, int state);
void	parse_data_color_ceil(t_cub *s, char *line);
void	parse_data_color_floor(t_cub *s, char *line);
//			PARSER_COLOR.C			//

//			PARSER_PATH.C			//
void	parse_data_path_no(t_cub *s, char *line);
void	parse_data_path_so(t_cub *s, char *line);
void	parse_data_path_we(t_cub *s, char *line);
void	parse_data_path_ea(t_cub *s, char *line);
void	parse_data_path_s(t_cub *s, char *line);
//			PARSER_PATH.C			//

//			EXIT.C				//
void	error_exit(t_cub *s, char *line, char *str);
void	error_exit_msg(char *str);
void	clean_exit(t_cub *s);
//			EXIT.C				//

//			MOVE.C				//
void	move_front(t_cub *s);
void	move_back(t_cub *s);
void	move_right(t_cub *s);
void	move_left(t_cub *s);
//			MOVE.C				//

//			MOVE_CAM.C			//
void	move_cam_right(t_cub *s);
void	move_cam_left(t_cub *s);
//			MOVE_CAM.C			//

//			KEY_GESTION.C		//
int		red_cross(t_cub *s);
int		key_release(int key, t_cub *s);
void	check_move(t_cub *s);
int		key_press(int key, t_cub *s);
//			KEY_GESTION.C		//


//			INIT.C				//
void	init_raycast_value(t_cub *s);
void	initialize_dir_and_cam(t_cub *s);
void	init_raycast_mlx(t_cub *s);
//			INIT.C				//

//			WINDOW.C			//
void	window(t_cub *s);
//			WINDOW.C			//

//			RAYCAST.C			//
int		raycast(t_cub *s);
void	draw_raycast(t_cub *s);
void	sky_floor_raycast(t_cub *s);
void	hit_raycast(t_cub *s);
void	step_raycast(t_cub *s);
void	init_raycast(t_cub *s);
//			RAYCAST.C			//



void	init_texture(t_cub *s);
void	check_dir(t_cub *s);
//			GAME				//

#endif
