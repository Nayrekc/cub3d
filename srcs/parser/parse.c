/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:05:29 by ketaouki          #+#    #+#             */
/*   Updated: 2021/05/17 08:06:57 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	data_full(t_cub *s)
{
	if (s->data.ceil == 1 && s->data.floor == 1 && s->data.resolution == 1
		&& s->data.texture_NO_path != NULL && s->data.texture_SO_path != NULL
		&& s->data.texture_WE_path != NULL && s->data.texture_EA_path != NULL
		&& s->data.texture_S_path != NULL)
		return (1);
	return (0);
}

void	parse_argc(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		error_exit_msg("Not a good format ./Cub3d <map.cub> (--save)\n");
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 7)
			|| ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 5))
			error_exit_msg("Not a good format ./Cub3d <map.cub> (--save)\n");
		if (!ft_strncmp(argv[2], "--save", 7))
			error_exit_msg("Not configured yet\n");
	}
	if (argc == 2)
	{
		if ((ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 5)))
			error_exit_msg("Not a good format ./Cub3d <map.cub> (--save)\n");
	}
}

void	parse_file(t_cub *s, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_exit_msg("Not a valid file");
	parse_data(s, fd);
}
