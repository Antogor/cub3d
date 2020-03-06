/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 12:21:12 by agarzon-          #+#    #+#             */
/*   Updated: 2020/03/04 15:18:59 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	calculate_text(t_text *text, t_raycast *raycast)
{
	text->text = (int)(raycast->wall_x * (double)text->text_wi);
	if (raycast->side == 0 && raycast->ray_dir_x > 0)
		text->text = (text->text_wi - text->text - 1);
	if (raycast->side == 1 && raycast->ray_dir_y < 0)
		text->text = (text->text_wi - text->text - 1);
	return (1);
}

int	choose_we(t_text *text)
{
	if (text->text_wall_dir == 'E')
	{
		text->text_dat = text->text_d_e;
		text->text_sl = text->text_e_sl;
		text->text_h = text->text_e_h;
		text->text_wi = text->text_e_w;
	}
	else if (text->text_wall_dir == 'W')
	{
		text->text_dat = text->text_d_w;
		text->text_sl = text->text_w_sl;
		text->text_h = text->text_w_h;
		text->text_wi = text->text_w_w;
	}
	return (1);
}

int	choose_texture(t_cub3d *cub3d, t_text *text)
{
	if (text->text_wall_dir == 'N')
	{
		text->text_dat = text->text_d_n;
		text->text_sl = text->text_n_sl;
		text->text_h = text->text_n_h;
		text->text_wi = text->text_n_w;
	}
	else if (text->text_wall_dir == 'S')
	{
		text->text_dat = text->text_d_s;
		text->text_sl = text->text_s_sl;
		text->text_h = text->text_s_h;
		text->text_wi = text->text_s_w;
	}
	choose_we(text);
	calculate_text(text, cub3d->raycast);
	return (1);
}