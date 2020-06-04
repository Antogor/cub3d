/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:19:05 by agarzon-          #+#    #+#             */
/*   Updated: 2020/06/04 13:25:37 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	paint(t_cub3d *cub3d, t_raycast rc, t_text *text, t_mlx *mlx)
{
	int		*tx;
	double	step;
	double	pos;
	int		y;

	y = rc.draw_start;
	step = 1.0 * text->text_h / rc.line_height;
	pos = (rc.draw_start - cub3d->screen_h / 2 + rc.line_height / 2)
		* step;
	tx = text->text_dat;
	while (y < rc.draw_end)
	{
		text->colortxt = tx[text->text + (int)pos * text->text_sl / 4];
		if (rc.side == 1)
			text->colortxt = text->colortxt >> 1 & 8355711;
		mlx->img_data[rc.x + y * mlx->size_l / 4] = text->colortxt;
		pos += step;
		y++;
	}
}
