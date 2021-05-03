#include "../../includes/cub3d.h"

void	init_raycast(t_cub *s)
{
	s->raycast.camera_x = 2 * s->raycast.x / s->width - 1;
	s->raycast.raydir_x = s->player.direction_x + s->player.cam_plane_x * s->raycast.camera_x;
	s->raycast.raydir_y = s->player.direction_y + s->player.cam_plane_y * s->raycast.camera_x;
	s->raycast.map_x = s->player.position_x;
	s->raycast.map_y = s->player.position_y;
	s->raycast.deltadist_x = fabs(1 / s->raycast.raydir_x);
	s->raycast.deltadist_y = fabs(1 / s->raycast.raydir_x);
	s->raycast.hit = 0;
}

void	step_raycast(t_cub *s)
{
	if(s->raycast.raydir_x < 0)
	{
		s->raycast.step_x = -1;
		s->raycast.sidedist_x = (s->player.position_x - s->raycast.map_x) * s->raycast.deltadist_x;
	}
	else
	{
		s->raycast.step_x = 1;
		s->raycast.sidedist_x = (s->raycast.map_x + 1.0 - s->player.position_x) * s->raycast.deltadist_x;
	}
	if(s->raycast.raydir_y < 0)
	{
		s->raycast.step_y = -1;
		s->raycast.sidedist_y = (s->player.position_y - s->raycast.map_y) * s->raycast.deltadist_y;
	}
	else
	{
		s->raycast.step_y = 1;
		s->raycast.sidedist_y = (s->raycast.map_y + 1.0 - s->player.position_y) * s->raycast.deltadist_y;
	}
}


// void			assign_side(t_cub *s)
// {
// 	if (s->raycast.side == 0)
// 	{
// 		if (s->raycast.map_x < s->player.position_x)
// 			s->raycast.side = 1;
// 	}
// 	else
// 	{
// 		if (s->raycast.map_y< s->player.position_y)
// 			s->raycast.side = 3;
// 	}
// }

void	hit_raycast(t_cub *s)
{
	while(!s->raycast.hit)
	{
		if(s->raycast.sidedist_x < s->raycast.sidedist_y)
		{
			s->raycast.sidedist_x += s->raycast.deltadist_x;
			s->raycast.map_x += s->raycast.step_x;
			s->raycast.side = 0;
		}
		else
		{
			s->raycast.sidedist_y += s->raycast.deltadist_y;
			s->raycast.map_y += s->raycast.step_y;
			s->raycast.side = 2;
		}
		if (s->data.map[s->raycast.map_y][s->raycast.map_x] == '|')
			s->raycast.hit = 1;
	}
	// assign_side(s);
}

void	sky_floor_raycast(t_cub *s)
{
	if(s->raycast.side == 0)
		s->raycast.wall_dist =
		(s->raycast.map_x - s->player.position_x + (1 - s->raycast.step_x) / 2) / s->raycast.raydir_x;
	else
		s->raycast.wall_dist =
		(s->raycast.map_y - s->player.position_y + (1 - s->raycast.step_y) / 2) / s->raycast.raydir_y;
	s->raycast.line_height = (long int)(s->raycast.wall_height / s->raycast.wall_dist);
	s->raycast.draw_start = -s->raycast.line_height / 2 + s->raycast.wall_height / 2;
	if(s->raycast.draw_start < 0)
		s->raycast.draw_start = 0;
	s->raycast.draw_end = -s->raycast.line_height / 2 + s->raycast.wall_height / 2;
	if(s->raycast.draw_end < 0)
		s->raycast.draw_end = s->raycast.wall_height - 1;
}

void	raycast(t_cub *s)
{
	s->raycast.x = 0;
	init_raycast_mlx(s);
	s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, s->data.resolution_x,
	s->data.resolution_y, "Cub3D");

	init_raycast(s);
	step_raycast(s);
	hit_raycast(s);
	sky_floor_raycast(s);
	mlx_loop(s->mlx);
}
