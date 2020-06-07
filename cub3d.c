/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:14:36 by agarzon-          #+#    #+#             */
/*   Updated: 2020/06/07 16:43:28 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		open_cub(int argc, char **argv, t_cub3d *c)
{
	if (argc == 2)
	{
		if (ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])))
			ft_map(argv, c);
		else
			ft_error("Insert map");
	}
	else if (argc == 3)
	{
		if (ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])) &&
			ft_strnstr(argv[2], "--save", ft_strlen(argv[2])))
		{
			ft_map(argv, c);
			save_bitmap("screen_shoot.bmp", c);
		}
		else
			ft_error("Insert map and command --save");
		return (0);
	}
	return (0);
}

int		run_game(t_cub3d *c)
{
	movement(c);
	ft_events(c);
	raycast_fc(c, &c->tx.tool, &c->mlx, c->pl);
	raycasting(c, c->pl);
	raycast_sprite(c, c->pl);
	mlx_put_image_to_window(c->mlx.ptr,
		c->mlx.win, c->mlx.img, 0, 0);
	return (0);
}

void	init_mlx(t_cub3d *c)
{
	if (!(c->mlx.ptr = mlx_init()))
		ft_error("FAIL to init mlx");
	if (!(c->mlx.img = mlx_new_image(c->mlx.ptr,
		c->screen_w, c->screen_h)))
		ft_error("FAIL to create image");
	c->mlx.i_data = (int*)mlx_get_data_addr(c->mlx.img,
		&c->mlx.bpp, &c->mlx.size_l, &c->mlx.endian);
	extract_textures(&c->tx, c->mlx);
	c->mlx.win = mlx_new_window(c->mlx.ptr,
		c->screen_w, c->screen_h, "cub3D");
	mlx_loop_hook(c->mlx.ptr, run_game, c);
	mlx_loop(c->mlx.ptr);
}

int		main(int argc, char **argv)
{
	t_cub3d *cub3d;

	if (!(cub3d = (t_cub3d *)malloc(sizeof(t_cub3d))))
		ft_error("Couldn't reserve memory");
	if (argc >= 2)
	{
		open_cub(argc, argv, cub3d);
		init_mlx(cub3d);
	}
	else
		ft_error("Not a valid command");
	return (0);
}
