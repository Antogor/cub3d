/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:30:05 by agarzon-          #+#    #+#             */
/*   Updated: 2020/03/09 11:37:42 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	extract_data_sprite(t_text *text, t_mlx *mlx)
{
	
	if (!(text->text_ptr_sprite = mlx_xpm_file_to_image(mlx->mlx_ptr,
		text->text_sprite, &text->text_sprite_w, &text->text_sprite_h)))
		ft_error("Fallo al cargar textura sprite");
	text->text_d_sprite = (int *)mlx_get_data_addr(text->text_ptr_sprite,
		&text->text_sprite_bpp, &text->text_sprite_sl, &text->text_sprite_end);
	return (1);
}

int	extract_data_fc(t_text *text, t_mlx *mlx)
{
	if (!(text->text_ptr_floor = mlx_xpm_file_to_image(mlx->mlx_ptr,
		text->text_floor, &text->text_floor_w, &text->text_floor_h)))
		ft_error("Fallo al cargar textura floor");
	text->text_d_floor = (int *)mlx_get_data_addr(text->text_ptr_floor,
		&text->text_floor_bpp, &text->text_floor_sl, &text->text_floor_end);
	if (!(text->text_ptr_celing = mlx_xpm_file_to_image(mlx->mlx_ptr,
		text->text_celing, &text->text_celing_w, &text->text_celing_h)))
		ft_error("Fallo al cargar textura celing");
	text->text_d_celing = (int *)mlx_get_data_addr(text->text_ptr_celing,
		&text->text_celing_bpp, &text->text_celing_sl, &text->text_celing_end);
	return (1);
}

int	extract_textures(t_text *text, t_mlx *mlx)
{
	if (!(text->text_ptr_n = mlx_xpm_file_to_image(mlx->mlx_ptr, text->text_n,
		&text->text_n_w, &text->text_n_h)))
		ft_error("Fallo al cargar textura NO");
	text->text_d_n = (int *)mlx_get_data_addr(text->text_ptr_n,
		&text->text_n_bpp, &text->text_n_sl, &text->text_n_end);
	if (!(text->text_ptr_s = mlx_xpm_file_to_image(mlx->mlx_ptr, text->text_s,
		&text->text_s_w, &text->text_s_h)))
		ft_error("Fallo al cargar textura SO");
	text->text_d_s = (int *)mlx_get_data_addr(text->text_ptr_s,
		&text->text_s_bpp, &text->text_s_sl, &text->text_s_end);
	if (!(text->text_ptr_w = mlx_xpm_file_to_image(mlx->mlx_ptr, text->text_w,
		&text->text_w_w, &text->text_w_h)))
		ft_error("Fallo al cargar textura WE");
	text->text_d_w = (int *)mlx_get_data_addr(text->text_ptr_w,
		&text->text_w_bpp, &text->text_w_sl, &text->text_w_end);
	if (!(text->text_ptr_e = mlx_xpm_file_to_image(mlx->mlx_ptr, text->text_e,
		&text->text_e_w, &text->text_e_h)))
		ft_error("Fallo al cargar textura EA");
	text->text_d_e = (int *)mlx_get_data_addr(text->text_ptr_e,
		&text->text_e_bpp, &text->text_e_sl, &text->text_e_end);
	if (text->text_floor && text->text_celing)
		extract_data_fc(text, mlx);
	extract_data_sprite(text, mlx);
	return (1);
}
