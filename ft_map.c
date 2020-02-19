/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:43:55 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/19 11:58:52 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		extract_map(char *str, t_cub3d *cub3d)
{
	int l;

	l = 0;
	if(!cub3d->map)
	{
		cub3d->map_w = 0;
		cub3d->map_h = 0;
		cub3d->map = malloc( sizeof(char *));
		while (l < 2)
		{
			cub3d->map[l] = malloc(2 * sizeof(char));
			l++;
		}
		if (!(cub3d->map[cub3d->map_h] = ft_strdup(str)))
			return (0);
		cub3d->map_h++;
	}
	else
	{
		if (!(cub3d->map[cub3d->map_h] = ft_strdup(str)))
			return (0);
		cub3d->map_h++;
	}
	return (1);
}

int		extract_data(char *str, t_cub3d *cub3d)
{
	if (ft_strnstr(str, "R ", 2))
		return (check_data(str, cub3d));
	else if (ft_strnstr(str, "NO ", 3))
		return (check_data(str, cub3d));
	else if (ft_strnstr(str, "SO ", 3))
		return (check_data(str, cub3d));
	else if (ft_strnstr(str, "WE ", 3))
		return (check_data(str, cub3d));
	else if (ft_strnstr(str, "EA ", 3))
		return (check_data(str, cub3d));
	else if (ft_strnstr(str, "S ", 2))
		return (check_data(str, cub3d));
	else if (ft_strnstr(str, "F ", 2))
		return (check_data(str, cub3d));
	else if (ft_strnstr(str, "C ", 2))
		return (check_data(str, cub3d));
	else if (ft_strnstr(str, "1", 1))
		return (2);
	else
		return (0);
}

int		ft_map(char **argv, t_cub3d *cub3d)
{
	char	*str;
	int		l;
	int		gnl;

	gnl = 1;
	l = 0;
	if (!(cub3d->fd = open(argv[1], O_RDONLY)))
		return (-1);
	while (gnl > 0)
	{
		gnl = get_next_line(cub3d->fd, &str);
		l = extract_data(str, cub3d);
		if (l == 2)
			l = extract_map(str, cub3d);
	}
	cub3d->map_w = ft_strlen(str);
	l = check_map(cub3d);
	if (l == 0)
		l -= 1;
	free(str);
	close(cub3d->fd);
	return (l);
}
