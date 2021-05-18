/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:49:08 by ketaouki          #+#    #+#             */
/*   Updated: 2021/03/23 08:42:59 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	start(char const *s1, char const *set)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (set[y])
	{
		while (s1[i] == set[y])
		{
			y = 0;
			i++;
		}
		y++;
	}
	return (i);
}

static int	end(char const *s1, char const *set)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (s1[i])
		i++;
	while (set[y])
	{
		while (i > 0 && s1[i - 1] == set[y])
		{
			y = 0;
			i--;
		}
		y++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		i;
	int		f;
	int		len;

	i = 0;
	f = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	len = end(s1, set) - start(s1, set);
	if (len < 0)
		return (ft_strdup(""));
	dest = malloc(sizeof(char) * (len + 1));
	if (!(dest))
		return (NULL);
	i = start(s1, set);
	while (s1[i] && i < end(s1, set))
		dest[f++] = s1[i++];
	dest[f] = '\0';
	return (dest);
}
