/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 20:48:55 by agarzon-          #+#    #+#             */
/*   Updated: 2020/06/05 18:23:41 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	close_game(t_cub3d *cub3d)
{
	int l;

	l = 0;
	if (cub3d->map.m)
	{
		while (cub3d->map.m[l])
		{
			free(cub3d->map.m[l]);
			l++;
		}
		free(cub3d->map.m);
	}
	free(cub3d);
	exit(EXIT_SUCCESS);
}
