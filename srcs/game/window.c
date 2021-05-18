/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 09:16:38 by ketaouki          #+#    #+#             */
/*   Updated: 2021/05/17 08:10:05 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	size_screen(t_cub *s)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_get_screen_size(s->mlx, &x, &y);
	if (s->data.resolution_x > x)
		s->data.resolution_x = x;
	if (s->data.resolution_y > y)
		s->data.resolution_y = y;
	s->width = s->data.resolution_x;
	s->height = s->data.resolution_y;
}

void	window(t_cub *s)
{
	init_raycast_mlx(s);
	s->mlx = mlx_init();
	size_screen(s);
	s->win = mlx_new_window(s->mlx, s->width, s->height, "Cub3D");
	s->img = mlx_new_image(s->mlx, s->width, s->height);
	s->addr = (int *)mlx_get_data_addr(s->img, &s->bits_per_pixel,
			&s->line_length, &s->endian);
	raycast(s);
	mlx_hook(s->win, 2, 1L <<0, key_press, s);
	mlx_hook(s->win, 3, 1L <<0, key_release, s);
	mlx_hook(s->win, 17, 1L << 17, red_cross, s);
	mlx_loop_hook(s->mlx, raycast, s);
	mlx_loop(s->mlx);
}
