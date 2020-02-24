/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:14:28 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/24 12:35:14 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	left_right(int key, t_cub3d *cub3d)
{
	if (key == D)
	{
		if (cub3d->map[(int)cub3d->player->pos_x][(int)cub3d->player->pos_y])
			cub3d->player->pos_x -= cub3d->player->dir_x *
				cub3d->player->speed;
	}
	else if (key == A)
	{
		if (cub3d->map[(int)cub3d->player->pos_x][(int)cub3d->player->pos_y])
			cub3d->player->pos_x += cub3d->player->dir_x *
				cub3d->player->speed;
	}
	return (0);
}

int	up_down(int key, t_cub3d *cub3d)
{
	if (key == ESC)
		exit(ESC);
	if (key == W)
	{
		if (cub3d->map[(int)cub3d->player->pos_x][(int)cub3d->player->pos_y])
			cub3d->player->pos_y += cub3d->player->dir_y *
				cub3d->player->speed;
	}
	else if (key == S)
	{
		if (cub3d->map[(int)cub3d->player->pos_x][(int)cub3d->player->pos_y])
			cub3d->player->pos_y -= cub3d->player->dir_y *
				cub3d->player->speed;
	}
	left_right(key, cub3d);
	return (0);
}

int	movement(t_cub3d *cub3d)
{
	cub3d->player->speed = 0.5;
	mlx_hook(cub3d->mlx->window, 2, 1L << 0, up_down, cub3d);
	return (0);
}
