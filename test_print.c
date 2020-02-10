/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:43:22 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/10 14:25:45 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int cross(int button, t_mlx *mlx)
{
	exit(0);
	return (0);
}

int close2(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
		exit(ESC);
	
	return (0);
}

int move_x(int kycde, t_mlx *mlx)
{
	if (kycde == W)
	{
		mlx->x++;
		return (mlx->x);
	}
	else if (kycde == S)
	{
		mlx->x--;
		return (mlx->x);
	}
	return (0);
}

int move_y(int keycde, t_mlx *mlx)
{
	if (keycde == A)
	{
		mlx->y--;
		return (mlx->y);
	}
	else if (keycde == D)
	{
		mlx->y++;
		return (mlx->y);
	}
	return (0);
}

int     render_next_frame(t_mlx *img)
{

	mlx_put_image_to_window(img->mlx_ptr, img->window, img->img, img->x, img->y);

	return (0);
}

int		main(void)
{
    t_mlx	*img;
	t_color	*color;

	color = (t_color *)malloc(sizeof(t_color));
	img = (t_mlx *)malloc(sizeof(t_mlx));
    img->mlx_ptr = mlx_init();
    img->window = mlx_new_window(img->mlx_ptr, 520, 360, "cub3D");
	mlx_hook(img->window, 2, 1L<<0, close2, img);
	mlx_hook(img->window, 5, 1L<<7, cross, img);
	img->x = 0;
	img->y = 0;
	img->x += mlx_hook(img->window, 2, 1L<<0, move_x, img);
	img->y += mlx_hook(img->window, 2, 1L<<0, move_y, img);
	img->img = mlx_new_image(img->mlx_ptr, 520, 360);
    img->img_data = mlx_get_data_addr(img->img, &img->bpp, &img->size_l,
                                 &img->endian);
	color->colorR = create_trgb(0, 255, 0, 0);
	color->colorG = create_trgb(0, 0, 255, 0);
	color->colorB = create_trgb(0, 0, 0, 255);
	color->colorT = create_trgb(255, 0, 0, 0);
	paint(img, color->colorB, 50, 50);
	
	mlx_loop_hook(img->mlx_ptr, render_next_frame, img);
	
	

    mlx_loop(img->mlx_ptr);
}
