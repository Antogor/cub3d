/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:24:14 by agarzon-          #+#    #+#             */
/*   Updated: 2020/01/24 13:18:42 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*int		deal_key(int key, void *param)
{

	return(0);
}*/
int		main()
{
	void *mlx_ptr;
	void *window;
	int *image;
	char *image_data;
	int bpp;
	int size_line;
	int endian;

	mlx_ptr = mlx_init();
	window = mlx_new_window(mlx_ptr, 640, 360, "cub3d");
	image = mlx_new_image(mlx_ptr, 5, 5);
	image_data = mlx_get_data_addr(image, &bpp, &size_line, &endian);
	image_data[40] = 0;
	image_data[41] = 255;
	image_data[42] = 200;
	mlx_put_image_to_window(mlx_ptr, window, image, 0, 2);
	//mlx_key_hook(window, deal_key, (void*)0);
	mlx_loop(mlx_ptr);

	return (0);
}
