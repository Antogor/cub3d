#include "../cub3d.h"

int		borderline(char **map, int x, int y)
{
	if ((map[x - 1][y] == '1' || map[x - 1][y] == '0' || map[x - 1][y] == '2')
		&& (map[x + 1][y] == '1'|| map[x + 1][y] == '0' || map[x + 1][y] == '2')
		&& (map[x][y - 1] == '1' || map[x][y - 1] == '0' ||
		map[x][y - 1] == '2') && (map[x][y + 1] == '1' ||
		map[x][y + 1] == '0' || map[x][y + 1] == '2'))
		return(1);
	else
		return(0);
}

int		is_a_close_map(char **map, int x, int y, int limit)
{
	int l;
	int q;

	if (map[x][y] == '0' || map[x][y] == '2' || map[x][y] == '1')
	{
		l = borderline(map, x, y);
		if(l == 0)
			ft_error("Not a valid map");
	}
	if (x < 0 || y < 0)
		return(1);
	if (x < limit)
		x += 1;
	else if (x == limit)
		x -= 1;
	else if (y < ft_strlen(map[x]))
		y += 1;
	else if (y == ft_strlen(map[x]))
		y -= 1;
	is_a_close_map(map, x, y, limit);
	return(1);
}
