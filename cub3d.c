/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:14:36 by agarzon-          #+#    #+#             */
/*   Updated: 2020/03/06 14:20:04 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		init_game(int argc, char **argv, t_cub3d *cub3d)
{
	if (argc == 2)
	{
		if (ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])))
		{
			if (ft_map(argv, cub3d) < 0)
				return (-1);
		}
		return (0);
	}
	if (argc == 3)
	{
		if (ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])))
		{
			if (ft_map(argv, cub3d) < 0)
				return (-1);
		}
		if (ft_strnstr(argv[2], "--save", ft_strlen(argv[2])))
			printf("save");
		return (0);
	}
	return (-1);
}

int		run_game(t_cub3d *cub3d)
{
	movement(cub3d);
	ft_keys(cub3d);
	raycast_fc(cub3d, cub3d->text, cub3d->mlx, cub3d->player);
	raycasting(cub3d, cub3d->raycast, cub3d->player);
	mlx_put_image_to_window(cub3d->mlx->mlx_ptr,
		cub3d->mlx->window, cub3d->mlx->img, 0, 0);
	return (0);
}

void	pre_run(t_cub3d *cub3d, t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx_ptr,
		cub3d->screen_w, cub3d->screen_h, "cub3D");
	mlx->img = mlx_new_image(mlx->mlx_ptr, cub3d->screen_w, cub3d->screen_h);
	mlx->img_data = (int*)mlx_get_data_addr(mlx->img,
		&mlx->bpp, &mlx->size_l, &mlx->endian);
	extract_textures(cub3d->text, cub3d->mlx);
	mlx_loop_hook(mlx->mlx_ptr, run_game, cub3d);
	mlx_loop(mlx->mlx_ptr);
}

int		main(int argc, char **argv)
{
	t_cub3d *cub3d;

	cub3d = (t_cub3d *)malloc(sizeof(t_cub3d));
	cub3d->player = (t_player *)malloc(sizeof(t_player));
	cub3d->raycast = (t_raycast *)malloc(sizeof(t_raycast));
	cub3d->color = (t_color *)malloc(sizeof(t_color));
	cub3d->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	cub3d->text = (t_text *)malloc(sizeof(t_text));
	if (init_game(argc, argv, cub3d) < 0 || argc < 2)
		perror("Los dioses no lo permiten");
	else
		pre_run(cub3d, cub3d->mlx);
	free(cub3d->player);
	free(cub3d->mlx);
	free(cub3d->raycast);
	free(cub3d->color);
	free(cub3d->text);
	free(cub3d);
	return (0);
}
