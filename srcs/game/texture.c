/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:26:01 by ketaouki          #+#    #+#             */
/*   Updated: 2021/05/11 13:52:46 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cub3d.h"

void init_texture_NO(t_cub *s)
{
	s->t_no.img = mlx_xpm_file_to_image(s->mlx, s->data.texture_NO_path,
			&s->t_no.texture_width, &s->t_no.texture_height);
	s->t_no.addr = (int *)mlx_get_data_addr(s->t_no.img, &s->bits_per_pixel,
			&s->t_no.line_length, &s->t_no.endian);
}

void	init_texture_SO(t_cub *s)
{
	s->t_so.img = mlx_xpm_file_to_image(s->mlx, s->data.texture_SO_path,
			&s->t_so.texture_width, &s->t_so.texture_height);
	s->t_so.addr = (int *)mlx_get_data_addr(s->t_so.img, &s->bits_per_pixel,
			&s->t_so.line_length, &s->t_so.endian);
}

void	init_texture_WE(t_cub *s)
{
	s->t_we.img = mlx_xpm_file_to_image(s->mlx, s->data.texture_WE_path,
			&s->t_we.texture_width, &s->t_we.texture_height);
	s->t_we.addr = (int *)mlx_get_data_addr(s->t_we.img, &s->bits_per_pixel,
			&s->t_we.line_length, &s->t_we.endian);
}

void	init_texture_EA(t_cub *s)
{
	s->t_ea.img = mlx_xpm_file_to_image(s->mlx, s->data.texture_EA_path,
			&s->t_ea.texture_width, &s->t_ea.texture_height);
	s->t_ea.addr = (int *)mlx_get_data_addr(s->t_ea.img, &s->bits_per_pixel,
			&s->t_ea.line_length, &s->t_ea.endian);
}

void	init_texture(t_cub *s)
{
	init_texture_EA(s);
	init_texture_WE(s);
	init_texture_NO(s);
	init_texture_SO(s);
}

void	check_dir(t_cub *s)
{
	if (s->raycast.side == 1)
	{
		if (s->raycast.map_y > s->player.position_y)
			s->t = s->t_so;
		if (s->raycast.map_y < s->player.position_y)
			s->t = s->t_no;
	}
	else
	{
		if (s->raycast.map_x > s->player.position_x)
			s->t = s->t_ea;
		if (s->raycast.map_x < s->player.position_x)
			s->t = s->t_we;
	}
}
