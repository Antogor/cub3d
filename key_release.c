#include "cub3d.h"

int key_release(int key, t_cub3d *cub3d)
{
	if (key == W)
		cub3d->player->up = 0;
	else if (key == S)
		cub3d->player->down = 0;
/*	else if (key == D)
		cub3d->player->pos_x += cub3d->player->speed;
	else if (key == A)
		cub3d->player->pos_x -= cub3d->player->speed;*/
		return (0);
}