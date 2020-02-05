/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:43:22 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/05 14:05:00 by agarzon-         ###   ########.fr       */
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

int create_trgb(int t, int r, int g, int b)
{
	return(t | b << 24 | r << 16 | g << 8);
}

int		get_t(int trgb)
{
	return (trgb & 0xFF);
}

int		get_r(int trgb)
{
	return (trgb & 0xFF00);
}

int		get_g(int trgb)
{
	return (trgb & 0xFF0000);
}

int		get_b(int trgb)
{
	return (trgb & 0xFF000000);
}

int main (void)
{
	void *mlx;
	void *mlx_window;
	int color;
	t_data img;
	char    *dst;
	img.line_length = 0;
	
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 1920, 1080, "test");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(mlx, &img.bits_per_pixel, &img.line_length, &img.endian);
	int t = get_t(000);
	int r = get_r(255);
	int g = get_g(000);
	int b = get_b(000);
	color = create_trgb(255, 0, 255, 0);
/*	my_mlx_pixel_put(&img, 5, 5, 0x23BAC4);
	my_mlx_pixel_put(&img, 5, 9, 0x23BAC4);
	my_mlx_pixel_put(&img, 5, 6, 0x23BAC4);
	my_mlx_pixel_put(&img, 5, 7, 0x23BAC4);
	my_mlx_pixel_put(&img, 5, 8, 0x23BAC4);*/
	mlx_pixel_put(mlx, mlx_window, 5, 6, 0x23BAC4);
	mlx_pixel_put(mlx, mlx_window, 5, 7, 0x23BAC4);
	mlx_pixel_put(mlx, mlx_window, 5, 8, 0x23BAC4);
	mlx_pixel_put(mlx, mlx_window, 5, 9, 0x23BAC4);
	mlx_pixel_put(mlx, mlx_window, 5, 10, 0x23BAC4);
	mlx_pixel_put(mlx, mlx_window, 5, 11, 0x23BAC4);
	mlx_pixel_put(mlx, mlx_window, 5, 12, 0x23BAC4);
	mlx_pixel_put(mlx, mlx_window, 5, 13, 0x23BAC4);
	mlx_put_image_to_window(mlx, mlx_window, img.img, 5, 5);
	mlx_string_put(mlx, mlx_window, 5, 5, color, "AAAAAAA");
	mlx_loop(mlx);
}