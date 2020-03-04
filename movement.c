/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:14:28 by agarzon-          #+#    #+#             */
/*   Updated: 2020/03/04 13:22:43 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rotation(int key, t_cub3d *cub3d)
{
	double old_dir_x;
	double old_plane_x;
	double speed;

	speed = 0.6;
	old_dir_x = cub3d->player->dir_x;
	old_plane_x = cub3d->player->plane_x;
	if (key == RIGTH)
	{
		cub3d->player->dir_x = cub3d->player->dir_x * cos(-speed) -
			cub3d->player->dir_y * sin(-speed);
		cub3d->player->plane_x = cub3d->player->plane_x * cos(-speed) -
			cub3d->player->plane_y * sin(-speed);
		cub3d->player->dir_y = old_dir_x * sin(-speed) +
			cub3d->player->dir_y * cos(-speed);
		cub3d->player->plane_y = old_plane_x * sin(-speed) +
			cub3d->player->plane_y * cos(-speed);
	}
	if (key == LEFT)
	{
		cub3d->player->dir_x = cub3d->player->dir_x * cos(speed) -
			cub3d->player->dir_y * sin(speed);
		cub3d->player->plane_x = cub3d->player->plane_x * cos(speed) -
			cub3d->player->plane_y * sin(speed);
		cub3d->player->dir_y = old_dir_x * sin(speed) +
			cub3d->player->dir_y * cos(speed);
		cub3d->player->plane_y = old_plane_x * sin(speed) +
			cub3d->player->plane_y * cos(speed);
	}
	return (0);
}

int	can_move(char pos)
{
	if (pos == '1')
		return (0);
	return (1);
}

int	left_right(int key, t_cub3d *cub3d)
{
	if (key == D)
	{
		if (can_move(cub3d->map[(int)cub3d->player->pos_y][(int)(cub3d->player->pos_x + cub3d->player->dir_y * cub3d->player->speed)]))
			cub3d->player->pos_x += cub3d->player->dir_y * cub3d->player->speed;
		if (can_move(cub3d->map[(int)(cub3d->player->pos_y - cub3d->player->dir_x * cub3d->player->speed)][(int)cub3d->player->pos_x]))
			cub3d->player->pos_y -= cub3d->player->dir_x * cub3d->player->speed;
		
	}
	else if (key == A)
	{
		if (can_move(cub3d->map[(int)cub3d->player->pos_y][(int)(cub3d->player->pos_x - cub3d->player->dir_y * cub3d->player->speed)]))
			cub3d->player->pos_x -= cub3d->player->dir_y * cub3d->player->speed;
		if (can_move(cub3d->map[(int)(cub3d->player->pos_y + cub3d->player->dir_x * cub3d->player->speed)][(int)cub3d->player->pos_x]))
			cub3d->player->pos_y += cub3d->player->dir_x * cub3d->player->speed;
			
	}
	return (0);
}

int	up_down(int key, t_cub3d *cub3d)
{
	if (key == ESC)
		exit(ESC);
	if (key == W)
	{
		if (can_move(cub3d->map[(int)(cub3d->player->pos_y + cub3d->player->dir_y * cub3d->player->speed)][(int)cub3d->player->pos_x]))
			cub3d->player->pos_y += cub3d->player->dir_y * cub3d->player->speed;
		if (can_move(cub3d->map[(int)cub3d->player->pos_y][(int)(cub3d->player->pos_x + cub3d->player->dir_x * cub3d->player->speed)]))
			cub3d->player->pos_x += cub3d->player->dir_x * cub3d->player->speed;
		
	}
	else if (key == S)
	{
		if (can_move(cub3d->map[(int)(cub3d->player->pos_y - cub3d->player->dir_y * cub3d->player->speed)][(int)cub3d->player->pos_x]))
			cub3d->player->pos_y -= cub3d->player->dir_y * cub3d->player->speed;
		if (can_move(cub3d->map[(int)cub3d->player->pos_y][(int)(cub3d->player->pos_x - cub3d->player->dir_x * cub3d->player->speed)]))
			cub3d->player->pos_x -= cub3d->player->dir_x * cub3d->player->speed;
	}
	left_right(key, cub3d);
	rotation(key, cub3d);
	return (0);
}

int	movement(t_cub3d *cub3d)
{
	cub3d->player->speed = 0.5;
	mlx_hook(cub3d->mlx->window, 2, 1L << 0, up_down, cub3d);
	return (0);
}
