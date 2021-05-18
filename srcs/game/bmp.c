/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:34:46 by ketaouki          #+#    #+#             */
/*   Updated: 2021/05/18 07:21:17 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	header(t_cub *s, unsigned char **screen, int size)
{
	(*screen)[0] = (unsigned char)('B');
	(*screen)[1] = (unsigned char)('M');
	(*screen)[2] = (unsigned char)(size);
	(*screen)[3] = (unsigned char)(size >> 8);
	(*screen)[4] = (unsigned char)(size >> 16);
	(*screen)[5] = (unsigned char)(size >> 24);
	(*screen)[10] = (unsigned char)(54);
	(*screen)[0 + 14] = (unsigned char)(40);
	(*screen)[4 + 14] = (unsigned char)(s->width >> 0);
	(*screen)[5 + 14] = (unsigned char)(s->width >> 8);
	(*screen)[6 + 14] = (unsigned char)(s->width >> 16);
	(*screen)[7 + 14] = (unsigned char)(s->width >> 24);
	(*screen)[8 + 14] = (unsigned char)(s->height >> 0);
	(*screen)[9 + 14] = (unsigned char)(s->height >> 8);
	(*screen)[10 + 14] = (unsigned char)(s->height >> 16);
	(*screen)[11 + 14] = (unsigned char)(s->height >> 24);
	(*screen)[12 + 14] = (unsigned char)(1);
	(*screen)[14 + 14] = (unsigned char)(s->bits_per_pixel);
}

void	img(t_cub *s, unsigned char **screen)
{
	int	x;
	int	y;
	int	j;

	j = 54;
	y = s->height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < s->width)
		{
			(*screen)[j++] = (s->addr[y * s->line_length / 4 + x]);
			(*screen)[j++] = (s->addr[y * s->line_length / 4 + x] >> 8);
			(*screen)[j++] = (s->addr[y * s->line_length / 4 + x] >> 16);
			(*screen)[j++] = (s->addr[y * s->line_length / 4 + x] >> 24);
			x++;
		}
		y--;
	}
}

void	bmp(t_cub *s)
{
	int				fd;
	unsigned char	*screen;
	int				size;

	size = 54 + 4 * s->height * s->width;
	screen = ft_calloc(size, sizeof(unsigned char));
	if (screen == NULL)
		clean_exit(s);
	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0700);
	header(s, &screen, size);
	img(s, &screen);
	write(fd, screen, size);
	free(screen);
	clean_exit(s);
}
