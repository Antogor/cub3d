/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:07:07 by agarzon-          #+#    #+#             */
/*   Updated: 2020/06/04 18:46:18 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	extract_floor(char *s, t_color *c)
{
	if ((c->color_floor = ft_split(s, ' ')))
	{
		if (!(c->color_r = ft_atoi(c->color_floor[1])))
			ft_error("FLOOR RED ERROR");
		if (!(c->color_g = ft_atoi(c->color_floor[2])))
			ft_error("FLOOR GREEN ERROR");
		if (!(c->color_b = ft_atoi(c->color_floor[3])))
			ft_error("FLOOR BLUE ERROR");
		c->floor = create_trgb(0, c->color_r, c->color_g,
			c->color_b);
	}
	else
		ft_error("FLOOR COLOR ERROR");

	return (0);
}

int	extract_color(char *s, t_color *c)
{
	if (s[0] == 'F')
		extract_floor(s, c);
	if (s[0] == 'C')
	{
		if ((c->color_celling = ft_split(s, ' ')))
		{
			if (!(c->color_r = ft_atoi(c->color_celling[1])))
				ft_error("CELING RED ERROR");
			if (!(c->color_g = ft_atoi(c->color_celling[2])))
				ft_error("CELING GREEN EROR");
			if (!(c->color_b = ft_atoi(c->color_celling[3])))
				ft_error("CELING BLUE ERROR");
			c->celling = create_trgb(0, c->color_r, c->color_g,
				c->color_b);
		}
		else
			ft_error("CELING COLOR EROR");
	}
	return (0);
}
