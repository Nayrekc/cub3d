#include "../../includes/cub3d.h"


void	window(t_cub *s)
{
	int x;
	int y;

	x = 0;
	y = 0;

	init_raycast_mlx(s);
	s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, s->width, s->height, "Cub3D");
	s->img = mlx_new_image(s->mlx, s->width, s->height);
	s->addr = (int *)mlx_get_data_addr(s->img, &s->bits_per_pixel, &s->line_length, &s->endian);
	raycast(s);
	mlx_hook(s->win, 2, 1L<<0, key_press, s);
	mlx_hook(s->win, 3, 1L<<0, key_release, s);
	mlx_loop_hook(s->mlx, raycast, s);
	mlx_loop(s->mlx);
}
