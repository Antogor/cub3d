/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:07:07 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/19 15:11:18 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	extract_floor(char *s, t_cub3d *cub3d)
{
	if ((cub3d->color->color_floor = ft_split(s, ' ')))
	{
		cub3d->color->color_r = ft_atoi(cub3d->color->color_floor[1]);
		cub3d->color->color_g = ft_atoi(cub3d->color->color_floor[2]);
		cub3d->color->color_b = ft_atoi(cub3d->color->color_floor[3]);
		cub3d->color->floor = create_trgb(0, cub3d->color->color_r,
		cub3d->color->color_g, cub3d->color->color_b);
		return (1);
	}
	return (0);
}

int	extract_color(char *s, t_cub3d *cub3d)
{
	if (s[0] == 'F')
		return (extract_floor(s, cub3d));
	if (s[0] == 'C')
	{
		if ((cub3d->color->color_celling = ft_split(s, ' ')))
		{
			cub3d->color->color_r = ft_atoi(cub3d->color->color_celling[1]);
			cub3d->color->color_g = ft_atoi(cub3d->color->color_celling[2]);
			cub3d->color->color_b = ft_atoi(cub3d->color->color_celling[3]);
			cub3d->color->celling = create_trgb(0, cub3d->color->color_r,
				cub3d->color->color_g, cub3d->color->color_b);
			return (1);
		}
		return (0);
	}
	return (0);
}
