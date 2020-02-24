/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:38:59 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/24 12:53:20 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_button(int key, t_cub3d *cub3d)
{
	exit(1);
	return (1);
}

int	ft_print(int button, int x, int y, t_cub3d *cub3d)
{
	(void)cub3d;
	printf("button %d\n", button);
	printf("posX: %d, posY: %d\n", x, y);
	return (1);
}

int	ft_keys(t_cub3d *cub3d)
{
	mlx_hook(cub3d->mlx->window, 17, 1L << 0, exit_button, cub3d);
	mlx_mouse_hook(cub3d->mlx->window, ft_print, cub3d);
	return (1);
}
