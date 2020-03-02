/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:54:45 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/24 12:45:16 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	extract_we(t_cub3d *cub3d)
{
	if (cub3d->dir_player == 'W')
	{
		cub3d->player->dir_x = -1.0;
		cub3d->player->dir_y = 0.0;
		cub3d->player->plane_x = 0.0;
		cub3d->player->plane_y = 0.66;
		return (1);
	}
	if (cub3d->dir_player == 'E')
	{
		cub3d->player->dir_x = 1.0;
		cub3d->player->dir_y = 0.0;
		cub3d->player->plane_x = 0.0;
		cub3d->player->plane_y = 0.66;
		return (1);
	}
	return (0);
}

int	extract_pos(t_cub3d *cub3d)
{
	if (cub3d->dir_player == 'N')
	{
		cub3d->player->dir_x = 0.0;
		cub3d->player->dir_y = -1.0;
		cub3d->player->plane_x = -0.66;
		cub3d->player->plane_y = 0.0;
		return (1);
	}
	if (cub3d->dir_player == 'S')
	{
		cub3d->player->dir_x = 0.0;
		cub3d->player->dir_y = 1.0;
		cub3d->player->plane_x = 0.66;
		cub3d->player->plane_y = 0;
		return (1);
	}
	if (extract_we(cub3d))
		return (1);
	return (0);
}

int	determinate_pos(t_cub3d *cub3d, int fill, int columns)
{
	if (cub3d->map[fill][columns] == 'N' || cub3d->map[fill][columns] == 'S' ||
		cub3d->map[fill][columns] == 'W' || cub3d->map[fill][columns] == 'E')
	{
		cub3d->dir_player = cub3d->map[fill][columns];
		cub3d->player->pos_x = (double)columns;
		cub3d->player->pos_y = (double)fill;
		return (1);
	}
	return (0);
}

int	map_data(t_cub3d *cub3d)
{
	int columns;
	int fill;

	fill = 0;
	while (fill < cub3d->map_h)
	{
		columns = 0;
		while (columns < cub3d->map_w)
		{
			if (cub3d->map[fill][columns] != '1' &&
				cub3d->map[fill][columns] != '0'
				&& cub3d->map[fill][columns] != '2'
				&& cub3d->map[fill][columns] != 'N' &&
				cub3d->map[fill][columns] != 'S'
				&& cub3d->map[fill][columns] != 'W' &&
				cub3d->map[fill][columns] != 'E')
				return (0);
			if (determinate_pos(cub3d, fill, columns))
				break ;
			columns++;
		}
		fill++;
	}
	return (extract_pos(cub3d));
}

int	check_map(t_cub3d *cub3d)
{
	int columns;
	int	fill;

	columns = 0;
	fill = 0;
	while (columns < cub3d->map_w)
	{
		if (cub3d->map[0][columns] != '1' ||
			cub3d->map[cub3d->map_h - 1][columns] != '1')
			return (0);
		columns++;
	}
	while (fill < cub3d->map_h)
	{
		if (cub3d->map[fill][0] != '1' ||
			cub3d->map[fill][cub3d->map_w - 1] != '1')
			return (0);
		fill++;
	}
	return (map_data(cub3d));
}
