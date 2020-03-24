/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:54:45 by agarzon-          #+#    #+#             */
/*   Updated: 2020/03/04 15:36:54 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	extract_we(t_cub3d *cub3d, t_player *player)
{
	if (cub3d->dir_player == 'W')
	{
		player->dir_x = 0.0;
		player->dir_y = -1.0;
		player->plane_x = -0.66;
		player->plane_y = 0.0;
		return (1);
	}
	if (cub3d->dir_player == 'E')
	{
		player->dir_x = 0.0;
		player->dir_y = 1.0;
		player->plane_x = 0.66;
		player->plane_y = 0.0;
		return (1);
	}
	return (0);
}

int	extract_pos(t_cub3d *cub3d, t_player *player)
{
	if (cub3d->dir_player == 'N')
	{
		player->dir_x = -1.0;
		player->dir_y = 0.0;
		player->plane_x = 0.0;
		player->plane_y = 0.66;
		return (1);
	}
	if (cub3d->dir_player == 'S')
	{
		player->dir_x = 1.0;
		player->dir_y = 0.0;
		player->plane_x = 0.0;
		player->plane_y = -0.66;
		return (1);
	}
	if (extract_we(cub3d, cub3d->player))
		return (1);
	return (0);
}

int	determinate_pos(t_cub3d *cub3d, int f, int f2, int c, char **tmp)
{
	if (tmp[f][c] == 'N' || tmp[f][c] == 'S' ||
		tmp[f][c] == 'W' || tmp[f][c] == 'E')
	{
		cub3d->dir_player = tmp[f][c];
		cub3d->player->pos_x = (double)f2;
		cub3d->player->pos_y = (double)c;
		cub3d->map[f2][c] = '0';
		cub3d->a = 1;
		return (1);
	}
	else
		ft_error("No hay jugador");
	return (0);
}

void	map_data(char **tmp, t_cub3d *cub3d)
{
	int c;
	int f;

	f = 0;
	while (tmp[cub3d->count])
	{
		if (!(cub3d->map[f] = (char *)malloc(sizeof(char) *
							ft_strlen(tmp[cub3d->count]) + 1)))
			ft_error("Fallo en malloc");
		c = 0;
		while (tmp[cub3d->count][c])
		{
			if (ft_isalpha(tmp[cub3d->count][c]))
				determinate_pos(cub3d, cub3d->count, f, c, tmp);
			if (tmp[cub3d->count][c] == '1' || tmp[cub3d->count][c] == '0' ||
				tmp[cub3d->count][c] == '2')
				cub3d->map[f][c] = tmp[cub3d->count][c];
			c++;
		}
		cub3d->map[f][c] = '\0';
		f++;
		cub3d->count++;
	}
	cub3d->map[f] = '\0';
}

int	check_map(char **tmp, t_cub3d *cub3d)
{
	cub3d->a = 0;
	if (!(cub3d->map = (char **)malloc(sizeof(char *) *
		cub3d->map_h + 1)))
		ft_error("Fallo en malloc");
	map_data(tmp, cub3d);
	if (!cub3d->a)
		ft_error("No hay jugador");
	extract_sprite(cub3d);
	extract_pos(cub3d, cub3d->player);
	return (0);
}
