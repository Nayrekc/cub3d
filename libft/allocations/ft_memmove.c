/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:47:18 by ketaouki          #+#    #+#             */
/*   Updated: 2021/03/23 08:26:55 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, void *src, size_t n)
{
	size_t	i;
	char	*src1;
	char	*dest1;

	i = 0;
	src1 = (char *)src;
	dest1 = (char *)dest;
	if (dest1 == NULL && src1 == NULL)
		return (NULL);
	if (dest1 > src1)
	{
		while (n > 0)
		{
			n--;
			dest1[n] = src1[n];
		}
	}
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest1);
}
