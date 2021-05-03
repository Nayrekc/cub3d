#include "../../includes/cub3d.h"

void	init_raycast_value(t_cub *s)
{
	s->player.position_x = s->data.spawn_x;
	s->player.position_y = s->data.spawn_y;
	s->player.direction_x = -1;
	s->player.direction_y = 0;
	s->player.cam_plane_x = 0;
	s->player.cam_plane_y = 0.66;
	s->raycast.raydir_x  = 0;
	s->raycast.raydir_y = 0;
	s->raycast.sidedist_x = 0;
	s->raycast.sidedist_y = 0;
	s->time = 0;
	s->old_time = 0;
	s->raycast.map_x = 0;
	s->raycast.map_y = 0;
	s->raycast.wall_dist = 0;
}

void	init_raycast_mlx(t_cub *s)
{
	init_raycast_value(s);
}
