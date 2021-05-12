/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 08:56:05 by ketaouki          #+#    #+#             */
/*   Updated: 2021/05/12 09:13:15 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	lol(t_cub *s)
{
	while(s->sprite.i < s->sprite.nb_sprite)
	{
      //translate sprite position to relative to camera
		s->sprite.x = sprite[spriteOrder[i]].x - s->player.position_x;
		s->sprite.y = sprite[spriteOrder[i]].y - s->player.position_y;

		s->sprite.inv_det = 1.0 / (s->player.cam_plane_x * s->player.direction_y
			- s->player.direction_x * s->player.cam_plane_y);

		s->sprite.transform_x = s->sprite.inv_det * (s->player.direction_y
			* s->sprite.x - s->player.direction_x * s->sprite.y);
		s->sprite.transform_y = s->sprite.inv_det * (-s->player.cam_plane_y
			* s->sprite.x + s->player.cam_plane_x * s->sprite.y); //this is actually the depth inside the screen, that what Z is in 3D

		s->sprite.screen_x = (s->width / 2) *
			(1 + s->sprite.transform_x / s->sprite.transform_y);


		s->sprite.height = abs(int(s->height / (s->sprite.transform_y)));

		s->sprite.draw_start_y = -s->sprite.height / 2 + s->height / 2;
		if(s->sprite.draw_start_y < 0)
			s->sprite.draw_start_y = 0;
		s->sprite.draw_end_y = s->sprite.height / 2 + s->height / 2;
		if(s->sprite.draw_end_y >= s->height)
			s->sprite.draw_end_y = s->height - 1;

		s->sprite.width = abs (int (s->height / (s->sprite.transform_y)));
		s->sprite.draw_start_x = -s->sprite.width / 2 + s->sprite.screen_x;
		if(s->sprite.draw_start_x < 0)
			s->sprite.draw_start_x = 0;
		s->sprite.draw_end_x = s->sprite.width / 2 + s->sprite.screen_x;
		if(s->sprite.draw_end_x >= s->width)
			s->sprite.draw_end_x = s->width - 1;

		s->sprite.stripe = s->sprite.draw_start_x;
		while (s->sprite.stripe < s->sprite.draw_end_x)
		{
			int texX = int(256 * (s->sprite.stripe - (-s->sprite.width  / 2 + s->sprite.screen_x)) * texWidth / s->sprite.width ) / 256;

			if(s->sprite.transform_y > 0 && s->sprite.stripe > 0 && s->sprite.stripe < s->width && s->sprite.transform_y < ZBuffer[s->sprite.stripe])
			{
				while(s->sprite.draw_start_y < 	s->sprite.draw_end_y)
				{
					int d = (y) * 256 - s->height * 128 + s->sprite.height * 128; //256 and 128 factors to avoid floats
					int texY = ((d * texHeight) / s->sprite.height) / 256;
				}
			}
		s->sprite.stripe++;
		}
	}
    }
