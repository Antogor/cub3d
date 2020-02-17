/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:43:55 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/17 14:25:08 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*char	*ft_text(char *data, t_cub3d *textures)
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
}*/

int		ft_map(char **argv, t_cub3d *cub3d)
{
	int		l;

	l = 0;
	if (!(cub3d->fd = open(argv[1], O_RDONLY)))
		return (-1);
	cub3d->map_data = ft_bi_array(100, 100);
	while (get_next_line(cub3d->fd, &cub3d->read_map) == 1)
	{
		cub3d->map_data[l] = ft_strdup(cub3d->read_map);
		l++;
	}
	printf("%s", cub3d->map_data[3]);
	free(cub3d->read_map);
	return (0);
}
