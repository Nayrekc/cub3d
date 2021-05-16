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

void	init_sprite_2(t_cub *s)
{
	int y;
	int x;
	int i;

	y = 0;
	x = 0;
	i = 0;
	if(!(s->sprite.order = (int *)ft_calloc(s->data.nb_sprite, sizeof(int))))
		clean_exit(s);
	if(!(s->sprite_x_y = (t_sprite *)ft_calloc(s->data.nb_sprite, sizeof(t_sprite))))
		clean_exit(s);
	if(!(s->sprite.dist = (double *)ft_calloc(s->data.nb_sprite, sizeof(t_sprite))))
		clean_exit(s);
	while(s->data.map[y])
	{
		x = 0;
		while(s->data.map[y][x])
		{
			if (s->data.map[y][x] == '$')
			{
				s->sprite_x_y[i].x = (double)x + 0.5;
				s->sprite_x_y[i].y = (double)y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	sprite_order(t_cub *s)
{
	int		i;
	int		j;
	double	tmp;

	i = 0;
	while (i < s->data.nb_sprite)
	{
		s->sprite.order[i] = i;
		s->sprite.dist[i] = ((s->player.position_x - s->sprite_x_y[i].x) *
				(s->player.position_x - s->sprite_x_y[i].x) + (s->player.position_y -
					s->sprite_x_y[i].y) * (s->player.position_y - s->sprite_x_y[i].y));
		i++;
	}
	i = 0;
	while (i < s->data.nb_sprite)
	{
		j = 0;
		while(j < s->data.nb_sprite)
		{
			if (s->sprite.dist[j] < s->sprite.dist[j + 1])
			{
				tmp = s->sprite.dist[j];
				s->sprite.dist[j] = s->sprite.dist[j + 1];
				s->sprite.dist[j + 1] = tmp;
				tmp = s->sprite.order[j];
				s->sprite.order[j] = s->sprite.order[j + 1];
				s->sprite.order[j + 1] = (int)tmp;
			}
			j++;
		}
		i++;	
	}
}

void	sprite_calcul(t_cub *s, int i)
{
	s->sprite.x = s->sprite_x_y[s->sprite.order[i]].x - s->player.position_x;
	s->sprite.y = s->sprite_x_y[s->sprite.order[i]].y - s->player.position_y;
	s->sprite.inv_det = 1.0 / (s->player.cam_plane_x * s->player.direction_y - s->player.direction_x * s->player.cam_plane_y);
	s->sprite.transform_x = s->sprite.inv_det * (s->player.direction_y * s->sprite.x - s->player.direction_x * s->sprite.y);
	s->sprite.transform_y = s->sprite.inv_det * (-s->player.cam_plane_y * s->sprite.x + s->player.cam_plane_x * s->sprite.y);
	s->sprite.screen_x = (int)((s->width / 2) * (1 + s->sprite.transform_x / s->sprite.transform_y));
	s->sprite.height = abs((int)(s->height / (s->sprite.transform_y)));
	s->sprite.draw_start_y = -s->sprite.height / 2 + s->height / 2;
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


void	sprite(t_cub *s)
{
	int i;
	int d;
	int y;

	i = 0;
	sprite_order(s);
	while(i < s->data.nb_sprite)
	{
		sprite_calcul(s, i);
		s->sprite.stripe = s->sprite.draw_start_x;
		while (s->sprite.stripe < s->sprite.draw_end_x)
		{		
			s->sprite.text_x = (int)(256 * (s->sprite.stripe - (-s->sprite.width  / 2 + s->sprite.screen_x)) * s->t_sprite.texture_width / s->sprite.width ) / 256;
			if (s->sprite.transform_y > 0 && s->sprite.stripe >= 0 && s->sprite.stripe < s->width && s->sprite.transform_y < s->sprite.buffer[s->sprite.stripe])
			{
				y = s->sprite.draw_start_y;
				while(y < s->sprite.draw_end_y)
				{
					d = y * 256 - s->height * 128 + s->sprite.height * 128;
					s->sprite.text_y = ((d * s->t_sprite.texture_height) / s->sprite.height) / 256;
					if (s->t_sprite.addr[s->sprite.text_y * s->t_sprite.line_length / 4 + s->sprite.text_x] != 0)
						s->addr[y * s->line_length / 4 + s->sprite.stripe] = s->t_sprite.addr[s->sprite.text_y * s->t_sprite.line_length / 4 + s->sprite.text_x];
					y++;
				}
			}
			s->sprite.stripe++;
		}
		i++;
	}
}
