/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:43:55 by agarzon-          #+#    #+#             */
/*   Updated: 2020/06/06 19:08:41 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		extract_rest(char *str, t_cub3d *cub)
{
	if (ft_strnstr(str, "F ", 2) || ft_strnstr(str, "C ", 2))
	{
		extract_color(str, &cub->color);
		cub->ch.fc++;
	}
	else if (ft_strnstr(str, "FT ", 3) || ft_strnstr(str, "CT ", 3))
	{
		extract_tx_fc(str, &cub->tx);
		cub->ch.tfc++;
	}
	else if (str[0] == '\0')
		return (0);
	else
		ft_error("Not a valid map");
	return (0);
}

int		extract_data(char *str, t_cub3d *cub)
{
	if (ft_strnstr(str, "R ", 2))
	{
		extract_resolution(str, cub);
		cub->ch.r++;
	}
	else if (ft_strnstr(str, "NO ", 3) || ft_strnstr(str, "SO ", 3))
	{
		extract_tx_ns(str, &cub->tx);
		cub->ch.ns++;
	}
	else if (ft_strnstr(str, "WE ", 3) || ft_strnstr(str, "EA ", 3) ||
		ft_strnstr(str, "S ", 2))
	{
		extract_tx_wes(str, &cub->tx);
		cub->ch.wes++;
	}
	else
		extract_rest(str, cub);
	return (0);
}

void	gnl_1(int fd, t_cub3d *cub)
{
	char	*str;

	if (!cub->map.h)
		cub->map.h = 0;
	while (get_next_line(fd, &str) > 0)
	{
		if (str[0] == '1' || str[0] == 32 || str[0] == '\t' ||
			str[0] == '0')
		{
			cub->map.h++;
			while (get_next_line(fd, &str) > 0)
			{
				cub->map.h++;
				if (str[0] != '1' && str[0] != 32 &&
					str[0] != '\t' && str[0] != '0')
					ft_error("NOT A VALID MAP");
			}
		}
		extract_data(str, cub);
	}
	free(str);
}

void	gnl_2(int fd, t_cub3d *cub)
{
	char	*str;
	char	*tmp;
	int		l;

	l = 0;
	while (get_next_line(fd, &str) > 0)
	{
		if (str[0] == '1' || str[0] == 32 || str[0] == '\t' ||
			str[0] == '0')
		{
			tmp = str;
			l++;
			while (get_next_line(fd, &str) > 0)
			{
				if (!cub->map.m)
				{
					cub->map.m = (char **)malloc(sizeof(char *) *
					cub->map.h + 1);
					cub->map.m[0] = ft_strdup(tmp);
				}
				cub->map.m[l++] = ft_strdup(str);
			}
		}
	}
	free(str);
}

int		ft_map(char **argv, t_cub3d *cub)
{
	int		fd;

	cub->ch.r = 0;
	cub->ch.ns = 0;
	cub->ch.wes = 0;
	cub->ch.fc = 0;
	cub->ch.tfc = 0;
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error("Couldn't open .cub");
	gnl_1(fd, cub);
	close(fd);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error("Couldn't open .cub");
	gnl_2(fd, cub);
	close(fd);
	if (!cub->map.m)
		ft_error("Map doesn't exist");
	if (cub->ch.r != 1 || cub->ch.ns != 2 || cub->ch.wes != 3 ||
		cub->ch.fc != 2 && cub->ch.fc != 0 ||
		cub->ch.tfc != 2 && cub->ch.tfc != 0)
		ft_error("Invalid map");
	cub->pl = extract_player(cub->map.m, cub->map.h);
	extract_sprite(cub, cub->map.m);
	return (0);
}
