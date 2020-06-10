/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:43:55 by agarzon-          #+#    #+#             */
/*   Updated: 2020/04/09 21:00:56 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	else if (ft_strnstr(str, "FT ", 3) || ft_strnstr(str, "CT ", 3))
		return (extract_txt_fc(str, cub3d->text));
	else if (str[0] == '1' || str[0] == 32 || str[0] == '\t')
		return (2);
	else if (str[0] == '\0')
		return (1);
	else
		ft_error("Not a valid map");
	return (0);
}

void	gnl_1(t_cub3d *cub3d)
{
	int		l;
	char	*str;

	l = 0;
	cub3d->count = 0;
	while (get_next_line(cub3d->fd, &str) > 0)
	{
		l = extract_data(str, cub3d);
		if (l == 2)
		{
			if (!cub3d->count_rows)
				cub3d->count_rows = 0;
			cub3d->count_rows++;
		}
		else
			cub3d->count++;
	}
	free(str);
}

void	gnl_2(t_cub3d *cub3d)
{
	int		l;
	char	**tmp;

	l = 0;
	if (!(tmp = (char **)malloc(sizeof(char *) *
		(cub3d->count + cub3d->count_rows) + 1)))
		ft_error("Couldn't reserve memory");
	while (get_next_line(cub3d->fd, &tmp[l]) > 0)
		l++;
	tmp[l] = NULL;
	check_map(tmp, cub3d);
	free(tmp);
}

int		ft_map(char **argv, t_cub3d *cub3d)
{
	if ((cub3d->fd = open(argv[1], O_RDONLY)) < 0)
		ft_error("Couldn't open .cub");
	gnl_1(cub3d);
	close(cub3d->fd);
	cub3d->map_h = cub3d->count_rows;
	if ((cub3d->fd = open(argv[1], O_RDONLY)) < 0)
		ft_error("Couldn't open .cub");
	gnl_2(cub3d);
	close(cub3d->fd);
	return (1);
}
