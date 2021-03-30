/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 15:43:19 by ketaouki          #+#    #+#             */
/*   Updated: 2021/03/27 15:12:54 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;
	size_t	i;

	i = 0;
	tab = (char *)malloc(size * nmemb);
	if (!(tab))
		return (0);
	while (i < (size * nmemb))
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		j;
	int		k;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	j = ft_strlen(s1) + ft_strlen(s2);
	k = 0;
	dest = malloc(sizeof(char) * j + 1);
	if (!(dest))
	{
		free(s1);
		return (NULL);
	}
	j = 0;
	while (s1[j])
		dest[k++] = s1[j++];
	j = 0;
	while (s2[j])
		dest[k++] = s2[j++];
	dest[k] = '\0';
	free(s1);
	s1 = NULL;
	return (dest);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		len = 0;
	s2 = malloc(sizeof(char) * (len + 1));
	if (!(s2))
	{
		free(s);
		return (NULL);
	}
	if (start < ft_strlen(s))
	{
		while (i < len)
			s2[i++] = s[start++];
	}
	s2[i] = '\0';
	free(s);
	s = NULL;
	return (s2);
}
