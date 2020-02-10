/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:19:05 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/10 11:36:04 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void            my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
    char    *dst;

    dst = data->img_data + (y * data->size_l + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}

void	paint(t_mlx *print, int color, int fin_x, int fin_y)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < fin_x)
	{
		my_mlx_pixel_put(print, x, y, color);
		y = 0;
		while (y < fin_y)
		{
			my_mlx_pixel_put(print, x, y, color);
			y++;
		}
		x++;
	}
}
