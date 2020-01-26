/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:24:14 by agarzon-          #+#    #+#             */
/*   Updated: 2020/01/26 13:28:22 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		deal_key(int key, void *param)
{
	if (key == 8 && param == 0)
		write(1, "c", 1);
	
	return(0);
}
int		main()
{
	t_mlx *tab;
/*	int bpp;
	int size_line;
	int endian;
	int count_h;
	int count_w;*/

	tab = (t_mlx *)malloc(sizeof(t_mlx *));
	tab->mlx_ptr = mlx_init();
	tab->window = mlx_new_window(tab->mlx_ptr, 640, 360, "cub3d");
	mlx_string_put (tab->mlx_ptr, tab->window, 10, 300, 0xFFFFFF, "Aqui la vida");
//	mlx_xpm_file_to_image (tab->mlx_ptr, "cthulhu", (int *)50, (int *)50);
//	mlx_pixel_put(tab->mlx_ptr, tab->window, 50, 50, 0xFFFFFF);
//	tab->image = mlx_new_image(tab->mlx_ptr, 50, 50);
//	tab->image_data = (int *)mlx_get_data_addr(tab->image, &bpp, &size_line, &endian);
/*	tab->image_data[40] = 150;
	tab->image_data[41] = 255;
	tab->image_data[42] = 200;*/
/*	count_h = 0;
	while(count_h++ < 640)
	{
		count_w = 0;
		while (count_w++ < 360)
		{
			if (count_w / 2)
				tab->image_data[count_h * 360 *count_w] = 0xFFFFFF;
			else
				tab->image_data[count_h * 360 *count_w] = 0;
		}
	mlx_put_image_to_window(tab->mlx_ptr, tab->window, tab->image, 50, 50);
	}*/
	
	
//	mlx_key_hook(tab->window, deal_key, (void*)0);
	mlx_loop(tab->mlx_ptr);
	free(tab);
	tab = NULL;

	return (0);
}
