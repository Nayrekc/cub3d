/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 08:36:12 by ketaouki          #+#    #+#             */
/*   Updated: 2021/04/22 09:11:11 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	window(t_cub *s)
{
	s->window.mlx = mlx_init();
	s->window.win = mlx_new_window(s->window.mlx, s->data.resolution_x,
			s->data.resolution_y, "Cub3D");
	mlx_loop(s->window.mlx);
}
