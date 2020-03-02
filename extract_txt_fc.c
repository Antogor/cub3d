/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_txt_fc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:47:13 by agarzon-          #+#    #+#             */
/*   Updated: 2020/03/02 13:47:14 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	extract_txt_fc(char *s, t_cub3d *cub3d)
{
	int l;

	l = 0;
	if (s[l] == 'F' && s[l + 1] == 'T')
	{
		cub3d->text->text_floor = ft_strtrim(s, "FT ");
		if (!(ft_strnstr(cub3d->text->text_floor, ".xpm",
			ft_strlen(cub3d->text->text_floor))))
			return (0);
	}
	if (s[l] == 'C' && s[l + 1] == 'T')
	{
		cub3d->text->text_celing = ft_strtrim(s, "CT ");
		if (!(ft_strnstr(cub3d->text->text_celing, ".xpm",
			ft_strlen(cub3d->text->text_celing))))
			return (0);
	}
	
	return (1);
}
