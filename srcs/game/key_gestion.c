/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_gestion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 09:57:44 by ketaouki          #+#    #+#             */
/*   Updated: 2021/05/11 11:10:52 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	red_cross(t_cub *s)
{
	clean_exit(s);
	return (1);
}

int	key_release(int key, t_cub *s)
{
	if (key == 126 || key == 13)
		s->key_up = 0;
	if (key == 125 || key == 1)
		s->key_down = 0;
	if (key == 124)
		s->arrow_left = 0;
	if (key == 123)
		s->arrow_right = 0;
	if (key == 2)
		s->key_left = 0;
	if (key == 0)
		s->key_right = 0;
	return (1);
}

void	check_move(t_cub *s)
{
	if (s->key_up)
		move_front(s);
	if (s->key_down)
		move_back(s);
	if (s->arrow_right)
		move_cam_right(s);
	if (s->arrow_left)
		move_cam_left(s);
	if (s->key_right)
		move_right(s);
	if (s->key_left)
		move_left(s);
}

int	key_press(int key, t_cub *s)
{
	if (key == 53)
		clean_exit(s);
	if (key == 49)
	{
		s->player.position_x = s->data.spawn_x;
		s->player.position_y = s->data.spawn_y;
	}
	if (key == 126 || key == 13)
		s->key_up = 1;
	if (key == 125 || key == 1)
		s->key_down = 1;
	if (key == 2)
		s->key_left = 1;
	if (key == 0)
		s->key_right = 1;
	if (key == 124)
		s->arrow_left = 1;
	if (key == 123)
		s->arrow_right = 1;
	return (1);
}
