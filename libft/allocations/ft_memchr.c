/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:21:07 by ketaouki          #+#    #+#             */
/*   Updated: 2021/03/23 08:26:50 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *dest, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest1;

	i = 0;
	dest1 = (unsigned char *)dest;
	while (i < n)
	{
		if (dest1[i] == (unsigned char)c)
			return (dest1 + i);
		i++;
	}
	return (0);
}
