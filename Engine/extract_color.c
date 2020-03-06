/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:07:07 by agarzon-          #+#    #+#             */
/*   Updated: 2020/03/04 15:36:34 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	extract_floor(char *s, t_color *color)
{
	if ((color->color_floor = ft_split(s, ' ')))
	{
		color->color_r = ft_atoi(color->color_floor[1]);
		color->color_g = ft_atoi(color->color_floor[2]);
		color->color_b = ft_atoi(color->color_floor[3]);
		color->floor = create_trgb(0, color->color_r, color->color_g,
			color->color_b);
		return (1);
	}
	return (0);
}

int	extract_color(char *s, t_color *color)
{
	if (s[0] == 'F')
		return (extract_floor(s, color));
	if (s[0] == 'C')
	{
		if ((color->color_celling = ft_split(s, ' ')))
		{
			color->color_r = ft_atoi(color->color_celling[1]);
			color->color_g = ft_atoi(color->color_celling[2]);
			color->color_b = ft_atoi(color->color_celling[3]);
			color->celling = create_trgb(0, color->color_r, color->color_g,
				color->color_b);
			return (1);
		}
		return (0);
	}
	return (0);
}
