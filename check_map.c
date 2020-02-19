/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:54:45 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/19 16:41:00 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	extract_pos(t_cub3d *cub3d)
{
	if (cub3d->dir_player == 'N')
	{
		cub3d->player->dir_x = 0;
		cub3d->player->dir_y = -1;
		cub3d->player->plane_x = 0.66;
		cub3d->player->plane_y = 0;
		return (1);
	}
	if (cub3d->dir_player == 'S')
	{
		cub3d->player->dir_x = 0;
		cub3d->player->dir_y = 1;
		cub3d->player->plane_x = 0.66;
		cub3d->player->plane_y = 0;
		return (1);
	}
	if (cub3d->dir_player == 'W')
	{
		cub3d->player->dir_x = -1;
		cub3d->player->dir_y = 0;
		cub3d->player->plane_x = 0;
		cub3d->player->plane_y = 0.66;
		return (1);
	}
	if (cub3d->dir_player == 'E')
	{
		cub3d->player->dir_x = 1;
		cub3d->player->dir_y = 0;
		cub3d->player->plane_x = 0;
		cub3d->player->plane_y = 0.66;
		return (1);
	}
	return (0);
}

int	map_data(t_cub3d *cub3d)
{
	int l;
	int q;

	l = 0;
	while (l < cub3d->map_h)
	{
		q = 0;
		while (cub3d->map[l][q])
		{
			if (cub3d->map[l][q] != '1' && cub3d->map[l][q] != '0'
				&& cub3d->map[l][q] != '2' && cub3d->map[l][q] != 'N' &&
				cub3d->map[l][q] != 'S' && cub3d->map[l][q] != 'W' &&
				cub3d->map[l][q] != 'E')
				return (0);
			if (cub3d->map[l][q] == 'N' || cub3d->map[l][q] == 'S' ||
				cub3d->map[l][q] == 'W' || cub3d->map[l][q] == 'E')
			{
				cub3d->dir_player = cub3d->map[l][q];
				cub3d->player->pos_x = q;
				cub3d->player->pos_y = l;
			}
			q++;
		}
		l++;
	}
	return (extract_pos(cub3d));
}

int	check_map(t_cub3d *cub3d)
{
	int l;
	int	q;

	l = 0;
	q = 0;
	while (l < cub3d->map_w)
	{
		if (cub3d->map[0][l] == '1' && cub3d->map[cub3d->map_h - 1][l] == '1')
			l++;
		else
			return (0);
	}
	while (q < cub3d->map_h)
	{
		if (cub3d->map[q][0] == '1' && cub3d->map[q][cub3d->map_w - 1] == '1')
			q++;
		else
			return (0);
	}
	return (map_data(cub3d));
}
