/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data_fc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:36:55 by agarzon-          #+#    #+#             */
/*   Updated: 2020/03/06 13:09:01 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	put_fc(t_cub3d *cub3d, t_text *text, t_mlx *mlx, int y)
{
	int x;

	x = 0;
	while (x < cub3d->screen_w)
	{
		text->cell_x = (int)text->floor_x;
		text->cell_y = (int)text->floor_y;
		text->tx = (int)(text->text_floor_w * text->floor_x - text->cell_x) &
			(text->text_floor_w - 1);
		text->ty = (int)(text->text_floor_h * text->floor_y - text->cell_y) &
			(text->text_floor_h - 1);
		text->floor_x += text->floorstep_x;
		text->floor_y += text->floorstep_y;
		text->colorc = *(text->text_d_celing + text->ty * text->text_celing_h +
			text->tx);
		text->colorf = *(text->text_d_floor + text->ty * text->text_floor_h +
			text->tx);
		*(mlx->img_data + y + x * text->text_celing_h /*cub3d->screen_h*/) = text->colorc;
		*(mlx->img_data + text->text_floor_w  /* cub3d->screen_w*/ - ((y - 1) + x)) = text->colorf;
		x++;
	}
	return (1);
}

int	raycast_fc(t_cub3d *cub3d, t_text *text, t_mlx *mlx,
	t_raycast *raycast)
{
	t_player	*player;
	int			y;

	player = cub3d->player;
	y = 0;
	while (y < cub3d->screen_h)
	{
		text->raydir_x0 = raycast->ray_dir_x - player->plane_x;
		text->raydir_y0 = raycast->ray_dir_y - player->plane_y;
		text->raydir_x1 = raycast->ray_dir_x + player->plane_x;
		text->raydir_y1 = raycast->ray_dir_y + player->plane_y;
		text->p = y - cub3d->screen_h / 2;
		text->pos_z = 0.5 * cub3d->screen_h;
		text->row_dist = text->pos_z / text->p;
		text->floorstep_x = text->row_dist * (text->raydir_x1 - text->raydir_x0)
			/ cub3d->screen_w;
		text->floorstep_y = text->row_dist * (text->raydir_y1 - text->raydir_y0)
			/ cub3d->screen_w;
		text->floor_x = player->pos_x + text->row_dist * text->raydir_x0;
		text->floor_y = player->pos_y + text->row_dist * text->raydir_y0;
		put_fc(cub3d, text, mlx, y);
		y++;
	}
	return (1);
}

int	extract_data_fc(t_cub3d *cub3d, t_text *text, t_mlx *mlx)
{
	t_raycast *raycast;

	raycast = cub3d->raycast;
	text->text_ptr_floor = mlx_xpm_file_to_image(mlx->mlx_ptr,
		text->text_floor, &text->text_floor_w, &text->text_floor_h);
	text->text_d_floor = (int *)mlx_get_data_addr(text->text_ptr_floor,
		&text->text_floor_bpp, &text->text_floor_sl, &text->text_floor_end);
	text->text_ptr_celing = mlx_xpm_file_to_image(mlx->mlx_ptr,
		text->text_celing, &text->text_celing_w, &text->text_celing_h);
	text->text_d_celing = (int *)mlx_get_data_addr(text->text_ptr_celing,
		&text->text_celing_bpp, &text->text_celing_sl, &text->text_celing_end);
	raycast_fc(cub3d, text, mlx, raycast);
	return (1);
}
