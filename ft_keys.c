/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:38:59 by agarzon-          #+#    #+#             */
/*   Updated: 2020/01/31 12:59:00 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		deal_key(int key, t_mlx *tab)
{
	if (key == ESC)
		exit(ESC);	
	return(0);
}

int 	ft_print(int button, int x, int y, t_cub3d *cub3d)
{
	(void)cub3d;
	(void)button;
	printf("posX: %d, posY: %d\n", x, y);
	return (0);
}

int		ft_keys(t_cub3d *cub3d)
{
	mlx_key_hook(cub3d->mlx->window, deal_key, cub3d);
	mlx_mouse_hook(cub3d->mlx->window, ft_print, cub3d);
}

