/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 09:16:38 by ketaouki          #+#    #+#             */
/*   Updated: 2021/05/05 09:28:05 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	window(t_cub *s)
{
	init_raycast_mlx(s);
	s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, s->width, s->height, "Cub3D");
	s->img = mlx_new_image(s->mlx, s->width, s->height);
	s->addr = (int *)mlx_get_data_addr(s->img, &s->bits_per_pixel,
			&s->line_length, &s->endian);
	raycast(s);
	mlx_hook(s->win, 2, 1L <<0, key_press, s);
	mlx_hook(s->win, 3, 1L <<0, key_release, s);
	mlx_loop_hook(s->mlx, raycast, s);
	mlx_loop(s->mlx);
}
