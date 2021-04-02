#include "../../includes/cub3d.h"

int	ft_atoi(t_cub *s, const char *str)
{
	int		n;
	long	res;

	n = 1;
	res = 0;
	while (((str[s->index] >= 9 && str[s->index] <= 13) || str[s->index] == 32) && str[s->index])
		s->index++;
	if (str[s->index] == '-' || str[s->index] == '+')
	{
		if (str[s->index] == '-')
			n = -1;
		s->index++;
	}
	while ((str[s->index] >= '0' && str[s->index] <= '9') && str[s->index])
	{
		res = res * 10;
		res = res + (str[s->index] - '0');
		s->index++;
	}
	res = res * n;
	while (((str[s->index] >= 9 && str[s->index] <= 13) || str[s->index] == 32) && str[s->index])
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

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n >= 1)
	{
		while ((s1[i] && s2[i]) && i < (n - 1))
		{
			if (s1[i] != s2[i])
			{
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
			}
			i++;
		}
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	else
		return (0);
}


void	ft_putchar(char c)
{
	write(0, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;
	size_t	i;

	i = 0;
	tab = (char *)malloc(size * nmemb);
	if (!(tab))
		return (NULL);
	while (i < (size * nmemb))
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
