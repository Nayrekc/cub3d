#include "../../includes/cub3d.h"

void	parse_data_reso(t_cub *s, char *line)
{
	(s->index)++;
	s->data.resolution++;
	while (line[s->index])
	{
		while (line[s->index] == ' ')
			(s->index)++;
		if (ft_isdigit(line[s->index]) == 1)
		{
			if (s->data.resolution_x == -1)
				s->data.resolution_x = ft_atoi(s, line);
			else if (s->data.resolution_y == -1)
				s->data.resolution_y = ft_atoi(s, line);
			else
				error_exit(s, line, "Error\nFormat x y");
		}
		else if (ft_isdigit(line[s->index]) == 0 && line[s->index] != ' ' )
			error_exit(s, line, "Error\nFormat x y");
	}
	if (s->data.resolution_x < 300)
		error_exit(s, line, "Error\nToo small");
	if (s->data.resolution_y < 300)
		error_exit(s, line, "Error\nToo small");
}
