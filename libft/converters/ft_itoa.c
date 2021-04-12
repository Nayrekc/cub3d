/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:19:28 by ketaouki          #+#    #+#             */
/*   Updated: 2021/03/23 08:41:18 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	len(long int n)
{
	long int	i;

	i = 0;
	if (n < 0)
	{
		n = (n * -1);
		i = 1;
	}
	while (n > 9)
	{
		i++;
		n = (n / 10);
	}
	return (i + 1);
}

char	*ft_itoa(int n)
{
	char		*dest;
	long int	i;
	long int	nb;

	nb = (long int)n;
	i = len(nb);
	dest = malloc(sizeof(char) * i + 1);
	if (!(dest))
		return (NULL);
	dest[i] = '\0';
	i--;
	if (nb < 0)
	{
		dest[0] = '-';
		nb = nb * -1;
	}
	while (nb > 9)
	{
		dest[i] = ((nb % 10) + '0');
		nb = nb / 10;
		i--;
	}
	dest[i] = ((nb % 10) + '0');
	return (dest);
}
