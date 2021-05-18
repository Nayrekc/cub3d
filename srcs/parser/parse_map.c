/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:36:32 by ketaouki          #+#    #+#             */
/*   Updated: 2021/05/17 08:53:06 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	spawn_map(t_cub *s, char *line)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	x = 0;
	count = 0;
	while (s->data.map[y])
	{
		x = 0;
		while (s->data.map[y][x])
		{
			if (s->data.map[y][x] == 'N' || s->data.map[y][x] == 'S'
				|| s->data.map[y][x] == 'W' || s->data.map[y][x] == 'E')
			{
				count++;
				s->data.spawn_x = x;
				s->data.spawn_y = y;
			}
			x++;
		}
		y++;
	}
	if (count == 0 || count > 1)
		error_exit(s, line, "Error\nIn the map format\n");
}

void	clean_map(t_cub *s)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (s->data.map[y])
	{
		x = 0;
		while (s->data.map[y][x])
		{
			if (s->data.map[y][x] == '1' || s->data.map[y][x] == '0'
				|| s->data.map[y][x] == '2')
				s->data.map[y][x] = ' ';
			x++;
		}
		y++;
	}
}

void	ft_check_map(t_cub *s, char *line, int y, int x)
{
	if (x < 0 || y < 0 || x >= (int)ft_strlen(s->data.map[y])
		|| s->data.map[y][x] == ' ')
		error_exit(s, line, "Error\nIn the map format\n");
	if (ft_char_in_str(s->data.map[y][x], ".$|" ))
		return ;
	if (s->data.map[y][x] == '0')
		s->data.map[y][x] = '.';
	if (s->data.map[y][x] == '1')
	{
		s->data.map[y][x] = '|';
		return ;
	}
	if (s->data.map[y][x] == '2')
	{
		s->data.map[y][x] = '$';
		s->data.nb_sprite++;
	}
	ft_check_map(s, line, y + 1, x);
	ft_check_map(s, line, y - 1, x);
	ft_check_map(s, line, y, x - 1);
	ft_check_map(s, line, y, x + 1);
}

void	parse_data_map(t_cub *s, char *line)
{
	s->data.start_parse_map = 1;
	while (line[s->index])
	{
		if (ft_char_in_str(line[s->index], " 012NSWE") == 1)
			s->index++;
		else
			error_exit(s, line, "Error\nWrong char in map\n");
	}
	s->data.str = ft_strjoin(s->data.str, line, '\n');
}
