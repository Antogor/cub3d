#include "cub3d.h"

int	check_map(t_cub3d *cub3d)
{
	int l;
	char *comp;

	l = cub3d->map_w;
	comp = malloc(sizeof(char *) * l);
	comp[l--] = '\0';
	while (l > 0)
		comp[l--] = '1';
	comp[l] = '1';
	free(comp);
	return (1);
}
