#include "cub3d.h"

int worldMap2[mapWidth][mapHeight]=
{
  1,1,1,1,1,1,1,1,1,1,
  1,0,0,0,0,0,0,0,0,1,
  1,0,0,0,0,0,0,0,0,1,
  1,0,0,0,0,0,0,0,0,1,
  1,0,0,0,0,0,0,0,0,1,
  1,0,0,0,0,0,0,0,0,1,
  1,0,0,0,0,0,0,0,0,1,
  1,0,0,0,0,0,0,0,0,1,
  1,0,0,0,0,0,0,0,0,1,
  1,1,1,1,1,1,1,1,1,1,
};

int	keys(int key, t_cub3d *cub3d)
{
	if (key == W)
	{
		if (worldMap2[(int)cub3d->player->pos_x][(int)(cub3d->player->pos_y + cub3d->player->dir_y * cub3d->player->speed)] == 0)
			cub3d->player->pos_y += cub3d->player->dir_y * cub3d->player->speed;
	}
		
	else if (key == S)
		cub3d->player->pos_y -= cub3d->player->speed;
	else if (key == D)
		cub3d->player->pos_x += cub3d->player->speed;
	else if (key == A)
		cub3d->player->pos_x -= cub3d->player->speed;
	
	return (0);
}
int	movement(t_cub3d *cub3d)
{
	cub3d->player->speed = 1.0;
	cub3d->player->pos_x = 5;
	cub3d->player->pos_y = 3;
	cub3d->player->dir_x = 0;
	cub3d->player->dir_y = -1;
	cub3d->player->plane_x = 0.66;
	cub3d->player->plane_y = 0;
	mlx_key_hook(cub3d->mlx->mlx_ptr, keys, cub3d);
}