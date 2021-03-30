#include "cub3d.h"

void	ft_initialise_structure(t_cub *s)
{
	s->data.resolution = 0;
	s->data.resolution_x = 0;
	s->data.resolution_y = 0;
	s->data.floor = 0;
	s->data.floor_r = 0;
	s->data.floor_g = 0;
	s->data.floor_b = 0;
	s->data.ceil = 0;
	s->data.ceil_r = 0;
	s->data.ceil_g = 0;
	s->data.ceil_b = 0;
	s->data.texture_NO = 0;
	s->data.texture_NO_path = NULL;
	s->data.texture_SO = 0;
	s->data.texture_SO_path = NULL;
	s->data.texture_WE = 0;
	s->data.texture_WE_path = NULL;
	s->data.texture_EA = 0;
	s->data.texture_EA_path = NULL;
}
