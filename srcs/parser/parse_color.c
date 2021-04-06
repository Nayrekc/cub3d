#include "../../includes/cub3d.h"

void	parse_data_floor(t_cub *s, char *line)
{
	(s->index)++;
	s->data.floor++;
	while (line[s->index])
	{
		while (line[s->index] == ' ')
			(s->index)++;
		if (ft_isdigit(line[s->index]) == 1)
			parse_data_color_floor(s, line);
		else if (ft_isdigit(line[s->index]) == 0 && line[s->index] != ' ')
			error_exit(s, line, "Error\nFormat <r, g, b>");
	}
	parse_data_color_add(s, 1, line);
}

void	parse_data_color_floor(t_cub *s, char *line)
{
	if (s->data.floor_r == -1)
	{
		s->data.floor_r = ft_atoi(s, line);
		if (!(line[s->index] == ','))
			error_exit(s, line, "Error\nFormat <r, g, b>");
		else
			s->index++;
	}
	else if (s->data.floor_g == -1)
	{
		s->data.floor_g = ft_atoi(s, line);
		if (!(line[s->index] == ','))
			error_exit(s, line, "Error\nFormat <r, g, b>");
		else
			s->index++;
	}
	else if (s->data.floor_b == -1)
		s->data.floor_b = ft_atoi(s, line);
	else
		error_exit(s, line, "Error\nFormat <r, g, b>");
}

void	parse_data_ceil(t_cub *s, char *line)
{
	(s->index)++;
	s->data.ceil++;
	while (line[s->index])
	{
		while (line[s->index] == ' ')
			(s->index)++;
		if (ft_isdigit(line[s->index]) == 1)
			parse_data_color_ceil(s, line);
		else if (ft_isdigit(line[s->index]) == 0 && line[s->index] != ' ')
			error_exit(s, line, "Error\nFormat <r, g, b>");
	}
	parse_data_color_add(s, 2, line);
}

void	parse_data_color_ceil(t_cub *s, char *line)
{
	if (s->data.ceil_r == -1)
	{
		s->data.ceil_r = ft_atoi(s, line);
		if (!(line[s->index] == ','))
			error_exit(s, line, "Error\nFormat <r, g, b>");
		else
			s->index++;
	}
	else if (s->data.ceil_g == -1)
	{
		s->data.ceil_g = ft_atoi(s, line);
		if (!(line[s->index] == ','))
			error_exit(s, line, "Error\nFormat <r, g, b>");
		else
			s->index++;
	}
	else if (s->data.ceil_b == -1)
		s->data.ceil_b = ft_atoi(s, line);
	else
		error_exit(s, line, "Error\nFormat <r, g, b>");
}

void	parse_data_color_add(t_cub *s, int state, char *line)
{
	if (state == 1)
	{
		if ((s->data.floor_r >= 0 && s->data.floor_r <= 255)
			&& (s->data.floor_g >= 0 && s->data.floor_g <= 255)
			&& (s->data.floor_b >= 0 && s->data.floor_b <= 255))
			s->data.floor_a = (256 * 256 * s->data.floor_r + 256
					* s->data.floor_g + s->data.floor_b);
		else
			error_exit(s, line, "Error\n RGB need to be >= 0 && <= 255");
	}
	if (state == 2)
	{
		if ((s->data.ceil_r >= 0 && s->data.ceil_r <= 255)
			&& (s->data.ceil_g >= 0 && s->data.ceil_g <= 255)
			&& (s->data.ceil_b >= 0 && s->data.ceil_b <= 255))
			s->data.ceil_a = (256 * 256 * s->data.ceil_r + 256
					* s->data.ceil_g + s->data.ceil_b);
		else
			error_exit(s, line, "Error\n RGB need to be >= 0 && <= 255");
	}
}
