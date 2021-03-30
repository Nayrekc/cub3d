#include "cub3d.h"

int read_cub(char *line, t_cub *s)
{
	while (line[s->index])
	{
		if(line[s->index] == 'R')
		{
			s->data.resolution = 1;
			(s->index)++;
			while(line[s->index] == ' ')
				s->index++;
			s->data.resolution_x = ft_atoi(&line[s->index]);
			while(line[s->index] >= '0' && line[s->index] <= '9')
				(s->index)++;
			while(line[s->index] == ' ')
				s->index++;
			s->data.resolution_y = ft_atoi(&line[s->index]);
			while(line[s->index] >= '0' && line[s->index] <= '9')
				(s->index)++;
			printf("%d", s->data.resolution_x);
			printf("%d", s->data.resolution_y);
		}
		(s->index)++;
	}
	return (0);
}


int main(void)
{
	int r;
	int fd;
	char *line;
	t_cub	s;

	s.index = 0;
	line = NULL;
	fd = open("map.cub", O_RDONLY);
	r = get_next_line(fd, &line);
	ft_initialise_structure(&s);
	while(r > 0)
	{
		read_cub(line, &s);
		free(line);
		line = NULL;
		r = get_next_line(fd, &line);
	}
	free(line);
	line = NULL;
	return (0);
}
