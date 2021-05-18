/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:10:09 by ketaouki          #+#    #+#             */
/*   Updated: 2021/05/17 13:10:09 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_wall_pos(t_cub *s)
{
	if (s->raycast.side == 1)
	{
		if (s->raycast.map_y > s->player.position_y)
			s->t = s->t_so;
		if (s->raycast.map_y < s->player.position_y)
			s->t = s->t_no;
	}
	else
	{
		if (s->raycast.map_x > s->player.position_x)
			s->t = s->t_ea;
		if (s->raycast.map_x < s->player.position_x)
			s->t = s->t_we;
	}
}

void	draw_wall(t_cub *s)
{
	if (s->raycast.side == 0)
		s->te.wall_x = s->player.position_y + s->raycast.wall_dist
			* s->raycast.raydir_y;
	else
		s->te.wall_x = s->player.position_x + s->raycast.wall_dist
			* s->raycast.raydir_x;
	s->te.wall_x -= floor((s->te.wall_x));
	s->te.tex_x = (int)(s->te.wall_x * s->t.texture_width);
	if (s->raycast.side == 0 && s->raycast.raydir_x > 0)
		s->te.tex_x = s->t.texture_width - s->te.tex_x - 1;
	if (s->raycast.side == 1 && s->raycast.raydir_y < 0)
		s->te.tex_x = s->t.texture_width - s->te.tex_x - 1;
	s->te.step = 1.0 * s->t.texture_height / s->raycast.line_height;
	s->te.position = (s->raycast.draw_start - s->height / 2
			+ s->raycast.line_height / 2) * s->te.step;
	s->te.tex_x = s->t.line_length / 4 - s->te.tex_x - 1;
	while (s->raycast.draw_start < s->raycast.draw_end)
	{
		s->te.tex_y = (int)s->te.position & (s->t.texture_height - 1);
		s->te.position += s->te.step;
		s->addr[s->raycast.draw_start * s->line_length / 4 + s->raycast.x]
			= s->t.addr[s->te.tex_y * (s->t.line_length / 4) + s->te.tex_x];
		s->raycast.draw_start++;
	}
}

void	draw_raycast(t_cub *s)
{
	int	i;

	i = 0;
	while (i < s->raycast.draw_start)
	{
		s->addr[i * s->line_length / 4 + s->raycast.x] = s->data.ceil_a;
		i++;
	}
	draw_wall(s);
	i = s->raycast.draw_end;
	while (i < s->height)
	{
		s->addr[i * s->line_length / 4 + s->raycast.x] = s->data.floor_a;
		i++;
	}
}
