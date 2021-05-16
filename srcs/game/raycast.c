/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 07:45:14 by ketaouki          #+#    #+#             */
/*   Updated: 2021/05/12 09:28:52 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_raycast(t_cub *s)
{
	s->raycast.camera_x = 2 * s->raycast.x / (double)s->width - 1;
	s->raycast.raydir_x = s->player.direction_x + s->player.cam_plane_x
		* s->raycast.camera_x;
	s->raycast.raydir_y = s->player.direction_y + s->player.cam_plane_y
		* s->raycast.camera_x;
	s->raycast.map_x = s->player.position_x;
	s->raycast.map_y = s->player.position_y;
	s->raycast.deltadist_x = fabs(1 / s->raycast.raydir_x);
	s->raycast.deltadist_y = fabs(1 / s->raycast.raydir_y);
	s->raycast.hit = 0;
}

void	step_raycast(t_cub *s)
{
	if (s->raycast.raydir_x < 0)
	{
		s->raycast.step_x = -1;
		s->raycast.sidedist_x = (s->player.position_x - s->raycast.map_x)
			* s->raycast.deltadist_x;
	}
	else
	{
		s->raycast.step_x = 1;
		s->raycast.sidedist_x = (s->raycast.map_x + 1.0 - s->player.position_x)
			* s->raycast.deltadist_x;
	}
	if (s->raycast.raydir_y < 0)
	{
		s->raycast.step_y = -1;
		s->raycast.sidedist_y = (s->player.position_y - s->raycast.map_y)
			* s->raycast.deltadist_y;
	}
	else
	{
		s->raycast.step_y = 1;
		s->raycast.sidedist_y = (s->raycast.map_y + 1.0 - s->player.position_y)
			* s->raycast.deltadist_y;
	}
}

void	hit_raycast(t_cub *s)
{
	while (!s->raycast.hit)
	{
		if (s->raycast.sidedist_x < s->raycast.sidedist_y)
		{
			s->raycast.sidedist_x += s->raycast.deltadist_x;
			s->raycast.map_x += s->raycast.step_x;
			s->raycast.side = 0;
		}
		else
		{
			s->raycast.sidedist_y += s->raycast.deltadist_y;
			s->raycast.map_y += s->raycast.step_y;
			s->raycast.side = 1;
		}
		if (s->data.map[s->raycast.map_y][s->raycast.map_x] == '|')
			s->raycast.hit = 1;
	}
}

void	sky_floor_raycast(t_cub *s)
{
	if (s->raycast.side == 0)
		s->raycast.wall_dist = (s->raycast.map_x - s->player.position_x
				+ (1 - s->raycast.step_x) / 2) / s->raycast.raydir_x;
	else
		s->raycast.wall_dist = (s->raycast.map_y - s->player.position_y
				+ (1 - s->raycast.step_y) / 2) / s->raycast.raydir_y;
	s->raycast.line_height = (int)(s->height / s->raycast.wall_dist);
	s->raycast.draw_start = -s->raycast.line_height / 2 + s->height / 2;
	if (s->raycast.draw_start < 0)
		s->raycast.draw_start = 0;
	s->raycast.draw_end = s->raycast.line_height / 2 + s->height / 2;
	if (s->raycast.draw_end >= s->height)
		s->raycast.draw_end = s->height - 1;
}

int	raycast(t_cub *s)
{
	check_move(s);
	s->raycast.x = 0;
	init_texture(s);
	s->sprite.buffer = (double *)malloc(sizeof(double) * s->width);
	while (s->raycast.x < s->width)
	{
		init_raycast(s);
		step_raycast(s);
		hit_raycast(s);
		sky_floor_raycast(s);
		check_wall_pos(s);
		draw_raycast(s);
		s->sprite.buffer[s->raycast.x] = s->raycast.wall_dist;
		s->raycast.x++;
	}
	sprite(s);
	mlx_clear_window(s->mlx, s->win);
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	mlx_do_sync(s->mlx);
	free(s->sprite.buffer);
	free(s->sprite.dist);
	free(s->sprite_x_y);
	free(s->sprite.order);
	return (1);
}
