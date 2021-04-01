#include "includes/cub3d.h"

void	init_structure(t_cub *s)
{
	s->index = 0;
	s->data.resolution = 0;
	s->data.resolution_x = -1;
	s->data.resolution_y = -1;
	s->data.floor = 0;
	s->data.floor_r = -1;
	s->data.floor_g = -1;
	s->data.floor_b = -1;
	s->data.ceil = 0;
	s->data.ceil_r = -1;
	s->data.ceil_g = -1;
	s->data.ceil_b = -1;
	s->data.texture_NO = 0;
	s->data.texture_SO = 0;
	s->data.texture_WE = 0;
	s->data.texture_EA = 0;
}

int main(int argc, char **argv)
{
	t_cub s;

	if(parse_argc(argc, argv) == 1)
		return(0);
	init_structure(&s);
	parse_file(&s, argv[1]);
	return (0);
}
