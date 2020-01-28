/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:24:14 by agarzon-          #+#    #+#             */
/*   Updated: 2020/01/28 11:50:51 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		deal_key(int key, t_mlx *tab)
{
	if (key == ESC)
		exit(ESC);
	else if (key == A)
		mlx_string_put (tab->mlx_ptr, tab->window, 4, 4, 0x23BAC4, "INSERTAR MAPA");
//	ft_putnbr_fd(key, 1);
	return(0);
}

int		main(int argc, char **argv)
{
	t_mlx *tab; 
	int fd;
	char *a = NULL;
	int bwr;

	tab = (t_mlx *)malloc(sizeof(t_mlx *));
	if (argc == 2 || argc == 3)
	{
		fd = open(argv[1], O_RDONLY);
		bwr = read(fd, a, 100);
		printf("%s", a);
		tab->mlx_ptr = mlx_init();
		tab->window = mlx_new_window(tab->mlx_ptr, X, Y, "cub3d");
//		tab->image = mlx_xpm_to_image (tab->mlx_ptr, argv, (int *)100, (int *)100);
//		tab->image = mlx_new_image (tab->mlx_ptr, 100, 100);
//		tab->image_data = (int *)mlx_get_data_addr(tab->image, &bpp, &size_l, &endian);
//		mlx_put_image_to_window(tab->mlx_ptr, tab->window, *argv, 200, 200);
//		mlx_put_image_to_window(tab->mlx_ptr, tab->window, tab->image, 0, 0);
		mlx_key_hook(tab->window, deal_key, tab);
		mlx_loop(tab->mlx_ptr);
	}
	else
	{
		write(1, "Error\n", 6);
	}
	free(tab);
	tab = NULL;
	return (0);
}
