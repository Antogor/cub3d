/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:43:22 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/07 13:04:55 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

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

int **bi_array(int **array, int nrows, int ncolumns)
{
    int i;

	i = 0;
    if(!(array = malloc(nrows * sizeof(int *))))
		return (NULL);
    while (i < nrows)
    {
    	if(!(array[i] = malloc(ncolumns * sizeof(int))))
			return (NULL);
		i++;
    }
	return(array);
}

int **fill_bi_array(int **array, int rows, int columns, int filled)
{
	int l;
	int q;

	l = 0;
	q = 0;
	while(l < rows)
	{
		q = 0;
		while(q < columns)
		{
			array[l][q] = filled;
			q++;
		}
		l++;
	}
	return (array);
}

int             main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
	int colorR;
	int colorG;
	int colorB;
	int colorT;

	
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 520, 360, "cub3D");
    img.img = mlx_new_image(mlx, 520, 360);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
	colorR = create_trgb(0, 255, 0, 0);
	colorG = create_trgb(0, 0, 255, 0);
	colorB = create_trgb(0, 0, 0, 255);
	colorT = create_trgb(255, 0, 0, 0);
	my_mlx_pixel_put(&img, 260, 180, colorR);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

    mlx_loop(mlx);
}
