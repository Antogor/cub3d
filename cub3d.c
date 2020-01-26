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

/*int		deal_key(int key, void *param)
{
	
	return(0);
}*/
int		main()
{
	t_mlx *tab;

	tab = (t_mlx *)malloc(sizeof(t_mlx *));
	tab->mlx_ptr = mlx_init();
	tab->window = mlx_new_window(tab->mlx_ptr, 640, 360, "cub3d");
	tab->image = mlx_new_image(tab->mlx_ptr, 5, 5);
	tab->image_data = mlx_get_data_addr(tab->image, &tab->bpp, &tab->size_line, &tab->endian);
	tab->image_data[40] = 0;
	tab->image_data[41] = 255;
	tab->image_data[42] = 200;
	mlx_put_image_to_window(tab->mlx_ptr, tab->window, tab->image, 0, 2);
//	mlx_key_hook(tab->window, deal_key, (void*)tab);
	mlx_loop(tab->mlx_ptr);
	free(tab);
	tab = NULL;

	return (0);
}
