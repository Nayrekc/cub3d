/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 08:34:59 by ketaouki          #+#    #+#             */
/*   Updated: 2021/05/17 08:35:00 by ketaouki         ###   ########lyon.fr   */
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
				error_exit(s, line, "Error\nFormat x y");
		}
		else if (ft_isdigit(line[s->index]) == 0 && line[s->index] != ' ' )
			error_exit(s, line, "Error\nFormat x y");
	}
	parse_data_reso_max_min(s, line);
}

void	parse_data_reso_max_min(t_cub *s, char *line)
{
	if (s->data.resolution_x < 300)
		error_exit(s, line, "Error\nToo small");
	if (s->data.resolution_y < 300)
		error_exit(s, line, "Error\nToo small");
}
