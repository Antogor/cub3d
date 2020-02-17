#include "cub3d.h"

int worldMap2[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,1},
  {1,0,0,1,0,0,0,0,0,1},
  {1,1,1,1,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1},
};

int	keys(t_cub3d *cub3d)
{
	if (cub3d->player->up)
	{
		if (!(worldMap2[(int)cub3d->player->pos_x][(int)cub3d->player->pos_y]))
			cub3d->player->pos_y += cub3d->player->dir_y * cub3d->player->speed;
	}
		
	/*else if (key == S)
		cub3d->player->pos_y -= cub3d->player->speed;
	else if (key == D)
		cub3d->player->pos_x += cub3d->player->speed;
	else if (key == A)
		cub3d->player->pos_x -= cub3d->player->speed;*/
	
	return (0);
}
int	movement(t_cub3d *cub3d)
{
	
	cub3d->player->speed = 1.0;
	if (cub3d->player->up)
	{
		if (!(worldMap2[(int)cub3d->player->pos_x][(int)cub3d->player->pos_y]))
			cub3d->player->pos_y += cub3d->player->dir_y * cub3d->player->speed;
	}
	mlx_key_hook(cub3d->mlx->window, keys, cub3d);
	return (0);
}