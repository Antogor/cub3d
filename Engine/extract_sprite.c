/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:32:42 by agarzon-          #+#    #+#             */
/*   Updated: 2020/03/09 12:33:06 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	count_sprite(t_cub3d *cub3d)
{
	int y;
	int x;

	y = 0;
	cub3d->sprite_nb = 0;
	while (cub3d->map[y])
	{
		x = 0;
		while (cub3d->map[y][x])
		{
			if (cub3d->map[y][x] == '2')
				cub3d->sprite_nb++;
			x++;
		}
		y++;
	}
	if (!cub3d->sprite_nb)
		ft_error("No hay sprite");
	return (1);
}

int		extract_sprite(t_cub3d *cub3d)
{
	int			y;
	int			x;
	int			l;

	l = 0;
	x = 0;
	if (!(cub3d->sprite = (malloc(cub3d->sprite_nb * sizeof(t_sprite)))))
		ft_error("Fallo malloc sprite");
	count_sprite(cub3d);
	while (cub3d->map[x])
	{
		y = 0;
		while (cub3d->map[x][y])
		{
			if (cub3d->map[x][y] == '2')
			{
				cub3d->sprite[l].sprite_x = x;
				cub3d->sprite[l].sprite_y = y;
				l++;
			}
			y++;
		}
		x++;
	}
	return (1);
}
