#include "../../includes/cub3d.h"

int	ft_atoi(t_cub *s, const char *str)
{
	int		n;
	long	res;

	n = 1;
	res = 0;
	while (str[s->index] == 32 && str[s->index])
		s->index++;
	if (str[s->index] == '-' || str[s->index] == '+')
	{
		if (str[s->index] == '-')
			n = -1;
		s->index++;
	}
	while (ft_isdigit(str[s->index]) == 1 && str[s->index])
	{
		res = res * 10;
		res = res + (str[s->index] - '0');
		s->index++;
	}
	res = res * n;
	while (str[s->index] == 32 && str[s->index])
		s->index++;
	return (res);
}

int	get_next_line(int fd, char **line)
{
	int		i;
	int		l;
	int		r;
	char	c;
	char	*tmp;

	r = 0;
	l = 1;
	if (!(*line = calloc(l, sizeof(char))))
		return (-1);
	*line[0] = 0;
	while ((r = read(fd, &c, 1)) && l++ && c != '\n')
	{
		if (!(tmp = malloc(l)))
		{
			free(*line);
			return (-1);
		}
		i = -1;
		while (++i < l - 2)
			tmp[i] = (*line)[i];
		tmp[i] = c;
		tmp[i + 1] = 0;
		free(*line);
		*line = tmp;
	}
	return (r);
}
