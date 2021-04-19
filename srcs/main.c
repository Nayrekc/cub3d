/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:36:51 by ketaouki          #+#    #+#             */
/*   Updated: 2021/04/19 14:00:19 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_structure(t_cub *s)
{
	s->index = 0;
	s->data.resolution = 0;
	s->data.resolution_x = -1;
	s->data.resolution_y = -1;
	s->data.floor = 0;
	s->data.floor_r = -1;
	s->data.floor_g = -1;
	s->data.floor_b = -1;
	s->data.floor_a = 0;
	s->data.ceil = 0;
	s->data.ceil_r = -1;
	s->data.ceil_g = -1;
	s->data.ceil_b = -1;
	s->data.ceil_a = 0;
	s->data.texture_NO_path = NULL;
	s->data.texture_SO_path = NULL;
	s->data.texture_WE_path = NULL;
	s->data.texture_EA_path = NULL;
	s->data.texture_S_path = NULL;
	s->data.str = ft_calloc(1, sizeof(char));
	s->data.map = NULL;
	s->data.start_parse_map = 0;
	s->data.spawn_x = 0;
	s->data.spawn_y = 0;
}

int	main(int argc, char **argv)
{
	t_cub	s;
	int		y;

	y = 0;
	parse_argc(argc, argv);
	init_structure(&s);
	parse_file(&s, argv[1]);
	while (s.data.map[y])
	{
		printf("%s\n", s.data.map[y]);
		y++;
	}
	return (0);
}
