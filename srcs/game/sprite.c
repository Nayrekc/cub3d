/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 08:56:05 by ketaouki          #+#    #+#             */
/*   Updated: 2021/05/12 12:35:59 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	sprite_calcul(t_cub *s, int i)
{
	s->sprite.x = s->sprite_x_y[s->sprite.order[i]].x - s->player.position_x;
	s->sprite.y = s->sprite_x_y[s->sprite.order[i]].y - s->player.position_y;
	s->sprite.inv_det = 1.0 / (s->player.cam_plane_x * s->player.direction_y
		 - s->player.direction_x * s->player.cam_plane_y);
	s->sprite.transform_x = s->sprite.inv_det * (s->player.direction_y 
		* s->sprite.x - s->player.direction_x * s->sprite.y);
	s->sprite.transform_y = s->sprite.inv_det * (-s->player.cam_plane_y 
		* s->sprite.x + s->player.cam_plane_x * s->sprite.y);
	s->sprite.screen_x = (int)((s->width / 2) * (1 + s->sprite.transform_x 
		/ s->sprite.transform_y));
	s->sprite.height = abs((int)(s->height / (s->sprite.transform_y)));
	s->sprite.draw_start_y = -s->sprite.height / 2 + s->height / 2;
	sprite_calcul_2(s);
}

void	sprite_calcul_2(t_cub *s)
{
	if (s->sprite.draw_start_y < 0)
		s->sprite.draw_start_y = 0;
	s->sprite.draw_end_y = s->sprite.height / 2 + s->height / 2;
	if (s->sprite.draw_end_y >= s->height)
		s->sprite.draw_end_y = s->height -1;
	s->sprite.width = abs ((int)(s->height / (s->sprite.transform_y)));
	s->sprite.draw_start_x = -s->sprite.width / 2 + s->sprite.screen_x;
	if (s->sprite.draw_start_x < 0)
		s->sprite.draw_start_x = 0;
	s->sprite.draw_end_x = s->sprite.width / 2 + s->sprite.screen_x;
	if (s->sprite.draw_end_x >= s->width)
		s->sprite.draw_end_x = s->width -1;
}

void	sprite_aff_2(t_cub *s)
{
	int d;
	int y;

	y = s->sprite.draw_start_y;
	while(y < s->sprite.draw_end_y)
	{
		d = y * 256 - s->height * 128 + s->sprite.height * 128;
		s->sprite.text_y = ((d * s->t_sprite.texture_height) 
			/ s->sprite.height) / 256;
		if (s->t_sprite.addr[s->sprite.text_y * s->t_sprite.line_length 
			/ 4 + s->sprite.text_x] != 0)
		s->addr[y * s->line_length / 4 + s->sprite.stripe] 
			= s->t_sprite.addr[s->sprite.text_y * s->t_sprite.line_length 
				/ 4 + s->sprite.text_x];
		y++;		
	}
}

void	sprite_aff(t_cub *s)
{
	s->sprite.stripe = s->sprite.draw_start_x ;
	while (s->sprite.stripe < s->sprite.draw_end_x)
	{		
		s->sprite.text_x = (int)(256 * (s->sprite.stripe - (-s->sprite.width
			/ 2 + s->sprite.screen_x)) * s->t_sprite.texture_width 
				/ s->sprite.width ) / 256;
		if (s->sprite.transform_y > 0 && s->sprite.stripe >= 0 && 
			s->sprite.stripe < s->width && 
			s->sprite.transform_y < s->sprite.buffer[s->sprite.stripe])
			sprite_aff_2(s);
		s->sprite.stripe++;	
	}
}

void	sprite(t_cub *s)
{
	int i;

	i = 0;
	sprite_dist(s);
	while(i < s->data.nb_sprite)
	{
		sprite_calcul(s, i);
		sprite_aff(s);
		i++;
	}
}
