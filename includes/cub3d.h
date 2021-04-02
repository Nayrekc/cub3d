#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

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
	int	ceil_r;
	int	ceil_g;
	int	ceil_b;
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
size_t	ft_strlen(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putchar(char c);
void	ft_putstr(char *s);
//			UTILS		//

//			PARSER		//
int	parse_argc(int argc, char **argv);
void	parse_value(t_cub *s, char *line);
void	parse_data(t_cub *s, int fd);
void	parse_file(t_cub *s, char *file);
void	parse_data_int(t_cub *s, char *line);
void	error_exit(char *str);
//			PARSER		//

#endif
