/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:43:55 by agarzon-          #+#    #+#             */
/*   Updated: 2020/01/30 11:39:23 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_text(int fd, char *data, t_cub3d *textures)
{
	int gnl;

	gnl = get_next_line(fd, &data);
	textures->text_n = ft_substr(data, 3, ft_strlen(data));
	gnl = get_next_line(fd, &data);
	textures->text_s = ft_substr(data, 3, ft_strlen(data));
	gnl = get_next_line(fd, &data);
	textures->text_o = ft_substr(data, 3, ft_strlen(data));
	gnl = get_next_line(fd, &data);
	textures->text_e = ft_substr(data, 3, ft_strlen(data));
	return (0);
}

int		ft_colors(int fd, char *data, t_cub3d *colors)
{
	int gnl;
	int l;

	l = 2;
	gnl = get_next_line(fd, &data);
	while (data[l] >= '0' && data[l] <= '9')
		l++;
	colors->floor_colors[0] = ft_substr(data, l, 100);
//	colors->floor_colors[1] = ft_atoi(data);
//	colors->floor_colors[2] = ft_atoi(data);
	printf("%s", colors->floor_colors[0]);
	return (0);
}

int		ft_map(char *path_map, t_cub3d *map)
{
	int		fd;
	int		gnl;
	char	*data;

	fd = open(path_map, O_RDONLY);
	gnl = get_next_line(fd, &data);
	map->resolution[0] = ft_substr(data, 2, 4);
	map->resolution[1] = ft_substr(data, 7, 4);
	map->x = ft_atoi(map->resolution[0]);
	map->y = ft_atoi(map->resolution[1]);
	ft_text(fd, data, map);
	ft_colors(fd, data, map);
	return (0);
}
