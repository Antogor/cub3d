#include <stdlib.h>
#include "../libft/libft.h"
#include <stdio.h>

char	*generator_map(int columns, int fills)
{
	char	*new;
	int		total;
	int		l;
	int		q;

	total =  fills * columns;
	new = (char *)malloc(sizeof(char) * total + fills);
	l = 0;
	q = 0;
	while (l < total + fills)
	{
		new[l] = '1';
		if (l == columns)
			new[l] = '\n';
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
			map = generator_map(columns, fills);
		printf("%s", map);
	}
	return (0);
}
