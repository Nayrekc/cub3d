/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:36:32 by ketaouki          #+#    #+#             */
/*   Updated: 2021/04/12 15:08:19 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	parse_spawn_map(t_cub *s, char *line)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s->data.str[i])
	{
		if (s->data.str[i] == 'N' || s->data.str[i] == 'S'
			|| s->data.str[i] == 'W' || s->data.str[i] == 'E')
			count++;
		i++;
	}
	if (count == 0)
		error_exit(s, line, "Error\nNo Spawn\n");
	if (count > 1)
		error_exit(s, line, "Error\nDouble Spawn\n");
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
	s->data.map = ft_split(s->data.str, '\n');
	s->data.map_fill = ft_split(s->data.str, '\n');
}

void	spawn_map(t_cub *s)
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
			if (s->data.map[y][x] == 'N' || s->data.map[y][x] == 'S'
				|| s->data.map[y][x] == 'W' || s->data.map[y][x] == 'E')
			{
				s->data.spawn_x = x;
				s->data.spawn_y = y;
			}
			x++;
		}
		y++;
	}
}

void	fill_map_v(t_cub *s)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (s->data.map_fill[y])
	{
		x = 0;
		while (s->data.map_fill[y][x])
		{
			s->data.map_fill[y][x] = 'V';
			x++;
		}
		y++;
	}
}

int		ft_recursive_check(t_cub *s)
{
	int x;
	int y;

	x = s->data.spawn_x;
	y = s->data.spawn_y;
	s->data.map_fill[y][x] = s->data.map[y][x];
	if (s->data.map[y][x] == '1')
		return (0);
	if (s->data.map[y][x] == ' ')
		return (-1);
	if (s->data.map_fill[y + 1][x] == 'V')
	
		return(-1);

	return (0);
}
