/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:39:25 by ketaouki          #+#    #+#             */
/*   Updated: 2021/04/22 10:44:17 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	gnl_ft_strcpy(char *line, char *buffer, int len, int save)
{
	int	i;

	i = 0;
	while (i < len)
	{
		line[i] = buffer[save + i];
		buffer[save + i] = 0;
		i++;
	}
	buffer[save + i] = 0;
	line[i] = '\0';
}

int	gnl_ft_strlen(char *buffer, int save)
{
	int	len;

	len = 0;
	while (buffer[len + save] && buffer[len + save] != '\n')
		len++;
	return (len);
}

char	*gnl_ft_strjoin(char *line, char *buffer, int len, int save)
{
	int		i;
	int		j;
	int		ret_len;
	char	*ret;

	i = 0;
	j = 0;
	ret_len = gnl_ft_strlen(line, 0) + len;
	ret = (char *)malloc(sizeof(char) * (ret_len + 1));
	if (!ret)
		return (NULL);
	while (line[j])
		ret[i++] = line[j++];
	j = 0;
	while (buffer[save + j] && buffer[save + j] != '\n')
	{
		ret[i] = buffer[save + j];
		buffer[save + j] = 0;
		i++;
		j++;
	}
	buffer[save + j] = 0;
	ret[i] = 0;
	free(line);
	return (ret);
}
