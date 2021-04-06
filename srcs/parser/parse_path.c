#include "../../includes/cub3d.h"

void	parse_data_path_no(t_cub *s, char *line)
{
	int	fd_open;

	s->index = s->index + 2;
	s->data.texture_NO++;
	if (s->data.texture_NO_path != NULL)
		error_exit(s, line, "Already has a texture");
	while (line[s->index] == ' ')
		s->index++;
	fd_open = open(&line[s->index], O_RDONLY);
	if (fd_open == -1)
		error_exit(s, line, "error\n");
	close(fd_open);
	s->data.texture_NO_path = ft_strdup(&line[s->index]);
}

void	parse_data_path_so(t_cub *s, char *line)
{
	int	fd_open;

	s->index = s->index + 2;
	s->data.texture_SO++;
	if (s->data.texture_SO_path != NULL)
		error_exit(s, line, "Already has a texture");
	while (line[s->index] == ' ')
		s->index++;
	fd_open = open(&line[s->index], O_RDONLY);
	if (fd_open == -1)
		error_exit(s, line, "error\n");
	close(fd_open);
	s->data.texture_SO_path = ft_strdup(&line[s->index]);
}

void	parse_data_path_we(t_cub *s, char *line)
{
	int	fd_open;

	s->index = s->index + 2;
	s->data.texture_WE++;
	if (s->data.texture_WE_path != NULL)
		error_exit(s, line, "Already has a texture");
	while (line[s->index] == ' ')
		s->index++;
	fd_open = open(&line[s->index], O_RDONLY);
	if (fd_open == -1)
		error_exit(s, line, "error\n");
	close(fd_open);
	s->data.texture_WE_path = ft_strdup(&line[s->index]);
}

void	parse_data_path_ea(t_cub *s, char *line)
{
	int	fd_open;

	s->index = s->index + 2;
	s->data.texture_EA++;
	if (s->data.texture_EA_path != NULL)
		error_exit(s, line, "Already has a texture");
	while (line[s->index] == ' ')
		s->index++;
	fd_open = open(&line[s->index], O_RDONLY);
	if (fd_open == -1)
		error_exit(s, line, "error\n");
	close(fd_open);
	s->data.texture_EA_path = ft_strdup(&line[s->index]);
}

void	parse_data_path_s(t_cub *s, char *line)
{
	int	fd_open;

	s->index++;
	s->data.texture_S++;
	if (s->data.texture_S_path != NULL)
		error_exit(s, line, "Already has a texture");
	while (line[s->index] == ' ')
		s->index++;
	fd_open = open(&line[s->index], O_RDONLY);
	if (fd_open == -1)
		error_exit(s, line, "error\n");
	close(fd_open);
	s->data.texture_S_path = ft_strdup(&line[s->index]);
}
