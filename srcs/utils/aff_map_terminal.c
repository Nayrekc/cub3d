/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_map_terminal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:35:54 by ketaouki          #+#    #+#             */
/*   Updated: 2021/04/14 08:15:42 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	aff_player(int c)
{
	if (c == 'N')
		printf("\033[38;5;166m▲\033[0m");
	if (c == 'S')
		printf("\033[38;5;166m▼\033[0m");
	if (c == 'E')
		printf("\033[38;5;166m►\033[0m");
	if (c == 'W')
		printf("\033[38;5;166m◄\033[0m");
}

void	aff_map_utilis(char c)
{
	if (ft_char_in_str(c, " "))
		printf("\033[31m░\033[0m");
	else if (c == '|')
		printf("\033[34m█\033[0m");
	else if (c == '#')
		printf("\033[32m█\033[0m");
	else if (c == '.')
		printf("\033[38;5;128m┼\033[0m");
	else if (c == '$')
		printf("\033[33m☺\033[0m");
	else if (ft_char_in_str(c, "NSEW"))
		aff_player(c);
}

void	aff_map(t_cub *s)
{
	int	x;
	int	y;

	y = 0;
	while (s->data.map[y])
	{
		x = 0;
		while (s->data.map[y][x])
		{
			aff_map_utilis(s->data.map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}
