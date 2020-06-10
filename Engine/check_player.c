/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:54:45 by agarzon-          #+#    #+#             */
/*   Updated: 2020/06/08 14:12:39 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			is_a_close_map(char **map, int x, int y, int limit)
{
	if (map[x][y] == 32 || map[x][y] == 9 || map[x][y] == 0)
		ft_error("Not a valid map");
	if (map[x][y] == '1' || map[x][y] == '8' || map[x][y] == '4')
		return (1);
	if ((x <= 0) || !map[x][y] || (y <= 0) || (x == limit))
		ft_error("Not a valid map");
	if (map[x][y] == '0')
		map[x][y] = '8';
	if (map[x][y] == '2')
		map[x][y] = '4';
	is_a_close_map(map, x + 1, y, limit);
	is_a_close_map(map, x - 1, y, limit);
	is_a_close_map(map, x, y + 1, limit);
	is_a_close_map(map, x, y - 1, limit);
	return (0);
}

int			extract_pos_we(t_player *pl)
{
	if (pl->dir_player == 'W')
	{
		pl->dir_x = 0.0;
		pl->dir_y = -1.0;
		pl->plane_x = -0.66;
		pl->plane_y = 0.0;
		return (1);
	}
	if (pl->dir_player == 'E')
	{
		pl->dir_x = 0.0;
		pl->dir_y = 1.0;
		pl->plane_x = 0.66;
		pl->plane_y = 0.0;
		return (1);
	}
	return (0);
}

int			extract_pos(t_player *pl)
{
	if (pl->dir_player == 'N')
	{
		pl->dir_x = -1.0;
		pl->dir_y = 0.0;
		pl->plane_x = 0.0;
		pl->plane_y = 0.66;
		return (0);
	}
	if (pl->dir_player == 'S')
	{
		pl->dir_x = 1.0;
		pl->dir_y = 0.0;
		pl->plane_x = 0.0;
		pl->plane_y = -0.66;
		return (0);
	}
	if (extract_pos_we(pl))
		return (0);
	return (0);
}

int			determinate_pos(t_player *pl, char p, int f, int c)
{
	if (p == 'N' || p == 'S' || p == 'W' || p == 'E')
	{
		pl->dir_player = p;
		pl->pos_x = (double)f + 0.5;
		pl->pos_y = (double)c + 0.5;
		pl->count_player++;
	}
	else
		ft_error("No player found");
	return (0);
}

t_player	extract_player(char **m, int limit)
{
	t_player	pl;
	int			f;
	int			c;

	f = 0;
	pl.count_player = 0;
	while (f++ < limit)
	{
		c = 0;
		while (c++ < (int)ft_strlen(m[f]))
		{
			if (ft_isalpha(m[f][c]))
			{
				determinate_pos(&pl, m[f][c], f, c);
				break ;
			}
		}
	}
	if (pl.count_player != 1)
		ft_error("Only allowed one player");
	extract_pos(&pl);
	init_key(&pl);
	pl.speed = 0.05;
	is_a_close_map(m, (int)pl.pos_x, (int)pl.pos_y, limit);
	return (pl);
}
