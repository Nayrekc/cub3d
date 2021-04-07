/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:24:52 by ketaouki          #+#    #+#             */
/*   Updated: 2021/04/07 11:24:55 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	parse_type(t_cub *s, char *line)
{
	if (line[s->index] == '\0')
		s->index++;
	else if (line[s->index] == 'R' && line[s->index + 1] == ' ')
		parse_data_reso(s, line);
	else if (line[s->index] == 'F' && line[s->index + 1] == ' ')
		parse_data_floor(s, line);
	else if (line[s->index] == 'C' && line[s->index + 1] == ' ')
		parse_data_ceil(s, line);
	else if (line[s->index] == 'N' && line[s->index + 1] == 'O' && line[s->index + 2] == ' ')
		parse_data_path_no(s, line);
	else if (line[s->index] == 'S' && line[s->index + 1] == 'O' && line[s->index + 2] == ' ')
		parse_data_path_so(s, line);
	else if (line[s->index] == 'W' && line[s->index + 1] == 'E' && line[s->index + 2] == ' ')
		parse_data_path_we(s, line);
	else if (line[s->index] == 'E' && line[s->index + 1] == 'A' && line[s->index + 2] == ' ')
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

	line = NULL;
	r = get_next_line(fd, &line);
	while (r > 0)
	{
		s->index = 0;
		parse_type(s, line);
		line = NULL;
		free(line);
		r = get_next_line(fd, &line);
	}
	free(line);
	printf("%s", s->data.str);
	if (r == - 1)
		error_exit(s, line, "Error\nReading .cub");
}
