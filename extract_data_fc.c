/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data_fc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:36:55 by agarzon-          #+#    #+#             */
/*   Updated: 2020/03/02 14:36:57 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	raycast_fc(t_cub3d *cub3d)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < cub3d->screen_h)
	{
		float raydir_x0 = cub3d->raycast->ray_dir_x - cub3d->player->plane_x;
		float raydir_y0 = cub3d->raycast->ray_dir_y - cub3d->player->plane_y;
		float raydir_x1 = cub3d->raycast->ray_dir_x + cub3d->player->plane_x;
		float raydir_y1 = cub3d->raycast->ray_dir_y + cub3d->player->plane_y;
		int p = y - cub3d->screen_h / 2;
		float pos_z = 0.5 * cub3d->screen_h;
		float row_dist = pos_z / p;
		float floorstep_x = row_dist * (raydir_x1 - raydir_x0) / cub3d->screen_w;
		float floorstep_y = row_dist * (raydir_y1 - raydir_y0) / cub3d->screen_w;
		float floor_x = cub3d->player->pos_x + row_dist * raydir_x0;
		float floor_y = cub3d->player->pos_y + row_dist * raydir_y0;
		while (x < cub3d->screen_w)
		{
			int cell_x = (int)floor_x;
			int cell_y = (int)floor_y;
			int tx = (int)(cub3d->text->text_floor_w * (floor_x - cell_x)) * (cub3d->text->text_floor_w - 1);
			int ty = (int)(cub3d->text->text_floor_h * (floor_y - cell_y)) * (cub3d->text->text_floor_h - 1);
			floor_x += floorstep_x;
			floor_y += floorstep_y;
			x++;
		}
		y++;
	}
	
	return (1);
}

int	extract_data_fc(t_cub3d *cub3d)
{
	cub3d->text->text_ptr_floor = mlx_xpm_file_to_image(cub3d->mlx->mlx_ptr,
		cub3d->text->text_floor, &cub3d->text->text_floor_w, &cub3d->text->text_floor_h);
	cub3d->text->text_d_floor = (int *)mlx_get_data_addr
		(cub3d->text->text_ptr_floor, &cub3d->text->text_floor_bpp,
		&cub3d->text->text_floor_sl, &cub3d->text->text_floor_end);
	cub3d->text->text_ptr_celing = mlx_xpm_file_to_image(cub3d->mlx->mlx_ptr,
		cub3d->text->text_celing, &cub3d->text->text_celing_w, &cub3d->text->text_celing_h);
	cub3d->text->text_d_celing = (int *)mlx_get_data_addr
		(cub3d->text->text_ptr_celing, &cub3d->text->text_celing_bpp,
		&cub3d->text->text_celing_sl, &cub3d->text->text_celing_end);
	raycast_fc(cub3d);
	return (1);
}
