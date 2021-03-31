#include "../../includes/cub3d.h"

int	parse_argc(int argc, char **argv)
{
	if (argc < 2 || argc >3)
	{
		printf("Not a good format .Cub3d (--save) <map.cub>\n");
		return(1);
	}
	if(argc == 3)
	{
		if (ft_strncmp(argv[1], "--save", 7)
			|| ft_strncmp(argv[2] + ft_strlen(argv[2]) - 4, ".cub", 5))
		{
			printf("Not a good format .Cub3d (--save) <map.cub>\n");
			return(1);
		}
		if (!ft_strncmp(argv[1], "--save", 7))
		{
			printf("Not configured yet\n");
			return (1);
		}
	}
	if(argc == 2)
	{
		if((ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 5)))
		{
			printf("Not a good format .Cub3d (--save) <map.cub>\n");
			return (1);
		}
	}
	return (0);
}

void parse_file(t_cub *s, char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	parse_data(s, fd);
}
