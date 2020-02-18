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

int		extract_map(char *str, t_cub3d *cub3d)
{
	if (!cub3d->map)
	{
		cub3d->map_w = 0;
		cub3d->map_h = 0;
		if (!(cub3d->map = ft_bi_array(1, 1)))
			return (0);
	}
	if (!(cub3d->map[cub3d->map_h] = ft_strdup(str)))
		return (0);
	cub3d->map_h++;
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
	cub3d->map_h = 0;
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
	printf("%s\n", cub3d->map[0]);
	printf("%s\n", cub3d->map[1]);
	printf("%s\n", cub3d->map[2]);
	printf("%s\n", cub3d->map[3]);
	printf("%s\n", cub3d->map[4]);
	printf("%s\n", cub3d->map[5]);
	printf("%s\n", cub3d->map[6]);
	printf("%s\n", cub3d->map[7]);
	printf("%s\n", cub3d->map[8]);
	printf("%s\n", cub3d->map[9]);
	l = check_map(cub3d);;
	if (l == 0)
		l -= 1;
	free(str);
	close(cub3d->fd);
	return (l);
}
