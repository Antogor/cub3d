/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:19:05 by agarzon-          #+#    #+#             */
/*   Updated: 2020/03/06 11:36:48 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	paint(t_cub3d *cub3d, t_raycast *raycast, t_text *text, t_mlx *mlx)
{
	int		l;
	int		*tx;
	double	step;
	double	pos;
	int		y;

	l = 0;
	y = raycast->draw_start;
	step = 1.0 * text->text_h / raycast->line_height;
	pos = (raycast->draw_start - cub3d->screen_h / 2 + raycast->line_height / 2)
		* step;
	tx = text->text_dat;
	/*while (l < raycast->draw_start)
	{
		*(mlx->img_data + raycast->x + l * mlx->size_l / 4) =
			cub3d->color->celling;
		l++;
	}*/
//	l += paint_text(l, cub3d);
	while (y < raycast->draw_end)
	{
		//int color = *(tx + text->text + (int)pos * text->text_sl / 4);
		//color = (color >> 1) & 8355711;
		*(mlx->img_data + raycast->x + y * mlx->size_l / 4) = 
			*(tx + text->text + (int)pos * text->text_sl / 4);
		pos += step;
		y++;
	}
/*	l = raycast->draw_end;
	while (l < cub3d->screen_h)
	{
		*(mlx->img_data + raycast->x + l * mlx->size_l / 4) =
			cub3d->color->floor;
		l++;
	}*/
}
