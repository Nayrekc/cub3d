/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:24:52 by ketaouki          #+#    #+#             */
/*   Updated: 2021/04/12 14:43:56 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	parse_type(t_cub *s, char *line)
{
	if (line[s->index] == '\0' && s->data.start_parse_map == 0)
		s->index++;
	else if (line[s->index] == 'R' && line[s->index + 1] == ' ')
		parse_data_reso(s, line);
	else if (line[s->index] == 'F' && line[s->index + 1] == ' ')
		parse_data_floor(s, line);
	else if (line[s->index] == 'C' && line[s->index + 1] == ' ')
		parse_data_ceil(s, line);
	else if (line[s->index] == 'N' && line[s->index + 1] == 'O'
		&& line[s->index + 2] == ' ')
		parse_data_path_no(s, line);
	else if (line[s->index] == 'S' && line[s->index + 1] == 'O'
		&& line[s->index + 2] == ' ')
		parse_data_path_so(s, line);
	else if (line[s->index] == 'W' && line[s->index + 1] == 'E'
		&& line[s->index + 2] == ' ')
		parse_data_path_we(s, line);
	else if (line[s->index] == 'E' && line[s->index + 1] == 'A'
		&& line[s->index + 2] == ' ')
		parse_data_path_ea(s, line);
	else if (line[s->index] == 'S' && line[s->index + 1] == ' ')
		parse_data_path_s(s, line);
	else if ((line[s->index] == ' ' || line[s->index] == '1'
			|| line[s->index] == '0') && data_full(s) == 1)
		parse_data_map(s, line);
	else
		error_exit(s, line, "Error\n");
}

void	parse_data(t_cub *s, int fd)
{
	char	*line;
	int		r;
	int i;
	int y;

	i = 0;
	y = 0;

	line = NULL;
	r = get_next_line(fd, &line);
	while (r > 0)
	{
		s->index = 0;
		parse_type(s, line);
		free(line);
		line = NULL;
		r = get_next_line(fd, &line);
	}
	free(line);
	line = NULL;
	parse_spawn_map(s, line);
	spawn_map(s);
	if (r == -1)
		error_exit(s, line, "Error\nReading .cub");

	while(s->data.map[i])
	{
		printf("%s\n", s->data.map[i]);
		i++;
	}
	printf("\n");
	fill_map_v(s);
	while(s->data.map_fill[y])
	{
		printf("%s\n", s->data.map_fill[y]);
		y++;
	}
	ft_recursive_check(s);
	printf("\n");
	y = 0;
	while(s->data.map_fill[y])
	{
		printf("%s\n", s->data.map_fill[y]);
		y++;
	}
	// printf("\n%s\n", s->data.texture_NO_path);
	// printf("\n%s\n", s->data.texture_SO_path);
	// printf("\n%s\n", s->data.texture_WE_path);
	// printf("\n%s\n", s->data.texture_EA_path);
	// printf("\n%s\n", s->data.texture_S_path);


	// printf("\n%d\n", s->data.resolution_x);
	// printf("\n%d\n", s->data.resolution_y);

	// printf("\n%d\n", s->data.floor_a);
	// printf("\n%d\n", s->data.ceil_a);

	// printf("\n%d\n", s->data.spawn_x);
	// printf("\n%d\n", s->data.spawn_y);
}


