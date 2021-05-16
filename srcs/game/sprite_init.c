#include "../../includes/cub3d.h"

void    init_variable_sprite(t_cub *s)
{
    if(!(s->sprite.order = (int *)ft_calloc(s->data.nb_sprite, sizeof(int))))
		clean_exit(s);
	if(!(s->sprite_x_y = (t_sprite *)ft_calloc(s->data.nb_sprite, sizeof(t_sprite))))
		clean_exit(s);
	if(!(s->sprite.dist = (double *)ft_calloc(s->data.nb_sprite, sizeof(t_sprite))))
		clean_exit(s);
}

void    get_position_sprite(t_cub *s)
{
    int y;
	int x;
	int i;

	y = 0;
	i = 0;
	init_variable_sprite(s);
    while(s->data.map[y])
	{
		x = 0;
		while(s->data.map[y][x])
		{
			if (s->data.map[y][x] == '$')
			{
				s->sprite_x_y[i].x = (double)x + 0.5;
				s->sprite_x_y[i].y = (double)y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	sprite_dist(t_cub *s)
{
	int		i;
	
	i = 0;
	while (i < s->data.nb_sprite)
	{
		s->sprite.order[i] = i;
		s->sprite.dist[i] = ((s->player.position_x - s->sprite_x_y[i].x)
			* (s->player.position_x - s->sprite_x_y[i].x)
				+ (s->player.position_y - s->sprite_x_y[i].y) 
				* (s->player.position_y - s->sprite_x_y[i].y));
		i++;
	}
	sprite_order(s);
}

void	sprite_order(t_cub *s)
{
	int		i;
	int		j;
	double	tmp;
	int		tmp_order;

	i = 0;
	while (i < s->data.nb_sprite)
	{
		j = -1;
		while(++j < s->data.nb_sprite)
		{
			if (s->sprite.dist[j] < s->sprite.dist[j + 1])
			{
				tmp = s->sprite.dist[j];
				s->sprite.dist[j] = s->sprite.dist[j + 1];
				s->sprite.dist[j + 1] = tmp;
				tmp_order = s->sprite.order[j];
				s->sprite.order[j] = s->sprite.order[j + 1];
				s->sprite.order[j + 1] = tmp_order;
			}
		}
		i++;	
	}
}

void	init_texture_sprite(t_cub *s)
{
	s->t_sprite.img = mlx_xpm_file_to_image(s->mlx, s->data.texture_S_path,
			&s->t_sprite.texture_width, &s->t_sprite.texture_height);
	s->t_sprite.addr = (int *)mlx_get_data_addr(s->t_sprite.img, 
			&s->bits_per_pixel, &s->t_sprite.line_length, &s->t_sprite.endian);		
}