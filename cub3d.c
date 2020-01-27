/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:24:14 by agarzon-          #+#    #+#             */
/*   Updated: 2020/01/27 12:21:04 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		deal_key(int key, t_mlx *tab)
{
	if (key == 53)
		mlx_string_put (tab->mlx_ptr, tab->window, 50, 300, 0x23BAC4, "CTHULHU");
	else if (key == 0)
		mlx_string_put (tab->mlx_ptr, tab->window, 100, 200, 0x23BAC4, "PRINTF");
	else if (key == 13)
		mlx_xpm_file_to_image (tab->mlx_ptr, "./cthulhu", (int *)50, (int *)50);
//	ft_putnbr_fd(key, 1);
//	param = 0;
	return(0);
}
int		main()
{
	t_mlx *tab;
/*	int bpp;
	int size_line;
	int endian;*/

	tab = (t_mlx *)malloc(sizeof(t_mlx *));
	tab->mlx_ptr = mlx_init();
	tab->window = mlx_new_window(tab->mlx_ptr, 1920, 1080, "cub3d");
	
	tab->image = mlx_new_image(tab->mlx_ptr, 5, 5);
//	tab->image_data = mlx_get_data_addr(tab->image, &bpp, &size_line, &endian);
/*	tab->image_data[40] = 0;
	tab->image_data[41] = 255;
	tab->image_data[42] = 200;*/
//	mlx_put_image_to_window(tab->mlx_ptr, tab->window, tab->image, 0, 2);
	mlx_key_hook(tab->window, deal_key, tab);
	mlx_loop(tab->mlx_ptr);
	free(tab);
	tab = NULL;

	return (0);
}
