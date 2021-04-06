#include "../../includes/cub3d.h"

int	data_full(t_cub *s)
{
	if (s->data.ceil == 1 && s->data.floor == 1 && s->data.resolution == 1
		&& s->data.texture_NO == 1 && s->data.texture_SO == 1
		&& s->data.texture_WE == 1 && s->data.texture_EA == 1
		&& s->data.texture_S == 1)
		return (1);
	return (0);
}

void	parse_argc(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		error_exit_msg("Not a good format .Cub3d (--save) <map.cub>\n");
	if (argc == 3)
	{
		if (ft_strncmp(argv[1], "--save", 7)
			|| ft_strncmp(argv[2] + ft_strlen(argv[2]) - 4, ".cub", 5))
			error_exit_msg("Not a good format .Cub3d (--save) <map.cub>\n");
		if (!ft_strncmp(argv[1], "--save", 7))
			error_exit_msg("Not configured yet\n");
	}
	if (argc == 2)
	{
		if ((ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 5)))
			error_exit_msg("Not a good format .Cub3d (--save) <map.cub>\n");
	}
}

void	parse_file(t_cub *s, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_exit_msg("Not a valid file");
	parse_data(s, fd);
}
