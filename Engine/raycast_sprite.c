/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:53:50 by agarzon-          #+#    #+#             */
/*   Updated: 2020/06/09 16:30:40 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	dist_sprite(t_cub3d *c, double *s_dist)
{
	int		tmp;
	int		dis_tmp;
	int		l;

	l = 0;
	while (l < c->s_nb)
	{
		if (s_dist[l] < s_dist[l + 1])
		{
			dis_tmp = s_dist[l];
			s_dist[l] = s_dist[l + 1];
			s_dist[l + 1] = dis_tmp;
			tmp = c->s_order[l];
			c->s_order[l] = c->s_order[l + 1];
			c->s_order[l + 1] = tmp;
			l = 0;
		}
		l++;
	}
}

void	choose_sprite(t_cub3d *c, t_player pl)
{
	int		l;
	double	s_dist[c->s_nb];

	l = 0;
	while (l < c->s_nb)
	{
		s_dist[l] = ((pl.pos_x - c->sprite[l].x) *
		(pl.pos_x - c->sprite[l].x) + (pl.pos_y - c->sprite[l].y) *
		(pl.pos_y - c->sprite[l].y));
		c->s_order[l] = l;
		l++;
	}
	dist_sprite(c, s_dist);
}

void	calcualte_sprite_hw(t_spritetools *s_tools, int h, int w)
{
	s_tools->h = abs((int)(h / (s_tools->transform_y)));
	s_tools->draw_start_y = -s_tools->h / 2 + h / 2;
	if (s_tools->draw_start_y < 0)
		s_tools->draw_start_y = 0;
	s_tools->draw_end_y = s_tools->h / 2 + h / 2;
	if (s_tools->draw_end_y >= h)
		s_tools->draw_end_y = h - 1;
	s_tools->w = abs((int)(h / (s_tools->transform_y)));
	s_tools->draw_start_x = -s_tools->w / 2 + s_tools->screen_x;
	if (s_tools->draw_start_x < 0)
		s_tools->draw_start_x = 0;
	s_tools->draw_end_x = s_tools->w / 2 + s_tools->screen_x;
	if (s_tools->draw_end_x >= w)
		s_tools->draw_end_x = w - 1;
}

void	draw_sprite(t_spritetools *s_tools, t_cub3d *c, t_tx_sprite s,
		t_mlx *ml)
{
	s_tools->stripe = s_tools->draw_start_x;
	while (s_tools->stripe++ < s_tools->draw_end_x)
	{
		s_tools->tex_x = (int)(256 * (s_tools->stripe - (-s_tools->w /
			2 + s_tools->screen_x)) * s.w /
			s_tools->w) / 256;
		if (s_tools->transform_y > 0 && s_tools->stripe > 0 &&
			s_tools->stripe < c->screen_w &&
			s_tools->transform_y < (float)c->z_buffer[s_tools->stripe])
		{
			s_tools->y = s_tools->draw_start_y;
			while (s_tools->y++ < s_tools->draw_end_y)
			{
				s_tools->d = (s_tools->y) * 256 - c->screen_h * 128 +
					s_tools->h * 128;
				s_tools->tex_y = ((s_tools->d * s.h) /
					s_tools->h / 256);
				if (s.data[s_tools->tex_x + s_tools->tex_y * s.sl / 4])
					ml->i_data[(int)(s_tools->stripe + s_tools->y *
					ml->size_l / 4)] =
						s.data[s_tools->tex_x + s_tools->tex_y
						* s.sl / 4];
			}
		}
	}
}

int		raycast_sprite(t_cub3d *c, t_player pl)
{
	int				l;
	t_sprite		s;
	t_spritetools	s_tools;

	choose_sprite(c, pl);
	l = 0;
	while (l < c->s_nb)
	{
		s = c->sprite[c->s_order[l]];
		s_tools.x = ((s.x + 0.5) - pl.pos_x);
		s_tools.y = ((s.y + 0.5) - pl.pos_y);
		s_tools.inv_det = 1.0 / (pl.plane_x * pl.dir_y -
			pl.dir_x * pl.plane_y);
		s_tools.transform_x = s_tools.inv_det * (pl.dir_y *
			s_tools.x - pl.dir_x * s_tools.y);
		s_tools.transform_y = s_tools.inv_det * (-pl.plane_y *
			s_tools.x + pl.plane_x * s_tools.y);
		s_tools.screen_x = (int)((c->screen_w / 2) *
			(1 + s_tools.transform_x / s_tools.transform_y));
		calcualte_sprite_hw(&s_tools, c->screen_h, c->screen_w);
		draw_sprite(&s_tools, c, c->tx.s, &c->mlx);
		l++;
	}
	return (0);
}
