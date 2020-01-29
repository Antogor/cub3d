/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:24:14 by agarzon-          #+#    #+#             */
/*   Updated: 2020/01/29 16:52:56 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		deal_key(int key, t_mlx *tab)
{
	if (key == ESC)
		exit(ESC);
	else if (key == A)
	{
		mlx_pixel_put(tab->mlx_ptr, tab->window, 300, 600, 0x23BAC4);
	}
	return(0);
}

int 	ft_print(int button, int x, int y, t_mlx *tab)
{
	(void)tab;
	(void)button;
	printf("posX: %d, posY: %d\n", x, y);
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx *tab;
	int fd;
	char *map;
	int gnl;
	int x;
	int y;

	x = 0;
	y = 0;
	tab = (t_mlx *)malloc(sizeof(t_mlx *));
	if (argc == 2 || argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 6) == 0)
			printf("save");
		if (ft_strncmp(argv[1], ".cub", 100) > 0)
			printf("save2");
		fd = open(argv[1], O_RDONLY);
		gnl = get_next_line(fd, &map);
		x = ft_atoi(&map[2]);
		y = ft_atoi(&map[6]);
	}
	else
		perror("No map");
/*	tab->mlx_ptr = mlx_init();
	tab->window = mlx_new_window(tab->mlx_ptr, x, y, "cub3d");
	mlx_xpm_to_image (tab->mlx_ptr, &argv[1], (int *)100, (int *)50);
	mlx_key_hook(tab->window, deal_key, tab);
	mlx_mouse_hook(tab->window, ft_print, tab);
	mlx_loop(tab->mlx_ptr);*/
	free(tab);
	tab = NULL;
	return (0);
}
