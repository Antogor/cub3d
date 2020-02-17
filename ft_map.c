/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:43:55 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/17 18:09:59 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		extract_data(char *str, t_cub3d *cub3d)
{
	if (ft_strnstr(str, "R ", 2))
		return (check_map(str, cub3d));
	else if (ft_strnstr(str, "NO ", 3))
		return (check_map(str, cub3d));
	else if (ft_strnstr(str, "SO ", 3))
		return (check_map(str, cub3d));
	else if (ft_strnstr(str, "WE ", 3))
		return (check_map(str, cub3d));
	else if (ft_strnstr(str, "EA ", 3))
		return (check_map(str, cub3d));
	else if (ft_strnstr(str, "S ", 2))
		return (check_map(str, cub3d));
	else if (ft_strnstr(str, "F ", 2))
		return (check_map(str, cub3d));
	else if (ft_strnstr(str, "C ", 2))
		return (check_map(str, cub3d));
	else if (ft_strchr(str, '1'))
		return (check_map(str, cub3d));
	else
		return (0);
}

int		ft_map(char **argv, t_cub3d *cub3d)
{
	int		l;

	l = 0;
	if (!(cub3d->fd = open(argv[1], O_RDONLY)))
		return (-1);
	while (get_next_line(cub3d->fd, &cub3d->read_map) == 1)
	{
		if(!extract_data(cub3d->read_map, cub3d))
			return (-1);
		free(cub3d->read_map);
	}
	close(cub3d->fd);
	return (0);
}
