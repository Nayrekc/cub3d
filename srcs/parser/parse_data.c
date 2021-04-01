#include "../../includes/cub3d.h"

void	parse_data_int(t_cub *s, char *line)
{
	if(line[s->index] == 'R')
	{
		s->index++;
		s->data.resolution++;
		while(line[s->index])
		{
			while (line[s->index] == ' ')
				s->index++;
			if ((line[s->index] >= '0' && line[s->index] <= '9'))
			{
				if (s->data.resolution_x == -1)
				{
					s->data.resolution_x = ft_atoi(&line[s->index]);
					while(line[s->index] >= '0' && line[s->index] <= '9')
						s->index++;
					if (!(line[s->index] >= '0' && line[s->index] <= '9') && line[s->index] != ' ')
						error_exit("Not a good format 1");
				}
				else if(s->data.resolution_y == -1)
				{
					s->data.resolution_y = ft_atoi(&line[s->index]);
					while(line[s->index] >= '0' && line[s->index] <= '9')
						s->index++;
					if (!(line[s->index] >= '0' && line[s->index] <= '9') && line[s->index] != ' ' && line[s->index] != '\0')
						error_exit("Not a good format 2");
				}
				else
				{
					error_exit("Not a good format 3");
				}
			}
			else if (line[s->index] != ' ' || !(line[s->index] >= '0' && line[s->index] <= '9'))
				error_exit("Not a good format 4");
			s->index++;
		}
		//printf("RESO = %d ", s->data.resolution_x);
		//printf("%d\n", s->data.resolution_y);
	}

	// if(*line == 'F')
	// {
	// 	line++;
	// 	s->data.floor++;
	// 	while(*line)
	// 	{
	// 		while (*line == ' ' || *line == ',')
	// 			line++;
	// 		if ((*line >= '0' && *line <= '9'))
	// 		{
	// 			if (s->data.floor_r == -1)
	// 			{
	// 				s->data.floor_r = ft_atoi(line);
	// 				while(*line >= '0' && *line <= '9')
	// 					line++;
	// 				if (!(*line >= '0' && *line <= '9') && *line != ' ' && *line != ',')
	// 					error_exit("Not a good format 5");
	// 			}
	// 			else if(s->data.floor_g == -1)
	// 			{
	// 				s->data.floor_g = ft_atoi(line);
	// 				while(*line >= '0' && *line <= '9')
	// 					line++;
	// 				if (!(*line >= '0' && *line <= '9') && *line != ' ' && *line != ',')
	// 					error_exit("Not a good format 6");
	// 			}
	// 			else if(s->data.floor_b == -1)
	// 			{
	// 				s->data.floor_b = ft_atoi(line);
	// 				while(*line >= '0' && *line <= '9')
	// 					line++;
	// 				if (!(*line >= '0' && *line <= '9') && *line != ' ' && *line != ',' && *line != '\0')
	// 					error_exit("Not a good format 7");
	// 			}
	// 			else if (*line != '\n')
	// 				error_exit("Not a good format 8");
	// 		}
	// 		else if (*line != ' ' || *line != ',' || !(*line >= '0' && *line <= '9'))
	// 			error_exit("Not a good format 9");
	// 		line++;
	// 	}
	// 		printf("FLOOR R = %d\n ", s->data.floor_r);
	// 		printf("FLOOR G = %d\n", s->data.floor_g);
	// 		printf("FLOOR B = %d\n", s->data.floor_b);
	// }

	// if(*line == 'C')
	// {
	// 	line++;
	// 	s->data.ceil++;
	// 	while(*line)
	// 	{
	// 		while (*line == ' ' || *line == ',')
	// 			line++;
	// 		if ((*line >= '0' && *line <= '9'))
	// 		{
	// 			if (s->data.ceil_r == -1)
	// 			{
	// 				s->data.ceil_r = ft_atoi(line);
	// 				while(*line >= '0' && *line <= '9')
	// 					line++;
	// 				if (!(*line >= '0' && *line <= '9') && *line != ' ' && *line != ',')
	// 					error_exit("Not a good format 10");
	// 			}
	// 			else if(s->data.ceil_g == -1)
	// 			{
	// 				s->data.ceil_g = ft_atoi(line);
	// 				while(*line >= '0' && *line <= '9')
	// 					line++;
	// 				if (!(*line >= '0' && *line <= '9') && *line != ' ' && *line != ',')
	// 					error_exit("Not a good format 11");
	// 			}
	// 			else if(s->data.ceil_b == -1)
	// 			{
	// 				s->data.ceil_b = ft_atoi(line);
	// 				while(*line >= '0' && *line <= '9')
	// 					line++;
	// 				if (!(*line >= '0' && *line <= '9') && *line != ' ' && *line != ',' && *line != '\0')
	// 					error_exit("Not a good format 12");
	// 			}
	// 			else
	// 				error_exit("Not a good format 13");
	// 		}
	// 		else if (*line != ' ' || *line != ',' || !(*line >= '0' && *line <= '9'))
	// 			error_exit("Not a good format 14");

	// 		line++;
	// 	}
	// 		printf("CEIL R = %d\n ", s->data.ceil_r);
	// 		printf("CEIL G = %d\n", s->data.ceil_g);
	// 		printf("CEIL B = %d\n", s->data.ceil_b);

	// }
}

void	parse_value(t_cub *s, char *line)
{
		if (line[s->index] == ' ')
			s->index++;
		if (line[s->index] == 'R' && line[s->index + 1] == ' ')
			parse_data_int(s, line);
		else if (line[s->index] == 'F' && line[s->index + 1] == ' ')
			parse_data_int(s, line);
		else if (line[s->index] == 'C' && line[s->index + 1] == ' ')
			parse_data_int(s, line);
		else if (line[s->index] == 'N' && line[s->index + 1] == 'O' && line[s->index + 2 == ' '])
			parse_data_int(s, line);
		else if (line[s->index] == 'S' && line[s->index + 1] == 'O' && line[s->index + 2 == ' '])
			parse_data_int(s, line);
		else if (line[s->index] == 'W' && line[s->index + 1] == 'E' && line[s->index + 2 == ' '])
			parse_data_int(s, line);
		else if (line[s->index] == 'E' && line[s->index + 1] == 'A' && line[s->index + 2 == ' '])
			parse_data_int(s, line);
		else if (line[s->index] == 'S' && line[s->index + 1] == ' ')
			parse_data_int(s, line);
		line++;
}

void	parse_data(t_cub *s, int fd)
{
	char	*line;
	int	r;

	r = get_next_line(fd, &line);
	while(r > 0)
	{
		s->index = 0;
		parse_value(s, line);
		free(line);
		r = get_next_line(fd, &line);
	}
	free(line);
}
