/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:30:05 by agarzon-          #+#    #+#             */
/*   Updated: 2020/06/05 19:17:19 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	extract_data_sprite(t_tx *t, t_mlx mlx)
{
	if (!(t->s.p_s = mlx_xpm_file_to_image(mlx.ptr,
		t->s.sprite, &t->s.w, &t->s.h)))
		ft_error("FAIL to charge text sprite");
	t->s.data = (int *)mlx_get_data_addr(t->s.p_s,
		&t->s.bpp, &t->s.sl, &t->s.end);
	return (0);
}

int	extract_data_fc(t_tx *t, t_mlx mlx)
{
	if (!(t->f.p_f = mlx_xpm_file_to_image(mlx.ptr,
		t->f.floor, &t->f.w, &t->f.h)))
		ft_error("FAIL to charge text floor");
	t->f.data = (int *)mlx_get_data_addr(t->f.p_f,
		&t->f.bpp, &t->f.sl, &t->f.end);
	if (!(t->c.p_c = mlx_xpm_file_to_image(mlx.ptr,
		t->c.celing, &t->c.w, &t->c.h)))
		ft_error("FAIL to charge text celing");
	t->c.data = (int *)mlx_get_data_addr(t->c.p_c,
		&t->c.bpp, &t->c.sl, &t->c.end);
	return (0);
}

int	extract_textures(t_tx *t, t_mlx mlx)
{
	if (!(t->walls.p_no = mlx_xpm_file_to_image(mlx.ptr, t->walls.north,
		&t->walls.no_w, &t->walls.no_h)))
		ft_error("FAIL to charge text NO");
	t->walls.data_no = (int *)mlx_get_data_addr(t->walls.p_no,
		&t->walls.no_bpp, &t->walls.no_sl, &t->walls.no_end);
	if (!(t->walls.p_so = mlx_xpm_file_to_image(mlx.ptr, t->walls.south,
		&t->walls.so_w, &t->walls.so_h)))
		ft_error("FAIL to charge text SO");
	t->walls.data_so = (int *)mlx_get_data_addr(t->walls.p_so,
		&t->walls.so_bpp, &t->walls.so_sl, &t->walls.so_end);
	if (!(t->walls.p_we = mlx_xpm_file_to_image(mlx.ptr, t->walls.west,
		&t->walls.we_w, &t->walls.we_h)))
		ft_error("FAIL to charge text WE");
	t->walls.data_we = (int *)mlx_get_data_addr(t->walls.p_we,
		&t->walls.we_bpp, &t->walls.we_sl, &t->walls.we_end);
	if (!(t->walls.p_ea = mlx_xpm_file_to_image(mlx.ptr, t->walls.east,
		&t->walls.ea_w, &t->walls.ea_h)))
		ft_error("FAIL to charge text EA");
	t->walls.data_ea = (int *)mlx_get_data_addr(t->walls.p_ea,
		&t->walls.ea_bpp, &t->walls.ea_sl, &t->walls.ea_end);
	if (t->f.floor && t->c.celing)
		extract_data_fc(t, mlx);
	extract_data_sprite(t, mlx);
	return (0);
}
