#include "cub3d.h"

int main (int argc, char **argv)
{
	int fd;
	int l;
	char *line;
	int *ancho = (int)640;
	int *alto = (int)360;

	fd = open(*argv, O_RDONLY);
	l = get_next_line(fd, &line);
	mlx_xpm_to_image(argv, argv, ancho, alto);
	printf("%d\n", l);
	printf("%s\n", line);

}