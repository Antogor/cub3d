/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 12:21:12 by agarzon-          #+#    #+#             */
/*   Updated: 2020/06/05 19:03:45 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	calculate_text(t_tx *t, t_raycast r)
{
	t->txt = (int)(r.wall_x * (double)t->w);
	if (r.side == 0 && r.ray_dir_x > 0)
		t->txt = (t->w - t->txt - 1);
	if (r.side == 1 && r.ray_dir_y < 0)
		t->txt = (t->w - t->txt - 1);
	return (0);
}

int	choose_we(t_tx *t)
{
	if (t->wall_dir == 'E')
	{
		t->data = t->walls.data_ea;
		t->sl = t->walls.ea_sl;
		t->h = t->walls.ea_h;
		t->w = t->walls.ea_w;
	}
	else if (t->wall_dir == 'W')
	{
		t->data = t->walls.data_we;
		t->sl = t->walls.we_sl;
		t->h = t->walls.we_h;
		t->w = t->walls.we_w;
	}
	return (0);
}

int	choose_texture(t_tx *t, t_raycast r)
{
	if (t->wall_dir == 'N')
	{
		t->data = t->walls.data_no;
		t->sl = t->walls.no_sl;
		t->h = t->walls.no_h;
		t->w = t->walls.no_w;
	}
	else if (t->wall_dir == 'S')
	{
		t->data = t->walls.data_so;
		t->sl = t->walls.so_sl;
		t->h = t->walls.so_h;
		t->w = t->walls.so_w;
	}
	choose_we(t);
	calculate_text(t, r);
	return (0);
}
