#include "cub3d.h"

int	map_data(t_cub3d *cub3d)
{

	return(1);
}

int	check_map(t_cub3d *cub3d)
{
	int l;
	int	q;

	l = 0;
	q = 1;
	while (l < cub3d->map_w)
	{
		if (cub3d->map[0][l] != '1' || cub3d->map[cub3d->map_h - 1][l] != '1')
			return (0);
		l++;
	}
	while (q < cub3d->map_h - 1)
	{
		if (cub3d->map[q][0] != '1' || cub3d->map[q][cub3d->map_w - 1] != '1')
			return (0);
		q++;
	}
	return (map_data(cub3d));
}
