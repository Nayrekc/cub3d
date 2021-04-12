#include "../../includes/cub3d.h"

void	error_exit(t_cub *s, char *line, char *str)
{
	printf("%s", str);
	if (line != NULL)
		free(line);
	if (s->data.texture_NO_path != NULL)
		free(s->data.texture_NO_path);
	if (s->data.texture_SO_path != NULL)
		free(s->data.texture_SO_path);
	if (s->data.texture_WE_path != NULL)
		free(s->data.texture_WE_path);
	if (s->data.texture_EA_path != NULL)
		free(s->data.texture_EA_path);
	if (s->data.texture_S_path != NULL)
		free(s->data.texture_S_path);
	// if (s->data.str != NULL ||)
	// 	free(s->data.str);
	if (s->data.map != NULL)
		free(s->data.map);
	exit (0);
}

void	error_exit_msg(char *str)
{
	printf("%s", str);
	exit (0);
}
