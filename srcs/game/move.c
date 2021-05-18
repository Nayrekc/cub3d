/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 09:24:51 by ketaouki          #+#    #+#             */
/*   Updated: 2021/05/06 09:58:49 by ketaouki         ###   ########lyon.fr   */
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
		s->player.position_x += s->player.direction_y * s->moveSpeed;
	y = s->player.position_y - s->player.direction_x * s->moveSpeed;
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
	y = s->player.position_y + s->player.direction_x * s->moveSpeed;
	x = s->player.position_x;
	if (s->data.map[y][x] != '|')
		s->player.position_y += s->player.direction_x * s->moveSpeed;
}
