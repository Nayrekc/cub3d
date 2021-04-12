/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_in_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 07:48:09 by ketaouki          #+#    #+#             */
/*   Updated: 2021/04/12 07:49:25 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_char_in_str(int c, char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
