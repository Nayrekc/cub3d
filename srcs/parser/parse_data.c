/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:24:52 by ketaouki          #+#    #+#             */
/*   Updated: 2021/04/05 13:53:45 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
				error_exit("Error\nFormat x y");
		}
		else if (ft_isdigit(line[s->index]) == 0 && line[s->index] != ' ' )
			error_exit("Error\nFormat x y");
	}
	if (s->data.resolution_x > 5120 && s->data.resolution_y > 2880)
	{
		s->data.resolution_x = 5120;
		s->data.resolution_y = 2880;
	}
}

void	parse_data_floor(t_cub *s, char *line)
{
	(s->index)++;
	s->data.floor++;
	while (line[s->index])
	{
		while (line[s->index] == ' ')
			(s->index)++;
		if (ft_isdigit(line[s->index]) == 1)
		{
			if (s->data.floor_r == -1)
			{
				s->data.floor_r = ft_atoi(s, line);
				if (!(line[s->index] == ','))
					error_exit("Error\nFormat <r, g, b>");
				else
					s->index++;
			}
			else if (s->data.floor_g == -1)
			{
				s->data.floor_g = ft_atoi(s, line);
				if (!(line[s->index] == ','))
					error_exit("Error\nFormat <r, g, b>");
				else
					s->index++;
			}
			else if (s->data.floor_b == -1)
				s->data.floor_b = ft_atoi(s, line);
			else
				error_exit("Error\nFormat <r, g, b>");
		}
		else if (ft_isdigit(line[s->index]) == 0 && line[s->index] != ' ')
			error_exit("Error\nFormat <r, g, b>");
	}
	parse_data_color(s, 1);
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
		{
			if (s->data.ceil_r == -1)
			{
				s->data.ceil_r = ft_atoi(s, line);
				if (!(line[s->index] == ','))
					error_exit("Error\nFormat <r, g, b>");
				else
					s->index++;
			}
			else if (s->data.ceil_g == -1)
			{
				s->data.ceil_g = ft_atoi(s, line);
				if (!(line[s->index] == ','))
					error_exit("Error\nFormat <r, g, b>");
				else
					s->index++;
			}
			else if (s->data.ceil_b == -1)
				s->data.ceil_b = ft_atoi(s, line);
			else
				error_exit("Error\nFormat <r, g, b>");
		}
		else if (ft_isdigit(line[s->index]) == 0 && line[s->index] != ' ')
			error_exit("Error\nFormat <r, g, b>");
	}
	parse_data_color(s, 2);
}

void	parse_data_color(t_cub *s, int state)
{
	if (state == 1)
	{
		if ((s->data.floor_r >= 0 && s->data.floor_r <= 255)
			&& (s->data.floor_g >= 0 && s->data.floor_g <= 255)
			&& (s->data.floor_b >= 0 && s->data.floor_b <= 255))
			s->data.floor_a = (256 * 256 * s->data.floor_r + 256
					* s->data.floor_g + s->data.floor_b);
		else
			error_exit("Error\n RGB need to be >= 0 && <= 255");
	}
	if (state == 2)
	{
		if ((s->data.ceil_r >= 0 && s->data.ceil_r <= 255)
			&& (s->data.ceil_g >= 0 && s->data.ceil_g <= 255)
			&& (s->data.ceil_b >= 0 && s->data.ceil_b <= 255))
			s->data.ceil_a = (256 * 256 * s->data.ceil_r + 256
					* s->data.ceil_g + s->data.ceil_b);
		else
			error_exit("Error\n RGB need to be >= 0 && <= 255");
	}
}

void	parse_data_path_no(t_cub *s, char *line)
{
	s->index = s->index + 2;
	while (line[s->index] == ' ')
		s->index++;
	if (ft_strncmp(line + ft_strlen(line) - 4, ".xpm", 5) == 0)
		s->data.texture_NO_path = ft_substr(line, s->index, ft_strlen(line));
	else
		error_exit("Error\nWrong Format use <.xpm>");
}

void	parse_value(t_cub *s, char *line)
{
	if (line[s->index] == ' ' || line[s->index] == '\n')
		s->index++;
	else if (line[s->index] == 'R')
		parse_data_reso(s, line);
	else if (line[s->index] == 'F')
		parse_data_floor(s, line);
	else if (line[s->index] == 'C')
		parse_data_ceil(s, line);
	else if (line[s->index] == 'N' && line[s->index + 1] == 'O')
		parse_data_path_no(s, line);
	// else if (line[s->index] == 'S' && line[s->index + 1] == 'O')
	// 	parse_data_path_no(s, line);
	// else if (line[s->index] == 'W' && line[s->index + 1] == 'E')
	// 	parse_data_path_no(s, line);
	// else if (line[s->index] == 'E' && line[s->index + 1] == 'A')
	// 	parse_data_path_no(s, line);
	// else if (line[s->index] == 'S' && line[s->index + 1] == ' ')
	// 	parse_data_path_no(s, line);
	// if ((line[s->index] == ' ' || line[s->index] == 0
	// 	|| line[s->index] == 1))
	// 	printf("lol");
	// 	//parse_map(s, line);
	// else
	// 	error_exit("Error\n");
}

void	parse_data(t_cub *s, int fd)
{
	char	*line;
	int		r;

	line = NULL;
	r = get_next_line(fd, &line);
	while (r > 0)
	{
		s->index = 0;
		parse_value(s, line);
		line = NULL;
		free(line);
		r = get_next_line(fd, &line);
	}
	free(line);
}
