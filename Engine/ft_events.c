/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:38:59 by agarzon-          #+#    #+#             */
/*   Updated: 2020/06/05 18:55:27 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	exit_button(t_cub3d *cub3d)
{
	close_game(cub3d);
	return (0);
}

int	ft_events(t_cub3d *cub3d)
{
	mlx_hook(cub3d->mlx.win, 17, 0L, exit_button, cub3d);
	return (0);
}
