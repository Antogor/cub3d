/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 20:46:00 by agarzon-          #+#    #+#             */
/*   Updated: 2020/04/09 20:47:51 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	int_to_char(unsigned char *c, int a)
{
	c[0] = (unsigned char)(a);
	c[1] = (unsigned char)(a >> 8);
	c[2] = (unsigned char)(a >> 16);
	c[3] = (unsigned char)(a >> 24);
}

int		bmp_header(int fd, int w, int h)
{
	unsigned char	header[54];
	int				file_size;

	file_size = 54 + 4 * w * h;
	ft_bzero(header, 54);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	int_to_char(header + 2, file_size);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	int_to_char(header + 18, w);
	int_to_char(header + 22, h);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	if (!(write(fd, header, 54)))
		return (0);
	return (1);
}

int		write_bmp(int fd, t_mlx *mlx, t_cub3d *cub)
{
	int	x;
	int	y;
	int	color;

	y = cub->screen_h - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < cub->screen_w)
		{
			color = mlx->img_data[x + y * mlx->size_l / 4];
			if (!(write(fd, &color, 3)))
				return (0);
			x++;
		}
		y--;
	}
	return (1);
}

void	init_save(t_cub3d *cub)
{
	if (!(cub->mlx->mlx_ptr = mlx_init()))
		ft_error("FAIL to init mlx");
	if (!(cub->mlx->img = mlx_new_image(cub->mlx->mlx_ptr, cub->screen_w,
		cub->screen_h)))
		ft_error("FAIL to create image");
	cub->mlx->img_data = (int*)mlx_get_data_addr(cub->mlx->img,
		&cub->mlx->bpp, &cub->mlx->size_l, &cub->mlx->endian);
	extract_textures(cub->text, cub->mlx);
	raycast_fc(cub, cub->text, cub->mlx, cub->player);
	raycasting(cub, cub->raycast, cub->player);
	raycast_sprite(cub, cub->text, cub->player);
}

void	save_bitmap(const char *file_name, t_cub3d *cub)
{
	int		fd;

	init_save(cub);
	if (!(fd = open(file_name, O_WRONLY | O_CREAT, 0777 | O_TRUNC | O_APPEND)))
		ft_error("FAIL to open/create screenshoot.bmp");
	if (!(bmp_header(fd, cub->screen_w, cub->screen_h)))
		ft_error("FAIL to create screenshoot");
	if (!(write_bmp(fd, cub->mlx, cub)))
		ft_error("FAIL to create screenshoot");
	close(fd);
	close_game(cub);
}
