#include "../../includes/cub3d.h"

void	move_front(t_cub *s)
{
	int x;
	int y;

	x = s->player.position_x + s->player.direction_x * s->moveSpeed;
	y = s->player.position_y;
	if(s->data.map[y][x] != '|')
		s->player.position_x += s->player.direction_x * s->moveSpeed;
	y = s->player.position_y + s->player.direction_y * s->moveSpeed;
	x = s->player.position_x;
	if(s->data.map[y][x] != '|')
		s->player.position_y += s->player.direction_y * s->moveSpeed;
}

void	move_back(t_cub *s)
{
	int x;
	int y;

	x = s->player.position_x - s->player.direction_x * s->moveSpeed;
	y = s->player.position_y;
	if(s->data.map[y][x] != '|')
		s->player.position_x -= s->player.direction_x * s->moveSpeed;
	x = s->player.position_x;
	y = s->player.position_y - s->player.direction_y * s->moveSpeed;
	if(s->data.map[y][x] != '|')
			s->player.position_y -= s->player.direction_y * s->moveSpeed;
}

void	move_right(t_cub *s)
{
	s->old_direction_x = s->player.direction_x;
	s->player.direction_x = s->player.direction_x * cos(-s->rotSpeed) - s->player.direction_y * sin(-s->rotSpeed);
	s->player.direction_y = s->old_direction_x * sin(-s->rotSpeed) + s->player.direction_y * cos(-s->rotSpeed);
	s->old_plane_x = s->player.cam_plane_x;
	s->player.cam_plane_x = s->player.cam_plane_x * cos(-s->rotSpeed) - s->player.cam_plane_y * sin(-s->rotSpeed);
	s->player.cam_plane_y = s->old_plane_x * sin(-s->rotSpeed) + s->player.cam_plane_y * cos(-s->rotSpeed);
}

void	move_left(t_cub *s)
{
	s->old_direction_x = s->player.direction_x;
	s->player.direction_x = s->player.direction_x * cos(s->rotSpeed) - s->player.direction_y * sin(s->rotSpeed);
	s->player.direction_y = s->old_direction_x * sin(s->rotSpeed) + s->player.direction_y * cos(s->rotSpeed);
	s->old_plane_x = s->player.cam_plane_x;
	s->player.cam_plane_x = s->player.cam_plane_x * cos(s->rotSpeed) - s->player.cam_plane_y * sin(s->rotSpeed);
	s->player.cam_plane_y = s->old_plane_x * sin(s->rotSpeed) + s->player.cam_plane_y * cos(s->rotSpeed);

}

int key_release(int key, t_cub *s)
{
	if(key == 126)
		s->key_up = 0;
	if(key == 125)
		s->key_down = 0;
	if(key == 124)
		s->arrow_right = 0;
	if(key == 123)
		s->arrow_left = 0;
	return (1);
}

void	check_move(t_cub *s)
{
	if(s->key_up)
		move_front(s);
	if(s->key_down)
		move_back(s);
	if(s->arrow_right)
		move_right(s);
	if(s->arrow_left)
		move_left(s);
}

int	key_press(int key, t_cub *s)
{

	if(key == 126)
		s->key_up = 1;
	if(key == 125)
		s->key_down = 1;
	if(key == 124)
		s->arrow_right = 1;
	if(key == 123)
		s->arrow_left = 1;
	return (1);
}
