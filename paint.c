/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:19:05 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/24 12:52:26 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		paint_text(int l, t_cub3d *cub3d)
{
	while (l < cub3d->raycast->draw_end)
	{
		if (cub3d->raycast->side == 0)
			*(cub3d->mlx->img_data + cub3d->raycast->x + l *
				cub3d->mlx->size_l / 4) = cub3d->color->color_g;
		else
			*(cub3d->mlx->img_data + cub3d->raycast->x + l *
				cub3d->mlx->size_l / 4) = cub3d->color->color_w;
		l++;
	}
	return (l);
}

void	paint(t_cub3d *cub3d)
{
	int		l;
	int		*text;
	double	step;
	double	pos;

	l = 0;
	cub3d->color->color_g = create_trgb(0, 0, 120, 100);
	cub3d->color->color_w = create_trgb(0, 100, 0, 255);
	step = 1.0 * cub3d->text->text_h / cub3d->raycast->line_height;
	pos = (cub3d->raycast->draw_start - cub3d->screen_h / 2 + cub3d->raycast->line_height / 2) * step;
	text = cub3d->text->text_dat;
	while (l < cub3d->raycast->draw_start)
	{
		*(cub3d->mlx->img_data + cub3d->raycast->x + l *
			cub3d->mlx->size_l / 4) = cub3d->color->celling;
		l++;
	}
//	l += paint_text(l, cub3d);
	while (l < cub3d->raycast->draw_end)
	{
		*(cub3d->mlx->img_data + cub3d->raycast->x + l *
			cub3d->mlx->size_l / 4) = *(text + cub3d->text->text +
			(int)pos * cub3d->text->text_sl / 4);
		pos += step;
		/*if (cub3d->raycast->side == 0)
			*(cub3d->mlx->img_data + cub3d->raycast->x + l *
				cub3d->mlx->size_l / 4) = cub3d->color->color_g;
		else
			*(cub3d->mlx->img_data + cub3d->raycast->x + l *
				cub3d->mlx->size_l / 4) = cub3d->color->color_w;*/
		l++;
	}
	while (l < cub3d->screen_h)
	{
		*(cub3d->mlx->img_data + cub3d->raycast->x + l *
			cub3d->mlx->size_l / 4) = cub3d->color->floor;
		l++;
	}
}
