/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:53:50 by agarzon-          #+#    #+#             */
/*   Updated: 2020/03/09 17:19:54 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	choose_sprite(t_cub3d *cub3d, t_sprite *sprite, t_player *player)
{
	int		l;
	double	sprite_dist[cub3d->sprite_nb];
	int		tmp;
	int		dis_tmp;

	l = 0;
	cub3d->sprite_order = malloc(cub3d->sprite_nb * sizeof(int));
	while (l++ < cub3d->sprite_nb)
	{
		sprite_dist[l] = ((player->pos_x - sprite[l].sprite_x) *
			(player->pos_x - sprite[l].sprite_x) + (player->pos_y -
			sprite[l].sprite_y) * (player->pos_y - sprite[l].sprite_y));
		cub3d->sprite_order[l] = l;
	}
	l = 0;
	while (l++ < cub3d->sprite_nb - 1)
	{
		if (sprite_dist[l] < sprite_dist[l + 1])
		{
			dis_tmp = sprite_dist[l];
			sprite_dist[l] = sprite_dist[l + 1];
			sprite_dist[l + 1] = dis_tmp;
			tmp = cub3d->sprite_order[l];
			cub3d->sprite_order[l] = cub3d->sprite_order[l + 1];
			cub3d->sprite_order[l + 1] = tmp;
			l = 0;
		}
	}
}

void	calcualte_sprite_h(t_spritetools *s_tools, t_cub3d *cub3d)
{
	s_tools->sprite_h = abs((int)(cub3d->screen_h /
		(s_tools->transform_y)));
	s_tools->draw_start_y = -s_tools->sprite_h / 2 + cub3d->screen_h / 2;
	if (s_tools->draw_start_y < 0)
		s_tools->draw_start_y = 0;
	s_tools->draw_end_y = s_tools->sprite_h / 2 + cub3d->screen_h / 2;
	if (s_tools->draw_end_y >= cub3d->screen_h)
		s_tools->draw_end_y = cub3d->screen_h;
}

void	calcualte_sprite_w(t_spritetools *s_tools, t_cub3d *cub3d)
{
	s_tools->sprite_w = abs((int)(cub3d->screen_h /
		(s_tools->transform_y)));
	s_tools->draw_start_x = -s_tools->sprite_w / 2 + s_tools->sprite_screen_x;
	if (s_tools->draw_start_x < 0)
		s_tools->draw_start_x = 0;
	s_tools->draw_end_x = s_tools->sprite_w / 2 + s_tools->sprite_screen_x;
	if (s_tools->draw_end_x >= cub3d->screen_w)
		s_tools->draw_end_x = cub3d->screen_w;
}

void	draw_sprite(t_spritetools *s_tools, t_cub3d *cub3d, t_text *text)
{
	s_tools->stripe = s_tools->draw_start_x;
	while (s_tools->stripe++ < s_tools->draw_end_x)
	{
		s_tools->tex_x = (int)((s_tools->stripe - (-s_tools->sprite_w /
			2 + s_tools->sprite_screen_x)) * text->text_sprite_w /
			s_tools->sprite_w);
		s_tools->y = s_tools->draw_start_y;
		if (s_tools->transform_y > 0 && s_tools->stripe >= 0 &&
			s_tools->stripe < cub3d->screen_w &&
			s_tools->transform_y < (float)cub3d->z_buffer[s_tools->stripe])
		{
			while (s_tools->y++ < s_tools->draw_end_y)
			{
				s_tools->d = (s_tools->y) * 256 - cub3d->screen_h * 128 +
					s_tools->sprite_h * 128;
				s_tools->tex_y = ((s_tools->d * text->text_sprite_h) /
					s_tools->sprite_h / 256);
				if (text->text_d_sprite[s_tools->tex_x + s_tools->tex_y *
					text->text_sprite_sl / 4])
					cub3d->mlx->img_data[s_tools->stripe + s_tools->y *
						cub3d->mlx->size_l / 4] =
						text->text_d_sprite[s_tools->tex_x + s_tools->tex_y
						* text->text_sprite_sl / 4];
			}
		}
	}
}

int		raycast_sprite(t_cub3d *cub3d, t_sprite *sprite, t_text *text,
					t_player *player)
{
	int				l;
	t_spritetools	*s_tools;

	l = 0;
	s_tools = (t_spritetools *)malloc(sizeof(t_spritetools));
	choose_sprite(cub3d, sprite, player);
	while (l++ < cub3d->sprite_nb)
	{
		s_tools->sprite_x = (sprite[cub3d->sprite_order[l]].sprite_x + 0.5) -
			player->pos_x;
		s_tools->sprite_y = (sprite[cub3d->sprite_order[l]].sprite_y + 0.5) -
			player->pos_y;
		s_tools->inv_det = 1.0 / (player->plane_x * player->dir_y -
			player->dir_x * player->plane_y);
		s_tools->transform_x = s_tools->inv_det * (player->dir_y *
			s_tools->sprite_x - player->dir_x * s_tools->sprite_y);
		s_tools->transform_y = s_tools->inv_det * (-player->plane_y *
			s_tools->sprite_x + player->plane_x * s_tools->sprite_y);
		s_tools->sprite_screen_x = (int)((cub3d->screen_w / 2) *
			(1 + s_tools->transform_x / s_tools->transform_y));
		calcualte_sprite_h(s_tools, cub3d);
		calcualte_sprite_w(s_tools, cub3d);
		draw_sprite(s_tools, cub3d, text);
	}
	return (1);
}
