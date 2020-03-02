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
	int		*text;
	double	step;
	double	pos;

	step = 1.0 * cub3d->text->text_h / cub3d->raycast->line_height;
	pos = (cub3d->raycast->draw_start - cub3d->screen_h / 2 +
		cub3d->raycast->line_height / 2) * step;
	text = cub3d->text->text_dat;
	while (l < cub3d->raycast->draw_end)
	{
		*(cub3d->mlx->img_data + cub3d->raycast->x + l *
			cub3d->mlx->size_l / 4) = *(text + cub3d->text->text +
			(int)pos * cub3d->text->text_sl / 4);
		pos += step;
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
	int 	y;

	l = 0;
	y = cub3d->raycast->draw_start;
	step = 1.0 * cub3d->text->text_h / cub3d->raycast->line_height;
	pos = (cub3d->raycast->draw_start - cub3d->screen_h / 2 +
		cub3d->raycast->line_height / 2) * step;
	text = cub3d->text->text_dat;
	while (l < cub3d->raycast->draw_start)
	{
		/**(cub3d->mlx->img_data + cub3d->raycast->x + l *
			cub3d->mlx->size_l / 4) = cub3d->color->celling;*/
		l++;
	}
//	l += paint_text(l, cub3d);
	while (y < cub3d->raycast->draw_end)
	{
		*(cub3d->mlx->img_data + cub3d->raycast->x + y *
			cub3d->mlx->size_l / 4) = *(text + cub3d->text->text +
			(int)pos * cub3d->text->text_sl / 4);
		pos += step;
		y++;
	}
/*	while (l < cub3d->screen_h)
	{
		*(cub3d->mlx->img_data + cub3d->raycast->x + l *
			cub3d->mlx->size_l / 4) = cub3d->color->floor;
		l++;
	}*/
}
