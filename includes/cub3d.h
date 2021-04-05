#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../Libft/libft.h"

typedef struct	s_data
{
	int	resolution;
	int	floor;
	int	ceil;
	int	texture_NO;
	int	texture_SO;
	int	texture_WE;
	int	resolution_x;
	int	resolution_y;
	int	texture_EA;
	int	floor_r;
	int	floor_g;
	int	floor_b;
	int	floor_a;
	int	ceil_r;
	int	ceil_g;
	int	ceil_b;
	int	ceil_a;
	char	*texture_NO_path;
	char	*texture_SO_path;
	char	*texture_WE_path;
	char	*texture_EA_path;
}				t_data;

typedef struct s_cub
{
	int	index;
	t_data	data;
}				t_cub;


//			GNL			//
int		get_next_line(int fd, char **line);
//			GNL			//

//			UTILS		//
int		ft_atoi(t_cub *s, const char *str);
void	init_structure(t_cub *s);
//			UTILS		//

//			PARSER		//
int	parse_argc(int argc, char **argv);
void	parse_value(t_cub *s, char *line);
void	parse_data(t_cub *s, int fd);
void	parse_file(t_cub *s, char *file);

void	parse_data_path_no(t_cub *s, char *line);
void	parse_data_reso(t_cub *s, char *line);
void	parse_data_floor(t_cub *s, char *line);
void	parse_data_ceil(t_cub *s, char *line);
void	parse_data_color(t_cub *s, int state);
void	error_exit(char *str);
//			PARSER		//

#endif
