/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:24:14 by agarzon-          #+#    #+#             */
/*   Updated: 2020/01/27 15:51:37 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		deal_key(int key, t_mlx *tab)
{
	if (key == ESC)
		mlx_destroy_window(tab->mlx_ptr, tab->window);
	else if (key == A)
		mlx_string_put (tab->mlx_ptr, tab->window, 4, 4, 0x23BAC4, "INSERTAR MAPA");
//	ft_putnbr_fd(key, 1);
	return(0);
}

int		main(int argc, char **argv)
{
	t_mlx *tab; 
	int count_h;
	int count_w;
	int bpp;
	int size_l;
	int endian;

	count_h = -1;	
	tab = (t_mlx *)malloc(sizeof(t_mlx *));
	if (argc == 2 || (argc == 3 && argv))
	{
//		open(*argv, O_RDONLY);
		tab->mlx_ptr = mlx_init();
		tab->window = mlx_new_window(tab->mlx_ptr, X, Y, "cub3d");
		tab->image = mlx_xpm_to_image (tab->mlx_ptr, argv, (int *)100, (int *)100);
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
