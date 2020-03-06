/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:30:05 by agarzon-          #+#    #+#             */
/*   Updated: 2020/03/06 14:18:02 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	extract_data_fc(t_text *text, t_mlx *mlx)
{
	text->text_ptr_floor = mlx_xpm_file_to_image(mlx->mlx_ptr,
		text->text_floor, &text->text_floor_w, &text->text_floor_h);
	text->text_d_floor = (int *)mlx_get_data_addr(text->text_ptr_floor,
		&text->text_floor_bpp, &text->text_floor_sl, &text->text_floor_end);
	text->text_ptr_celing = mlx_xpm_file_to_image(mlx->mlx_ptr,
		text->text_celing, &text->text_celing_w, &text->text_celing_h);
	text->text_d_celing = (int *)mlx_get_data_addr(text->text_ptr_celing,
		&text->text_celing_bpp, &text->text_celing_sl, &text->text_celing_end);
	return (1);
}

int	extract_textures(t_text *text, t_mlx *mlx)
{
	text->text_ptr_n = mlx_xpm_file_to_image(mlx->mlx_ptr, text->text_n,
		&text->text_n_w, &text->text_n_h);
	text->text_d_n = (int *)mlx_get_data_addr(text->text_ptr_n,
		&text->text_n_bpp, &text->text_n_sl, &text->text_n_end);
	text->text_ptr_s = mlx_xpm_file_to_image(mlx->mlx_ptr, text->text_s,
		&text->text_s_w, &text->text_s_h);
	text->text_d_s = (int *)mlx_get_data_addr(text->text_ptr_s,
		&text->text_s_bpp, &text->text_s_sl, &text->text_s_end);
	text->text_ptr_w = mlx_xpm_file_to_image(mlx->mlx_ptr, text->text_w,
		&text->text_w_w, &text->text_w_h);
	text->text_d_w = (int *)mlx_get_data_addr(text->text_ptr_w,
		&text->text_w_bpp, &text->text_w_sl, &text->text_w_end);
	text->text_ptr_e = mlx_xpm_file_to_image(mlx->mlx_ptr, text->text_e,
		&text->text_e_w, &text->text_e_h);
	text->text_d_e = (int *)mlx_get_data_addr(text->text_ptr_e,
		&text->text_e_bpp, &text->text_e_sl, &text->text_e_end);
	if (text->text_floor && text->text_celing)
		extract_data_fc(text, mlx);
	return (1);
}
