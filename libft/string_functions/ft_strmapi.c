/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:46:27 by ketaouki          #+#    #+#             */
/*   Updated: 2021/03/23 08:42:47 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*final;

	if (s == NULL || f == NULL)
		return (NULL);
	i = ft_strlen(s);
	final = malloc(sizeof(char) * (i + 1));
	if (!(final))
		return (NULL);
	i = 0;
	while (s[i])
	{
		final[i] = s[i];
		final[i] = (*f)(i, final[i]);
		i++;
	}
	final[i++] = '\0';
	return (final);
}
