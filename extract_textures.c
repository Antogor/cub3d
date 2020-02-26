/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:30:05 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/24 12:54:21 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	extract_textures(t_cub3d *cub3d)
{
	cub3d->text->text_ptr_n = mlx_xpm_file_to_image(cub3d->mlx->mlx_ptr,
		cub3d->text->text_n, &cub3d->text->text_n_w, &cub3d->text->text_n_h);
	cub3d->text->text_d_n = (int *)mlx_get_data_addr(cub3d->text->text_ptr_n,
		&cub3d->text->text_n_bpp, &cub3d->text->text_n_sl,
		&cub3d->text->text_n_end);
	cub3d->text->text_ptr_s = mlx_xpm_file_to_image(cub3d->mlx->mlx_ptr,
		cub3d->text->text_s, &cub3d->text->text_s_w, &cub3d->text->text_s_h);
	cub3d->text->text_d_s = (int *)mlx_get_data_addr(cub3d->text->text_ptr_s,
		&cub3d->text->text_s_bpp, &cub3d->text->text_s_sl,
		&cub3d->text->text_s_end);
	cub3d->text->text_ptr_w = mlx_xpm_file_to_image(cub3d->mlx->mlx_ptr,
		cub3d->text->text_w, &cub3d->text->text_w_w, &cub3d->text->text_w_h);
	cub3d->text->text_d_w = (int *)mlx_get_data_addr(cub3d->text->text_ptr_w,
		&cub3d->text->text_w_bpp, &cub3d->text->text_w_sl,
		&cub3d->text->text_w_end);
	cub3d->text->text_ptr_e = mlx_xpm_file_to_image(cub3d->mlx->mlx_ptr,
		cub3d->text->text_e, &cub3d->text->text_e_w, &cub3d->text->text_e_h);
	cub3d->text->text_d_e = (int *)mlx_get_data_addr(cub3d->text->text_ptr_e,
		&cub3d->text->text_e_bpp, &cub3d->text->text_e_sl,
		&cub3d->text->text_e_end);
	return (1);
}
