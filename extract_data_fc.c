/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data_fc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:36:55 by agarzon-          #+#    #+#             */
/*   Updated: 2020/03/04 14:28:02 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	raycast_fc(t_cub3d *cub3d, t_text *text, t_mlx *mlx,
	t_raycast *raycast, t_player *player)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < cub3d->screen_h)
	{
		float raydir_x0 = raycast->ray_dir_x - player->plane_x;
		float raydir_y0 = raycast->ray_dir_y - player->plane_y;
		float raydir_x1 = raycast->ray_dir_x + player->plane_x;
		float raydir_y1 = raycast->ray_dir_y + player->plane_y;
		int p = y - cub3d->screen_h / 2;
		float pos_z = 0.5 * cub3d->screen_h;
		float row_dist = pos_z / p;
		float floorstep_x = row_dist * (raydir_x1 - raydir_x0) / cub3d->screen_w;
		float floorstep_y = row_dist * (raydir_y1 - raydir_y0) / cub3d->screen_w;
		float floor_x = player->pos_x + row_dist * raydir_x0;	
		float floor_y = player->pos_y + row_dist * raydir_y0;
		while (x < cub3d->screen_w)
		{
			int cell_x = (int)floor_x;
			int cell_y = (int)floor_y;
			int tx = (int)(text->text_floor_w) * (floor_x - cell_x);// * (text->text_floor_w - 1);
			int ty = (int)(text->text_floor_h) * (floor_y - cell_y);// * (text->text_floor_h - 1);
			floor_x += floorstep_x;
			floor_y += floorstep_y;
//			*(mlx->img_data + ty + tx )= *(text->text_d_floor);//* text->text_floor_sl / 4); //cub3d->color->celling;
		//	mlx->img_data =  text->text_d_floor + ty + tx * text->text_floor_w;
	//		*(mlx->img_data) = *(text->text_d_floor + y  *  text->text_floor_sl / 4);//*(text->text_d_floor);
			//*(mlx->img_data + y * mlx->size_l / 4) = cub3d->color->celling;//*(text->text_d_floor + tx + (int)pos_z * text->text_floor_sl / 4);
			x++;
		}
		y++;
	}
	return (1);
}

int	extract_data_fc(t_cub3d *cub3d, t_text *text, t_mlx *mlx)
{
	text->text_ptr_floor = mlx_xpm_file_to_image(mlx->mlx_ptr,
		text->text_floor, &text->text_floor_w, &text->text_floor_h);
	text->text_d_floor = (int *)mlx_get_data_addr
		(text->text_ptr_floor, &text->text_floor_bpp,
		&text->text_floor_sl, &text->text_floor_end);
	text->text_ptr_celing = mlx_xpm_file_to_image(mlx->mlx_ptr,
		text->text_celing, &text->text_celing_w, &text->text_celing_h);
	text->text_d_celing = (int *)mlx_get_data_addr
		(text->text_ptr_celing, &text->text_celing_bpp,
		&text->text_celing_sl, &text->text_celing_end);
	raycast_fc(cub3d, cub3d->text, cub3d->mlx, cub3d->raycast, cub3d->player);
	return (1);
}
