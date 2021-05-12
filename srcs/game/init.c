/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 09:24:46 by ketaouki          #+#    #+#             */
/*   Updated: 2021/05/12 09:44:26 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_raycast_value(t_cub *s)
{
	s->player.position_x = s->data.spawn_x;
	s->player.position_y = s->data.spawn_y;
	s->player.direction_x = -1;
	s->player.cam_plane_y = -0.66;
	s->moveSpeed = 0.05;
	s->rotSpeed = 0.03;
}

void	initialize_dir_and_cam(t_cub *s)
{
	double	rotation;

	rotation = 0;
	if (s->data.map[s->data.spawn_y][s->data.spawn_x] == 'N')
		rotation = -1.58;
	if (s->data.map[s->data.spawn_y][s->data.spawn_x] == 'S')
		rotation = 1.58;
	if (s->data.map[s->data.spawn_y][s->data.spawn_x] == 'W')
		rotation = 0;
	if (s->data.map[s->data.spawn_y][s->data.spawn_x] == 'E')
		rotation = 3.14;
	s->old_direction_x = s->player.direction_x;
	s->player.direction_x = s->player.direction_x * cos(-rotation)
		- s->player.direction_y * sin(-rotation);
	s->player.direction_y = s->old_direction_x * sin(-rotation)
		+ s->player.direction_y * cos(-rotation);
	s->old_plane_x = s->player.cam_plane_x;
	s->player.cam_plane_x = s->player.cam_plane_x * cos(-rotation)
		- s->player.cam_plane_y * sin(-rotation);
	 s->player.cam_plane_y = s->old_plane_x * sin(-rotation)
		+ s->player.cam_plane_y * cos(-rotation);
}

void	init_raycast_mlx(t_cub *s)
{
	init_raycast_value(s);
	initialize_dir_and_cam(s);
}
