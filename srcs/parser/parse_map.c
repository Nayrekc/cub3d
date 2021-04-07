#include "../../includes/cub3d.h"

void	parse_data_map(t_cub *s, char *line)
{
	s->data.str = ft_strjoin(s->data.str, line, '\n');
	s->data.map = ft_split(s->data.str, '\n');
}
