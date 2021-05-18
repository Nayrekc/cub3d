/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 09:58:56 by ketaouki          #+#    #+#             */
/*   Updated: 2021/05/06 09:58:59 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_cam_right(t_cub *s)
{
	s->old_direction_x = s->player.direction_x;
	s->player.direction_x = s->player.direction_x * cos(-s->rotSpeed)
		- s->player.direction_y * sin(-s->rotSpeed);
	s->player.direction_y = s->old_direction_x * sin(-s->rotSpeed)
		+ s->player.direction_y * cos(-s->rotSpeed);
	s->old_plane_x = s->player.cam_plane_x;
	s->player.cam_plane_x = s->player.cam_plane_x * cos(-s->rotSpeed)
		- s->player.cam_plane_y * sin(-s->rotSpeed);
	s->player.cam_plane_y = s->old_plane_x * sin(-s->rotSpeed)
		+ s->player.cam_plane_y * cos(-s->rotSpeed);
}

void	move_cam_left(t_cub *s)
{
	s->old_direction_x = s->player.direction_x;
	s->player.direction_x = s->player.direction_x * cos(s->rotSpeed)
		- s->player.direction_y * sin(s->rotSpeed);
	s->player.direction_y = s->old_direction_x * sin(s->rotSpeed)
		+ s->player.direction_y * cos(s->rotSpeed);
	s->old_plane_x = s->player.cam_plane_x;
	s->player.cam_plane_x = s->player.cam_plane_x * cos(s->rotSpeed)
		- s->player.cam_plane_y * sin(s->rotSpeed);
	s->player.cam_plane_y = s->old_plane_x * sin(s->rotSpeed)
		+ s->player.cam_plane_y * cos(s->rotSpeed);
}
