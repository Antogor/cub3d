/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 13:42:18 by agarzon-          #+#    #+#             */
/*   Updated: 2020/06/08 15:28:51 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	init_key(t_player *p)
{
	p->k.up = 0;
	p->k.down = 0;
	p->k.left = 0;
	p->k.right = 0;
	p->k.rot_l = 0;
	p->k.rot_r = 0;
	return (0);
}

int	key_press(int k, t_cub3d *c)
{
	if (k == W)
		c->pl.k.up = 1;
	else if (k == S)
		c->pl.k.down = 1;
	else if (k == A)
		c->pl.k.left = 1;
	else if (k == D)
		c->pl.k.right = 1;
	else if (k == LEFT)
		c->pl.k.rot_l = 1;
	else if (k == RIGHT)
		c->pl.k.rot_r = 1;
	else if (k == ESC)
		close_game(c);
	return (0);
}

int	key_release(int k, t_cub3d *c)
{
	if (k == W)
		c->pl.k.up = 0;
	else if (k == S)
		c->pl.k.down = 0;
	else if (k == A)
		c->pl.k.left = 0;
	else if (k == D)
		c->pl.k.right = 0;
	else if (k == LEFT)
		c->pl.k.rot_l = 0;
	else if (k == RIGHT)
		c->pl.k.rot_r = 0;
	return (0);
}
