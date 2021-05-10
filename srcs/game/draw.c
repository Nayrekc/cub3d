/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:10:09 by ketaouki          #+#    #+#             */
/*   Updated: 2021/05/10 13:29:47 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_wall(t_cub *s)
{
	if(s->raycast.side == 0)
		s->t.wall_x = s->player.position_y + s->raycast.wall_dist * s->raycast.raydir_y;
	else
		s->t.wall_x = s->player.position_x + s->raycast.wall_dist * s->raycast.raydir_x;
	s->t.wall_x -= floor((s->t.wall_x));
	s->t.texture_x = (int)(s->t.wall_x * s->t.texture_width);
	if(s->raycast.side == 0 && s->raycast.raydir_x > 0)
		s->t.texture_x = s->t.texture_width - s->t.texture_x - 1;
	if(s->raycast.side == 1 && s->raycast.raydir_y < 0)
		s->t.texture_x = s->t.texture_width - s->t.texture_x - 1;
	s->t.step = 1.0 * s->t.texture_height / s->raycast.line_height;
	s->t.texture_position = (s->raycast.draw_start - s->height / 2 + s->raycast.line_height / 2) * s->t.step;
	while (s->raycast.draw_start < s->raycast.draw_end)
	{
		s->t.texture_y = (int)s->t.texture_position & (s->t.texture_height - 1);
		s->t.texture_position += s->t.step;
		s->addr[s->raycast.draw_start * s->line_length / 4 + s->raycast.x] = s->t.addr[s->t.texture_height];
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
	// while (i < s->raycast.draw_end)
	// {
	// 	s->addr[i * s->line_length / 4 + s->raycast.x] = 0x00FFFFFF;
	// 	i++;
	// }
	draw_wall(s);
	i = s->raycast.draw_end;
	while (i < s->height)
	{
		s->addr[i * s->line_length / 4 + s->raycast.x] = s->data.floor_a;
		i++;
	}
}
