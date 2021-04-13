/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:36:53 by ketaouki          #+#    #+#             */
/*   Updated: 2021/04/13 16:22:45 by ketaouki         ###   ########lyon.fr   */
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
	int		spawn_x;
	int		spawn_y;
}				t_data;

typedef struct s_cub
{
	int		index;
	t_data	data;
}				t_cub;

//			GNL			//
int		get_next_line(int fd, char **line);
//			GNL			//

//			UTILS.c		//
int		ft_atoi(t_cub *s, const char *str);
//			UTILS		//

//			MAIN.C					//
void	init_structure(t_cub *s);
//			MAIN.C					//

//			PARSER		//
void	parse_argc(int argc, char **argv);
void	parse_file(t_cub *s, char *file);
void	parse_data(t_cub *s, int fd);
void	parse_type(t_cub *s, char *line);
int		data_full(t_cub *s);
void	parse_data_map(t_cub *s, char *line);
void	parse_spawn_map(t_cub *s, char *line);
void	spawn_map(t_cub *s);
void    ft_check_map(t_cub *s, char *line, int y, int x);
void	clean_map(t_cub *s);
void	aff_map(t_cub *s);
void	aff_map_utilis(char c);
void	aff_player(int c);

//			PARSER_RESOLUTION.c		//
void	parse_data_reso(t_cub *s, char *line);
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

//			ERRORS.C				//
void	error_exit(t_cub *s, char *line, char *str);
void	error_exit_msg(char *str);
//			ERRORS.C				//

#endif
