/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:14:28 by agarzon-          #+#    #+#             */
/*   Updated: 2020/06/06 19:53:29 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	rotation(int key, t_player *p)
{
	double old_dir_x;
	double old_plane_x;
	double s;

	s = 0.6;
	old_dir_x = p->dir_x;
	old_plane_x = p->plane_x;
	if (key == RIGTH)
	{
		p->dir_x = p->dir_x * cos(-s) - p->dir_y * sin(-s);
		p->plane_x = p->plane_x * cos(-s) - p->plane_y * sin(-s);
		p->dir_y = old_dir_x * sin(-s) + p->dir_y * cos(-s);
		p->plane_y = old_plane_x * sin(-s) + p->plane_y * cos(-s);
	}
	if (key == LEFT)
	{
		p->dir_x = p->dir_x * cos(s) - p->dir_y * sin(s);
		p->plane_x = p->plane_x * cos(s) - p->plane_y * sin(s);
		p->dir_y = old_dir_x * sin(s) + p->dir_y * cos(s);
		p->plane_y = old_plane_x * sin(s) + p->plane_y * cos(s);
	}
	return (0);
}

int	can_move(char pos)
{
	if (pos == '1' || pos == '4')
		return (0);
	return (1);
}

int	left_right(int key, t_player *p, char **m)
{
	if (key == D)
	{
		if (can_move(m[(int)p->pos_x][(int)(p->pos_y +
			p->dir_x * p->speed)]))
			p->pos_y += p->dir_x * p->speed;
		if (can_move(m[(int)(p->pos_x - p->dir_y *
			p->speed)][(int)p->pos_y]))
			p->pos_x -= p->dir_y * p->speed;
	}
	else if (key == A)
	{
		if (can_move(m[(int)p->pos_x][(int)(p->pos_y -
			p->dir_x * p->speed)]))
			p->pos_y -= p->dir_x * p->speed;
		if (can_move(m[(int)(p->pos_x + p->dir_y *
			p->speed)][(int)p->pos_y]))
			p->pos_x += p->dir_y * p->speed;
	}
	return (0);
}

int	up_down(int key, t_cub3d *c)
{
	if (key == ESC)
		close_game(c);
	if (key == W)
	{
		if (can_move(c->map.m[(int)(c->pl.pos_x + c->pl.dir_x *
			c->pl.speed)][(int)c->pl.pos_y]))
			c->pl.pos_x += c->pl.dir_x * c->pl.speed;
		if (can_move(c->map.m[(int)c->pl.pos_x][(int)(c->pl.pos_y +
			c->pl.dir_y * c->pl.speed)]))
			c->pl.pos_y += c->pl.dir_y * c->pl.speed;
	}
	else if (key == S)
	{
		if (can_move(c->map.m[(int)(c->pl.pos_x - c->pl.dir_x *
			c->pl.speed)][(int)c->pl.pos_y]))
			c->pl.pos_x -= c->pl.dir_x * c->pl.speed;
		if (can_move(c->map.m[(int)c->pl.pos_x][(int)(c->pl.pos_y -
			c->pl.dir_y * c->pl.speed)]))
			c->pl.pos_y -= c->pl.dir_y * c->pl.speed;
	}
	left_right(key, &c->pl, c->map.m);
	rotation(key, &c->pl);
	return (0);
}

int	movement(t_cub3d *cub3d)
{
	mlx_hook(cub3d->mlx.win, 2, 1L << 0, up_down, cub3d);
	return (0);
}
