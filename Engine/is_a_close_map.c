#include "../cub3d.h"

int		is_a_close_map(char **map, int x, int y, int limit)
{
	if (map[x][y] == 32 || map[x][y] == 9 || map[x][y] == 0)
		ft_error("Not a valid map");
	if (map[x][y] == '1' || map[x][y] == '8' || map[x][y] == '4')
		return (1);
	if ((x <= 0) || !map[x][y] || (y <= 0) || (x == limit))
		ft_error("Not a valid map");
	if (map[x][y] == '0')
		map[x][y] = '8';
	if (map[x][y] == '2')
		map[x][y] = '4';
	is_a_close_map(map, x + 1, y, limit);
	is_a_close_map(map, x - 1, y, limit);
	is_a_close_map(map, x, y + 1, limit);
	is_a_close_map(map, x, y - 1, limit);
	return(1);
}
