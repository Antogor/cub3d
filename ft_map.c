/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:43:55 by agarzon-          #+#    #+#             */
/*   Updated: 2020/01/31 15:51:34 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_text(char *data, t_cub3d *textures)
{
	int gnl;

	gnl = get_next_line(textures->fd, &data);
	textures->text_n = ft_substr(data, 3, ft_strlen(data));
	gnl = get_next_line(textures->fd, &data);
	textures->text_s = ft_substr(data, 3, ft_strlen(data));
	gnl = get_next_line(textures->fd, &data);
	textures->text_o = ft_substr(data, 3, ft_strlen(data));
	gnl = get_next_line(textures->fd, &data);
	textures->text_e = ft_substr(data, 3, ft_strlen(data));
	return (data);
}

int		ft_colors(char *data, t_cub3d *colors)
{
	int l;
	int gnl;

	l = 2;
	gnl = get_next_line(colors->fd, &data);
//	colors->floor_colors[0] = ft_substr(data, 0, 100);
//	colors->floor_colors[1] = ft_substr(data, l, 100);
//	colors->floor_colors[2] = ft_substr(data, l, 100);
	
	return (0);
}

int		ft_map(t_cub3d *map)
{
	char	*data;
	int		gnl;

	gnl = get_next_line(map->fd, &data);
	map->resolution[0] = ft_substr(data, 2, 4);
	map->resolution[1] = ft_substr(data, 7, 4);
	map->x = ft_atoi(map->resolution[0]);
	map->y = ft_atoi(map->resolution[1]);
	data = ft_text(data, map);
	ft_colors(data, map);
	return (0);
}
