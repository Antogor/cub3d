/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:43:22 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/05 17:26:10 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>
#include <stdio.h>

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
} 				t_data;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

int main (void)
{
	void *mlx;
	void *mlx_window;
	int colorR;
	int colorG;
	int colorB;
	int colorT;
	t_data img;
	char    *dst;
	
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 1920, 1080, "test");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(mlx, &img.bits_per_pixel, &img.line_length, &img.endian);
	colorR = create_trgb(0, 255, 0, 0);
	colorG = create_trgb(0, 0, 255, 0);
	colorB = create_trgb(0, 0, 0, 255);
	colorT = create_trgb(255, 0, 0, 0);
	dst = img.addr + (5 * img.line_length + 5 * (img.bits_per_pixel / 8));
   *(unsigned int*)dst = colorR;
	printf("%s", dst);
//	my_mlx_pixel_put(&img, 1000, 500, colorR);
//	mlx_pixel_put(mlx, mlx_window, 1000, 500, colorR);
/*	mlx_string_put(mlx, mlx_window, 6, 6, colorR, "ROJO");
	mlx_string_put(mlx, mlx_window, 100, 100, colorG, "VERDE");
	mlx_string_put(mlx, mlx_window, 300, 300, colorB, "AZUL");*/
//	mlx_put_image_to_window(mlx, mlx_window, img.img, 5, 5);
	mlx_loop(mlx);
}