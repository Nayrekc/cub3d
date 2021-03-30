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
	int	resolution_x;
	int	resolution_y;
	int	floor;
	int	floor_r;
	int	floor_g;
	int	floor_b;
	int	ceil;
	int	ceil_r;
	int	ceil_g;
	int	ceil_b;
	int	texture_NO;
	char	*texture_NO_path;
	int	texture_SO;
	char	*texture_SO_path;
	int	texture_WE;
	char	*texture_WE_path;
	int	texture_EA;
	char	*texture_EA_path;
}				t_data;

typedef struct s_cub
{
	int	index;
	t_data	data;
}				t_cub;

int		get_next_line(int fd, char **line);
char	*ft_rec(char *str, char c);
int		ft_len_nl(char *str, char c);
size_t	ft_strlen(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		the_line(char **line, char **save, char **next, int ret);
int		free_error(char **save, int ret);

int		ft_atoi(const char *str);
void	ft_initialise_structure(t_cub *s);

#endif
