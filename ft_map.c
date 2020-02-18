/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:43:55 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/17 18:37:27 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	char	*tmp;

	gnl = 1;
	if (!(cub3d->fd = open(argv[1], O_RDONLY)))
		return (-1);
	while (gnl > 0)
	{
		gnl = get_next_line(cub3d->fd, &str);
		l = extract_data(str, cub3d);
		if (l == 2)
		{
			if (!cub3d->map)
				cub3d->map = ft_strdup(str);
			else
			{
				tmp = ft_strjoin(cub3d->map, str);
				free(cub3d->map);
				cub3d->map = tmp;
			}
		}
	}
	printf("%s", cub3d->map);
	l = 0 ? -1 : 1;
	free(str);
	close(cub3d->fd);
	return (l);
}
