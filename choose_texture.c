/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 12:21:12 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/26 12:21:14 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int calculate_text(t_cub3d *cub3d)
{
	cub3d->text->text = cub3d->raycast->wall_x *
			(cub3d->text->text_sl / 4);
	if (cub3d->raycast->side == 0 && cub3d->raycast->ray_dir_x > 0)
		cub3d->text->text = ((cub3d->text->text_sl / 4) -
			cub3d->text->text - 1);
	if (cub3d->raycast->side == 1 && cub3d->raycast->ray_dir_y < 0)
		cub3d->text->text = ((cub3d->text->text_sl / 4) -
		cub3d->text->text - 1);
	return (1);
}

int choose_we(t_cub3d *cub3d)
{
	/*	else if (cub3d->text->text_wall_dir == 'E')
	{
		cub3d->text->text_dat = cub3d->text->text_d_e;
		cub3d->text->text_sl = cub3d->text->text_e_sl;
		cub3d->text->text_h = cub3d->text->text_e_h;
	}
	else if (cub3d->text->text_wall_dir == 'W')
	{
		cub3d->text->text_dat = cub3d->text->text_d_w;
		cub3d->text->text_sl = cub3d->text->text_w_sl;
		cub3d->text->text_h = cub3d->text->text_w_h;
	}*/
	return (1);
}

int	choose_texture(t_cub3d *cub3d)
{
	if (cub3d->text->text_wall_dir == 'N')
	{
		cub3d->text->text_dat = cub3d->text->text_d_n;
		cub3d->text->text_sl = cub3d->text->text_n_sl;
		cub3d->text->text_h = cub3d->text->text_n_h;
	}
	else if (cub3d->text->text_wall_dir == 'S')
	{
		cub3d->text->text_dat = cub3d->text->text_d_s;
		cub3d->text->text_sl = cub3d->text->text_s_sl;
		cub3d->text->text_h = cub3d->text->text_s_h;
	}
	choose_we(cub3d);
	calculate_text(cub3d);
	return (1);
}
