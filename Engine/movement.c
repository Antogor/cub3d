/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:14:28 by agarzon-          #+#    #+#             */
/*   Updated: 2020/04/09 21:22:20 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	rotation(int key, t_player *player)
{
	double old_dir_x;
	double old_plane_x;
	double speed;

	speed = 0.6;
	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	if (key == RIGTH)
	{
		player->dir_x = player->dir_x * cos(-speed) - player->dir_y *
			sin(-speed);
		player->plane_x = player->plane_x * cos(-speed) - player->plane_y *
			sin(-speed);
		player->dir_y = old_dir_x * sin(-speed) + player->dir_y * cos(-speed);
		player->plane_y = old_plane_x * sin(-speed) + player->plane_y *
			cos(-speed);
	}
	if (key == LEFT)
	{
		player->dir_x = player->dir_x * cos(speed) - player->dir_y * sin(speed);
		player->plane_x = player->plane_x * cos(speed) - player->plane_y *
			sin(speed);
		player->dir_y = old_dir_x * sin(speed) + player->dir_y * cos(speed);
		player->plane_y = old_plane_x * sin(speed) + player->plane_y *
			cos(speed);
	}
	return (0);
}

int	can_move(char pos)
{
	if (pos == '1' || pos == '4')
		return (0);
	return (1);
}

int	left_right(int key, t_cub3d *cub3d, t_player *player)
{
	if (key == D)
	{
		if (can_move(cub3d->map[(int)player->pos_x][(int)(player->pos_y +
			player->dir_x * player->speed)]))
			player->pos_y += player->dir_x * player->speed;
		if (can_move(cub3d->map[(int)(player->pos_x - player->dir_y *
			player->speed)][(int)player->pos_y]))
			player->pos_x -= player->dir_y * player->speed;
	}
	else if (key == A)
	{
		if (can_move(cub3d->map[(int)player->pos_x][(int)(player->pos_y -
			player->dir_x * player->speed)]))
			player->pos_y -= player->dir_x * player->speed;
		if (can_move(cub3d->map[(int)(player->pos_x + player->dir_y *
			player->speed)][(int)player->pos_y]))
			player->pos_x += player->dir_y * player->speed;
	}
	return (0);
}

int	up_down(int key, t_cub3d *cub3d)
{
	t_player *player;

	player = cub3d->player;
	if (key == ESC)
		close_game(cub3d);
	if (key == W)
	{
		if (can_move(cub3d->map[(int)(player->pos_x + player->dir_x *
			player->speed)][(int)player->pos_y]))
			player->pos_x += player->dir_x * player->speed;
		if (can_move(cub3d->map[(int)player->pos_x][(int)(player->pos_y +
			player->dir_y * player->speed)]))
			player->pos_y += player->dir_y * player->speed;
	}
	else if (key == S)
	{
		if (can_move(cub3d->map[(int)(player->pos_x - player->dir_x *
			player->speed)][(int)player->pos_y]))
			player->pos_x -= player->dir_x * player->speed;
		if (can_move(cub3d->map[(int)player->pos_x][(int)(player->pos_y -
			player->dir_y * player->speed)]))
			player->pos_y -= player->dir_y * player->speed;
	}
	left_right(key, cub3d, player);
	rotation(key, player);
	return (0);
}

int	movement(t_cub3d *cub3d)
{
	cub3d->player->speed = 0.5;
	mlx_hook(cub3d->mlx->window, 2, (1L << 0), up_down, cub3d);
	return (0);
}
