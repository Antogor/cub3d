/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:19:05 by agarzon-          #+#    #+#             */
/*   Updated: 2020/06/05 19:16:23 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	paint(t_raycast rc, t_tx *t, t_mlx *ml, int h)
{
	int		*tx;
	double	step;
	double	pos;
	int		y;

	y = rc.draw_start;
	step = 1.0 * t->h / rc.line_height;
	pos = (rc.draw_start - h / 2 + rc.line_height / 2) * step;
	tx = t->data;
	while (y < rc.draw_end)
	{
		t->colortx = tx[t->txt + (int)pos * t->sl / 4];
		if (rc.side == 1)
			t->colortx = t->colortx >> 1 & 8355711;
		ml->i_data[rc.x + y * ml->size_l / 4] = t->colortx;
		pos += step;
		y++;
	}
}
