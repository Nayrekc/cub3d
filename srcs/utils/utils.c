/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:36:37 by ketaouki          #+#    #+#             */
/*   Updated: 2021/05/17 08:35:09 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_atoi(t_cub *s, const char *str)
{
	int		n;
	long	res;

	n = 1;
	res = 0;
	while (str[s->index] == 32 && str[s->index])
		s->index++;
	if (str[s->index] == '-' || str[s->index] == '+')
	{
		if (str[s->index] == '-')
			n = -1;
		s->index++;
	}
	while (ft_isdigit(str[s->index]) == 1 && str[s->index])
	{
		res = res * 10;
		res = res + (str[s->index] - '0');
		s->index++;
	}
	res = res * n;
	while (str[s->index] == 32 && str[s->index])
		s->index++;
	return (res);
}
