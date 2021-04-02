#include "../../includes/cub3d.h"

void	parse_data_int(t_cub *s, char *line)
{
	if(line[s->index] == 'R')
	{
		(s->index)++;
		while(line[s->index])
		{
			while (line[s->index] == ' ')
				(s->index)++;
			if (line[s->index] >= '0' && line[s->index] <= '9')
			{
				if (s->data.resolution_x == 0)
				{
					s->data.resolution_x = ft_atoi(s, line);
					if (!(line[s->index] >= '0' && line[s->index] <= '9') && line[s->index] != ' ')
						error_exit("Error\nFormat x");
				}
				else if(s->data.resolution_y == 0)
				{
					s->data.resolution_y = ft_atoi(s, line);
					if (!(line[s->index] >= '0' && line[s->index] <= '9') && line[s->index] != ' ' && line[s->index] != '\0')
						error_exit("Error\nFormat y");
				}
				else
					error_exit("Error\nFormat x y");
			}
			else if (!(line[s->index] >= '0' && line[s->index] <= '9') && line[s->index] != ' ' )
				error_exit("Error\nChar1");
		}
		if (s->data.resolution_x > 0 && s->data.resolution_y > 0)
			s->data.resolution++;
		printf("RESO = %d %d\n", s->data.resolution_x, s->data.resolution_y);
	}

	if(line[s->index] == 'F')
	{
		(s->index)++;
		while(line[s->index])
		{
			while (line[s->index] == ' ')
				(s->index)++;
			if ((line[s->index] >= '0' && line[s->index] <= '9'))
			{
				if (s->data.floor_r == -1)
				{
					s->data.floor_r = ft_atoi(s, line);
					if (!(line[s->index] == ','))
						error_exit("Error\nFormat comma");
					if (!(line[s->index] >= '0' && line[s->index] <= '9') && line[s->index] != ' ' && line[s->index] != ',')
						error_exit("Error\nFormat floor_r");
				}
				else if(s->data.floor_g == -1)
				{
					s->data.floor_g = ft_atoi(s, line);
					if (!(line[s->index] == ','))
						error_exit("Error\nFormat comma");
					if (!(line[s->index] >= '0' && line[s->index] <= '9') && line[s->index] != ' ' && line[s->index] != ',')
						error_exit("Error\nFormat floor_g");
				}
				else if(s->data.floor_b == -1)
				{
					s->data.floor_b = ft_atoi(s, line);
					if (!(line[s->index] >= '0' && line[s->index] <= '9') && line[s->index] != ' ' && line[s->index] != '\0')
						error_exit("Error\nFormat floor_b");
				}
				else
						error_exit("Error\nFormat");
			}
			else if (!(line[s->index] >= '0' && line[s->index] <= '9') && line[s->index] != ' ')
			{
					printf("\n%s\n", &line[s->index]);
						error_exit("Error\nChar2");
			}
			s->index++;
		}
		if (s->data.floor_r >= 0 && s->data.floor_g >= 0 && s->data.floor_b >= 0)
			s->data.floor++;
		printf("FLOOR R = %d G = %d B = %d\n", s->data.floor_r, s->data.floor_g, s->data.floor_b);
	}

	if(line[s->index] == 'C')
	{
		(s->index)++;
		while(line[s->index])
		{
			while (line[s->index] == ' ')
				(s->index)++;
			if ((line[s->index] >= '0' && line[s->index] <= '9'))
			{
				if (s->data.ceil_r == -1)
				{
					s->data.ceil_r = ft_atoi(s, line);
					if (!(line[s->index] == ','))
						error_exit("Error\nFormat comma");
					if (!(line[s->index] >= '0' && line[s->index] <= '9') && line[s->index] != ' ' && line[s->index] != ',')
						error_exit("Error\nFormat ceil_r");
				}
				else if(s->data.ceil_g == -1)
				{
					s->data.ceil_g = ft_atoi(s, line);
					if (!(line[s->index] == ','))
						error_exit("Error\nFormat comma");
					if (!(line[s->index] >= '0' && line[s->index] <= '9') && line[s->index] != ' ' && line[s->index] != ',')
						error_exit("Error\nFormat ceil_g");
				}
				else if(s->data.ceil_b == -1)
				{
					s->data.ceil_b = ft_atoi(s, line);
					if (!(line[s->index] >= '0' && line[s->index] <= '9') && line[s->index] != ' ' && line[s->index] != '\0')
						error_exit("Error\nFormat ceil_b");
				}
				else
					error_exit("Error\nFormat");
			}
			else if (!(line[s->index] >= '0' && line[s->index] <= '9') && line[s->index] != ' ')
				error_exit("Error\nChar3");
			s->index++;
		}
		if (s->data.ceil_r >= 0 && s->data.ceil_g >= 0 && s->data.ceil_b >= 0)
			s->data.ceil++;
		printf("CEIL R = %d G = %d B = %d\n", s->data.ceil_r, s->data.ceil_g, s->data.ceil_b);
	}
}

void	parse_value(t_cub *s, char *line)
{
		if (line[s->index] == 'R' && line[s->index + 1] == ' ')
			parse_data_int(s, line);
		else if (line[s->index] == 'F' && line[s->index + 1] == ' ')
			parse_data_int(s, line);
		else if (line[s->index] == 'C' && line[s->index + 1] == ' ')
			parse_data_int(s, line);
		// else if (line[s->index] == 'N' && line[s->index + 1] == 'O' && line[s->index + 2 == ' '])
		// 	parse_data_int(s, line);
		// else if (line[s->index] == 'S' && line[s->index + 1] == 'O' && line[s->index + 2 == ' '])
		// 	parse_data_int(s, line);
		// else if (line[s->index] == 'W' && line[s->index + 1] == 'E' && line[s->index + 2 == ' '])
		// 	parse_data_int(s, line);
		// else if (line[s->index] == 'E' && line[s->index + 1] == 'A' && line[s->index + 2 == ' '])
		// 	parse_data_int(s, line);
		// else if (line[s->index] == 'S' && line[s->index + 1] == ' ')
		//	parse_data_int(s, line);
}

void	parse_data(t_cub *s, int fd)
{
	char	*line;
	int	r;

	line = NULL;
	r = get_next_line(fd, &line);
	while(r > 0)
	{
		s->index = 0;
		parse_value(s, line);
		line = NULL;
		free(line);
		r = get_next_line(fd, &line);
	}
	free(line);
}
