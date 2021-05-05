/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 09:24:51 by ketaouki          #+#    #+#             */
/*   Updated: 2021/05/05 12:43:35 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_front(t_cub *s)
{
	int	x;
	int	y;

	x = s->player.position_x + s->player.direction_x * s->moveSpeed;
	y = s->player.position_y;
	if (s->data.map[y][x] != '|')
		s->player.position_x += s->player.direction_x * s->moveSpeed;
	y = s->player.position_y + s->player.direction_y * s->moveSpeed;
	x = s->player.position_x;
	if (s->data.map[y][x] != '|')
		s->player.position_y += s->player.direction_y * s->moveSpeed;
}

void	move_back(t_cub *s)
{
	int	x;
	int	y;

	x = s->player.position_x - s->player.direction_x * s->moveSpeed;
	y = s->player.position_y;
	if (s->data.map[y][x] != '|')
		s->player.position_x -= s->player.direction_x * s->moveSpeed;
	x = s->player.position_x;
	y = s->player.position_y - s->player.direction_y * s->moveSpeed;
	if (s->data.map[y][x] != '|')
		s->player.position_y -= s->player.direction_y * s->moveSpeed;
}

void	move_right(t_cub *s)
{
	int	x;
	int	y;

	x = s->player.position_x + s->player.direction_y * s->moveSpeed;
	y = s->player.position_y;
	if (s->data.map[y][x] != '|')
		s->player.position_x +=  s->player.direction_y * s->moveSpeed;
	y = s->player.position_y + s->player.direction_x * s->moveSpeed;
	x = s->player.position_x;
	if (s->data.map[y][x] != '|')
		s->player.position_y -= s->player.direction_x * s->moveSpeed;
}

void	move_left(t_cub *s)
{
	int	x;
	int	y;

	x = s->player.position_x - s->player.direction_y * s->moveSpeed;
	y = s->player.position_y;
	if (s->data.map[y][x] != '|')
		s->player.position_x -= s->player.direction_y * s->moveSpeed;
	y = s->player.position_y - s->player.direction_x * s->moveSpeed;
	x = s->player.position_x;
	if (s->data.map[y][x] != '|')
		s->player.position_y += s->player.direction_x * s->moveSpeed;
}

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

int	key_release(int key, t_cub *s)
{
	if (key == 126 || key == 13)
		s->key_up = 0;
	if (key == 125 || key == 1)
		s->key_down = 0;
	if (key == 124)
		s->arrow_right = 0;
	if (key == 123)
		s->arrow_left = 0;
	if (key == 2)
		s->key_right = 0;
	if (key == 0)
		s->key_left = 0;
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
	if (key == 126  || key == 13)
		s->key_up = 1;
	if (key == 125 || key == 1)
		s->key_down = 1;
	if (key == 2)
		s->key_right = 1;
	if (key == 0)
		s->key_left = 1;
	if (key == 124)
		s->arrow_right = 1;
	if (key == 123)
		s->arrow_left = 1;
	return (1);
}
