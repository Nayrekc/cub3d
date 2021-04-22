#include "../../includes/cub3d.h"

void	init(t_cub *s)
{
	s->player.x = s->data.spawn_x;
	s->player.y = s->data.spawn_x;
	s->player.dir_x = -1;
	s->player.dir_y = 0;
	s->player.cam_x = 0;
	s->player.cam_y = 0.66;
}
