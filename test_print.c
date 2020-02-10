/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:43:22 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/10 12:24:23 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(void)
{
    t_mlx	*img;
	t_color	*color;

	img = (t_mlx *)malloc(sizeof(t_mlx));
	color = (t_color *)malloc(sizeof(t_color));
    img->mlx_ptr = mlx_init();
    img->window = mlx_new_window(img->mlx_ptr, 520, 360, "cub3D");
    img->img = mlx_new_image(img->mlx_ptr, 520, 360);
    img->img_data = mlx_get_data_addr(img->img, &img->bpp, &img->size_l,
                                 &img->endian);
	color->colorR = create_trgb(0, 255, 0, 0);
	color->colorG = create_trgb(0, 0, 255, 0);
	color->colorB = create_trgb(0, 0, 0, 255);
	color->colorT = create_trgb(255, 0, 0, 0);
	paint(img, color->colorR, 20, 50);
	mlx_put_image_to_window(img->mlx_ptr, img->window, img->img, 0, 0);

    mlx_loop(img->mlx_ptr);
}
