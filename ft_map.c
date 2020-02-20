/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:43:55 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/20 09:23:29 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		extract_map(char *str, t_cub3d *cub3d)
{
	int l;

	l = 0;
	if (!cub3d->map)
	{
		cub3d->map_h = 0;
		cub3d->map = ft_bi_array(cub3d->count_rows, cub3d->map_w); //cub3d->map = malloc(sizeof(char *) * cub3d->count_rows);
		if (!(cub3d->map[cub3d->map_h] = ft_strdup(str)))
			return (0);
	}
	else
	{
		cub3d->map_h++;
		if (!(cub3d->map[cub3d->map_h] = ft_strdup(str)))
			return (0);
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
	else if (str[0] == '\0')
		return (1);
	else
		return (0);
}

int		gnl_1(t_cub3d *cub3d)
{
	char	*str;
	int		l;
	int		gnl;

	gnl = 1;
	while (gnl > 0)
	{
		gnl = get_next_line(cub3d->fd, &str);
		l = extract_data(str, cub3d);
		if (l == 0)
			break ;
		if (l == 2)
		{
			if (!cub3d->count_rows)
				cub3d->count_rows = 0;
			cub3d->count_rows++;
		}
	}
	if (l == 2)
		cub3d->map_w = ft_strlen(str);
	free(str);
	return (l);
}

int		gnl_2(t_cub3d *cub3d)
{
	char	*str;
	int		l;
	int		gnl;

	gnl = 1;
	while (gnl > 0)
	{
		gnl = get_next_line(cub3d->fd, &str);
		if (str[0] == '1')
		{
			l = extract_map(str, cub3d);
			if (l == 0)
				break ;
		}
	}
	free(str);
	return (l);
}

int		ft_map(char **argv, t_cub3d *cub3d)
{
	int		l;

	if (!(cub3d->fd = open(argv[1], O_RDONLY)))
		return (-1);
	l = gnl_1(cub3d);
	if (l == 0)
	{
		l -= 1;
		close(cub3d->fd);
		return (l);
	}
	close(cub3d->fd);
	if (!(cub3d->fd = open(argv[1], O_RDONLY)))
		return (-1);
	l = gnl_2(cub3d);
	if (l > 0)
		l = check_map(cub3d);
	if (l == 0)
		l -= 1;
	close(cub3d->fd);
	return (l);
}
