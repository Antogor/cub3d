/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:14:36 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/12 16:41:45 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int run_game(t_cub3d *cub3d)
{
	movement(cub3d);
	raycasting(cub3d);

	return (0);

}

int main (int argc, char **argv)
{
	t_cub3d *cub3d;

	cub3d = (t_cub3d *)malloc(sizeof(t_cub3d));
	cub3d->player = (t_player *)malloc(sizeof(t_player));
	cub3d->raycast = (t_raycast *)malloc(sizeof(t_raycast));
	cub3d->color = (t_color *)malloc(sizeof(t_color));
	cub3d->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	cub3d->mlx->mlx_ptr = mlx_init();
    cub3d->mlx->window = mlx_new_window(cub3d->mlx->mlx_ptr, screenWidth, screenHeight, "cub3D");
	cub3d->mlx->img = mlx_new_image(cub3d->mlx->mlx_ptr, 520, 360);
    cub3d->mlx->img_data = (int*)mlx_get_data_addr(cub3d->mlx->img, &cub3d->mlx->bpp, &cub3d->mlx->size_l, &cub3d->mlx->endian);
	mlx_loop_hook(cub3d->mlx->mlx_ptr, run_game, cub3d);
	mlx_loop(cub3d->mlx->mlx_ptr);
	/*
	(void)argc;
	tab = (t_cub3d *)malloc(sizeof(t_cub3d *));
	fd = open(argv[1], O_RDONLY);
	ft_map(tab);
	if (argc == 0 || argc == 0)
	{
		if (ft_strncmp(argv[1], ".cub", 100) == 0)
		
		if (ft_strncmp(argv[2], "--save", 6) == 0)
			printf("FUNCION GUARDAR BMP");
	}
	else
		perror("No map");
	free(tab);
	tab = NULL;
//	system("leaks");*/
	free(cub3d->player);
	free(cub3d->mlx);
	free(cub3d->raycast);
	free(cub3d->color);
	free(cub3d);
	system("leaks Raytest");
	return (0);
}
	
