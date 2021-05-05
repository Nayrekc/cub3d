/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 09:24:46 by ketaouki          #+#    #+#             */
/*   Updated: 2021/05/05 09:24:47 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_raycast_value(t_cub *s)
{
	s->player.position_x = s->data.spawn_x;
	s->player.position_y = s->data.spawn_y;
	s->width = s->data.resolution_x;
	s->height = s->data.resolution_y;
	s->player.direction_x = -1;
	s->player.cam_plane_y = 0.66;
	s->moveSpeed = 0.05;
	s->rotSpeed = 0.03;
}

void	init_raycast_mlx(t_cub *s)
{
	init_raycast_value(s);
}
