#include "../cub3d.h"

void	close_game(t_cub3d *cub3d)
{
	int l;

	l = 0;
	if (cub3d->map)
	{
		while (cub3d->map[l])
		{
			free(cub3d->map[l]);
			l++;
		}
		free(cub3d->map);
	}
	free(cub3d->player);
	free(cub3d->mlx);
	free(cub3d->raycast);
	free(cub3d->color);
	free(cub3d->text);
	free(cub3d);
	exit(EXIT_SUCCESS);
}
