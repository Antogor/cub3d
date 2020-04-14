/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:38:59 by agarzon-          #+#    #+#             */
/*   Updated: 2020/04/09 21:19:49 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	exit_button(t_cub3d *cub3d)
{
	close_game(cub3d);
	return (1);
}

int	ft_keys(t_cub3d *cub3d)
{
	mlx_hook(cub3d->mlx->window, 17, 0L, exit_button, cub3d);
	return (1);
}
