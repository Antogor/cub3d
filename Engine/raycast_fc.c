/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_fc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:36:55 by agarzon-          #+#    #+#             */
/*   Updated: 2020/06/08 18:47:22 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	choose_color(t_color color, t_tx *t, int tx, int ty)
{
	if (t->f.floor && t->c.celing)
	{
		t->colorc = (int)t->c.data[ty * t->c.w + tx];
		t->colorc = t->colorc >> 1 & 8355711;
		t->colorf = (int)t->f.data[ty * t->f.w + tx];
		t->colorf = t->colorf >> 1 & 8355711;
	}
	else
	{
		t->colorc = color.celling;
		t->colorf = color.floor;
	}
}

void	put_fc(t_cub3d *c, t_fc_tools *t, t_mlx *ml, int y)
{
	int x;

	x = 0;
	while (x < c->screen_w)
	{
		t->cell_x = (int)t->floor_x;
		t->cell_y = (int)t->floor_y;
		t->tx = (int)(256 * (t->floor_x - t->cell_x)) &
			(256 - 1);
		t->ty = (int)(256 * (t->floor_y - t->cell_y)) &
			(256 - 1);
		t->floor_x += t->floorstep_x;
		t->floor_y += t->floorstep_y;
		choose_color(c->color, &c->tx, t->tx, t->ty);
		ml->i_data[y * c->screen_w + x] = c->tx.colorf;
		ml->i_data[(c->screen_h - y - 1) * c->screen_w + x] =
			c->tx.colorc;
		x++;
	}
}

int		raycast_fc(t_cub3d *c, t_fc_tools *t, t_mlx *ml,
	t_player p)
{
	int			y;

	y = c->screen_h / 2 - 1;
	while (y < c->screen_h)
	{
		t->raydir_x0 = p.dir_x - p.plane_x;
		t->raydir_y0 = p.dir_y - p.plane_y;
		t->raydir_x1 = p.dir_x + p.plane_x;
		t->raydir_y1 = p.dir_y + p.plane_y;
		t->p = y - c->screen_h / 2;
		t->pos_z = 0.5 * c->screen_h;
		t->row_dist = t->pos_z / t->p;
		t->floorstep_x = t->row_dist * (t->raydir_x1 - t->raydir_x0)
			/ c->screen_w;
		t->floorstep_y = t->row_dist * (t->raydir_y1 - t->raydir_y0)
			/ c->screen_w;
		t->floor_x = p.pos_x + t->row_dist * t->raydir_x0;
		t->floor_y = p.pos_y + t->row_dist * t->raydir_y0;
		put_fc(c, t, ml, y);
		y++;
	}
	return (0);
}
