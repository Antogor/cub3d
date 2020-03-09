/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:53:50 by agarzon-          #+#    #+#             */
/*   Updated: 2020/03/09 12:34:28 by agarzon-         ###   ########.fr       */
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
	while(l < cub3d->sprite_nb)
	{
		
		sprite_dist[l] = ((player->pos_x - sprite[l].sprite_x) * (player->pos_x - sprite[l].sprite_x) + (player->pos_y - sprite[l].sprite_y) * (player->pos_y - sprite[l].sprite_y));
		cub3d->sprite_order[l] = l;
		l++;
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

int	raycast_sprite(t_cub3d *cub3d, t_sprite *sprite, t_text *text,
					t_player *player)
{
	int l;

	l = 0;
	choose_sprite(cub3d, sprite, player);
	while (l < cub3d->sprite_nb)
	{
		double	sprite_x = sprite[cub3d->sprite_order[l]].sprite_x - player->pos_x;
		double	sprite_y = sprite[cub3d->sprite_order[l]].sprite_y - player->pos_y;
		double	inv_det = 1.0 / (player->plane_x * player->dir_y - player->dir_x * player->plane_y);
		double	transform_x = inv_det * (player->dir_y * sprite_x - player->dir_x * sprite_y);
		double	transform_y = inv_det * (-player->plane_y * sprite_x + player->plane_x * sprite_y);
		int		sprite_screen_x = (int)(cub3d->screen_w / 2) * (int)(1 + transform_x / transform_y);
		int		sprite_h = fabs((int)cub3d->screen_h / transform_y);
		int		draw_start_y = -sprite_h / 2 + cub3d->screen_h / 2;
		if (draw_start_y < 0)
			draw_start_y = 0;
		int		draw_end_y = sprite_h / 2 + cub3d->screen_h / 2;
		if (draw_end_y < 0)
			draw_end_y = cub3d->screen_h - 1;
		int		sprite_w = fabs((int)cub3d->screen_h / transform_y);
		int		draw_start_x = -sprite_w / 2 + sprite_screen_x;
		if (draw_start_x < 0)
			draw_start_x = 0;
		int		draw_end_x = sprite_w / 2 + sprite_screen_x;
		if (draw_end_x < 0)
			draw_end_x = cub3d->screen_w - 1;
		int		stripe = draw_start_x;
		while (stripe < draw_end_x)
		{
			int		tex_x = (int)(256 * (stripe - (-sprite_w / 2 + sprite_screen_x)) * text->text_sprite_w / sprite_w) / 256;
			if(transform_y > 0 && stripe > 0 && stripe < cub3d->screen_w && transform_y < cub3d->z_buffer[stripe])
			{
				int	y = draw_start_y;
				while (y < draw_end_y)
				{
					int	d = (y) * 256 - cub3d->screen_h * 128 + sprite_h * 128;
					int	tex_y = ((d * text->text_sprite_h) / sprite_h / 256);
					if(text->text_d_sprite[tex_x + tex_y * text->text_sprite_sl / 4])
						cub3d->mlx->img_data[stripe + y * cub3d->mlx->size_l / 4] = text->text_d_sprite[tex_x + tex_y * text->text_sprite_sl / 4];
					y++;
				}
				
			}
			stripe++;
		}
		l++;
	}
	return (1);
}