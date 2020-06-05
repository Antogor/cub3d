/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:32:42 by agarzon-          #+#    #+#             */
/*   Updated: 2020/06/05 15:13:26 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	count_sprite(t_cub3d *c, char **m)
{
	int y;
	int x;

	y = 0;
	c->s_nb = 0;
	while (m[y])
	{
		x = 0;
		while (m[y][x])
		{
			if (m[y][x] == '4')
				c->s_nb++;
			x++;
		}
		y++;
	}
	if (!c->s_nb)
		ft_error("No sprite found");
	return (0);
}

int	extract_sprite(t_cub3d *c, char **m)
{
	int			y;
	int			x;
	int			l;

	l = 0;
	x = 0;
	count_sprite(c, m);
	if (!(c->sprite = (malloc(c->s_nb * sizeof(t_sprite)))))
		ft_error("Couldn't reserve sprite memory");
	if (!(c->s_order = (int *)malloc(c->s_nb * sizeof(int))))
		ft_error("Couldn't reserve memory");
	while (m[x])
	{
		y = 0;
		while (m[x][y])
		{
			if (m[x][y] == '4')
			{
				c->sprite[l].x = x;
				c->sprite[l].y = y;
				l++;
			}
			y++;
		}
		x++;
	}
	return (0);
}
