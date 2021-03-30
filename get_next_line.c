/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 15:44:44 by ketaouki          #+#    #+#             */
/*   Updated: 2021/03/27 15:39:51 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_len_nl(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (i);
}

char	*ft_rec(char *str, char c)
{
	char	*rec;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != c && str[i])
		i++;
	if (str[i] == c && str[i])
	{
		while (str[i + j])
			j++;
		rec = ft_calloc(sizeof(char), j + 1);
		if (!(rec))
			return (NULL);
		j = 0;
		while (str[i])
			rec[j++] = str[i++];
		rec[j] = '\0';
		return (rec);
	}
	return (0);
}

int	the_line(char **line, char **save, char **next, int ret)
{
	*line = ft_substr(*save, 0, (ft_len_nl(*save, '\n')));
	*save = ft_substr(*next, 1, ft_strlen(*next));
	return (ret);
}

int	free_error(char **save, int ret)
{
	free(*save);
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*save;
	char		*next;
	int			r;

	r = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	if (save == NULL)
		if (!(save = ft_calloc(BUFFER_SIZE + 1, sizeof(char))))
			return (-1);
	while (!(next = ft_rec(save, '\n')))
	{
		if ((r = read(fd, buffer, BUFFER_SIZE)) == 0)
		{
			*line = ft_substr(save, 0, ft_strlen(save));
			save = NULL;
			return (0);
		}
		if (r == -1)
			return (free_error(&save, -1));
		buffer[r] = '\0';
		save = ft_strjoin(save, buffer);
	}
	return (the_line(line, &save, &next, 1));
}
