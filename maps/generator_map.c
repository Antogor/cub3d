#include <stdlib.h>
#include "../libft/libft.h"
#include <stdio.h>


void	generator_wall(char *map, int total, int columns, int fills)
{
	int l;
	int q;
	int count;

	l = 0;
	count = 0;
	while (l < total + fills)
	{
		if (map[l] == '\n')
		{
			break ;
		}
		map[l] = '1';
		l++;
	}
	l++;
	map[l] = '1';
	l++;
	while (l < total + fills)
	{
		q = 1;
		if (map[l + q]  == '\n')
		{
			map[l] = '1';
			l += 2;
			if (map[l + q] == '0')
				map[l] = '1';
			count++;
			if (count == fills - 1)
			{
				break ;
			}
		}
		l++;
	}
	printf("%s", map);
}

char	*premap(int total, int columns, int fills)
{
	char	*new;
	int		l;
	int		q;

	new = (char *)malloc(sizeof(char) * total + fills);
	l = 0;
	q = 0;
	while (l < total + fills)
	{
		new[l] = '0';
		if (q == columns)
		{
			new[l] = '\n';
			q = -1;
		}
		q++;
		l++;
	}
	new[l] = '\0';
	return (new);
}

int		main(int argc, char **argv)
{
	char	*map;
	int		fills;
	int		columns;
	int		total;
	int		l;

	fills = 0;
	columns = 0;
	if (argc == 4)
	{
		if (!(ft_strnstr(argv[1], ".cub", ft_strlen(argv[1]))))
			perror("Nombre no valido");
		l = 0;
		while (argv[2][l] >= '0' && argv[2][l] <= '9' )
		{
			columns = columns * 10 + (argv[2][l] - 48);
			l++;
		}      
		l = 0;
		while (argv[3][l] >= '0' && argv[3][l] <= '9')
		{
			fills = fills * 10 + (argv[3][l] - 48);
			l++;
		}
		if (fills > 0 && columns > 0)
		{
			total =  fills * columns;
			map = premap(total, columns, fills);
			generator_wall(map, total, columns, fills);
		}
	}
	return (0);
}
