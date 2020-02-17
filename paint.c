/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:19:05 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/17 13:42:57 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	paint(t_cub3d *cub3d)
{
	int l;

	l = 0;
	while (l < cub3d->raycast->draw_start)
	{
		*(cub3d->mlx->img_data + cub3d->raycast->x + l *
			cub3d->mlx->size_l / 4) = cub3d->color->color_b;
		l++;
	}
	while (l < cub3d->raycast->draw_end)
	{
		if (cub3d->raycast->side == 0)
			*(cub3d->mlx->img_data + cub3d->raycast->x + l *
				cub3d->mlx->size_l / 4) = cub3d->color->color_g;
		else
			*(cub3d->mlx->img_data + cub3d->raycast->x + l *
				cub3d->mlx->size_l / 4) = cub3d->color->color_w;
		l++;
	}
	while (l < screenHeight)
	{
		*(cub3d->mlx->img_data + cub3d->raycast->x + l *
			cub3d->mlx->size_l / 4) = cub3d->color->color_r;
		l++;
	}
}
