/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:42:39 by ketaouki          #+#    #+#             */
/*   Updated: 2021/04/19 12:29:59 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char *s1, char *s2, char c)
{
	char	*dest;
	int		j;
	int		k;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	j = ft_strlen(s1) + ft_strlen(s2) + 1;
	k = 0;
	dest = malloc(sizeof(char) * j + 1);
	if (!(dest))
		return (NULL);
	j = 0;
	while (s1[j])
		dest[k++] = s1[j++];
	j = 0;
	dest[k++] = c;
	while (s2[j])
		dest[k++] = s2[j++];
	dest[k] = '\0';
	free(s1);
	return (dest);
}
