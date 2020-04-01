		/* ************************************************************************** */
		/*                                                                            */
		/*                                                        :::      ::::::::   */
		/*   raycast_fc.c                                       :+:      :+:    :+:   */
		/*                                                    +:+ +:+         +:+     */
		/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
		/*                                                +#+#+#+#+#+   +#+           */
		/*   Created: 2020/03/02 14:36:55 by agarzon-          #+#    #+#             */
		/*   Updated: 2020/03/09 11:14:23 by agarzon-         ###   ########.fr       */
		/*                                                                            */
		/* ************************************************************************** */

#include "../cub3d.h"

void	choose_color(t_color *color, t_text *text, int txc, int tyc)
{
	if (text->text_floor && text->text_celing)
	{
		text->colorc = (int)text->text_d_celing[text->text_celing_w * tyc +
			txc];
		text->colorc = text->colorc >> 1 & 8355711;
		text->colorf = (int)text->text_d_floor[text->text_floor_w * text->ty +
			text->tx];
		text->colorf = text->colorf >> 1 & 8355711;
	}
	else
	{
		text->colorc = color->celling;
		text->colorf = color->floor;
	}
}

void	put_fc(t_cub3d *cub3d, t_text *text, t_mlx *mlx, int *y)
{
	int x;
	int txc;
	int tyc;

	x = 0;
	while (x < cub3d->screen_w)
	{
		text->cell_x = (int)text->floor_x;
		text->cell_y = (int)text->floor_y;
		text->tx = (int)(128 * (text->floor_x - text->cell_x)) &
			(128 - 1);
		text->ty = (int)(128 * (text->floor_y - text->cell_y)) &
			(128 - 1);
		txc = (int)(128 * (text->floor_x - text->cell_x)) &
			(128 - 1);
		tyc = (int)(128 * (text->floor_y - text->cell_y)) &
			(128 - 1);
		text->floor_x += text->floorstep_x;
		text->floor_y += text->floorstep_y;
		choose_color(cub3d->color, text, txc, tyc);
		mlx->img_data[*y * cub3d->screen_w + x] = text->colorf;
		mlx->img_data[(cub3d->screen_h - *y - 1) * cub3d->screen_w + x] =
			text->colorc;
		x++;
	}
}

int		raycast_fc(t_cub3d *cub3d, t_text *text, t_mlx *mlx,
	t_player *player)
{
	int			y;

	y = cub3d->screen_h / 2 - 1;
	while (y < cub3d->screen_h)
	{
		text->raydir_x0 = player->dir_x - player->plane_x;
		text->raydir_y0 = player->dir_y - player->plane_y;
		text->raydir_x1 = player->dir_x + player->plane_x;
		text->raydir_y1 = player->dir_y + player->plane_y;
		text->p = y - cub3d->screen_h / 2;
		text->pos_z = 0.5 * cub3d->screen_h;
		text->row_dist = text->pos_z / text->p;
		text->floorstep_x = text->row_dist * (text->raydir_x1 - text->raydir_x0)
			/ cub3d->screen_w;
		text->floorstep_y = text->row_dist * (text->raydir_y1 - text->raydir_y0)
			/ cub3d->screen_w;
		text->floor_x = player->pos_x + text->row_dist * text->raydir_x0;
		text->floor_y = player->pos_y + text->row_dist * text->raydir_y0;
		put_fc(cub3d, text, mlx, &y);
		y++;
		
	}
	return (1);
}
