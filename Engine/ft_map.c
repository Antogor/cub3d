/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:43:55 by agarzon-          #+#    #+#             */
/*   Updated: 2020/03/06 14:13:34 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		extract_data(char *str, t_cub3d *cub3d)
{
	if (ft_strnstr(str, "R ", 2))
		return(check_data(str, cub3d));
	else if (ft_strnstr(str, "NO ", 3))
		return(check_data(str, cub3d));
	else if (ft_strnstr(str, "SO ", 3))
		return(check_data(str, cub3d));
	else if (ft_strnstr(str, "WE ", 3))
		return(check_data(str, cub3d));
	else if (ft_strnstr(str, "EA ", 3))
		return(check_data(str, cub3d));
	else if (ft_strnstr(str, "S ", 2))
		return(check_data(str, cub3d));
	else if (ft_strnstr(str, "F ", 2))
		return(check_data(str, cub3d));
	else if (ft_strnstr(str, "C ", 2))
		return(check_data(str, cub3d));
	else if (ft_strnstr(str, "FT ", 3) || ft_strnstr(str, "CT ", 3))
		return(extract_txt_fc(str, cub3d->text));
	else if (ft_strnstr(str, "1", 1))
		return (2);
	else if (str[0] == '\0')
		return (1);
	else
		ft_error("Mapa no valido");
	return(0);
}

void	gnl_1(char *str, int *l, t_cub3d *cub3d)
{
//	char	*str;
	int		i;

	i = 0;
	while (get_next_line(cub3d->fd, &str) > 0)
	{
	//	gnl = get_next_line(cub3d->fd, &str);
		i = extract_data(str, cub3d);
		if (i == 2)
			*l += 1;
	/*	{
			if (!cub3d->count_rows)
				cub3d->count_rows = 0;
			cub3d->count_rows++;
			cub3d->map_w = ft_strlen(*str);
		}*/
	}
//	if (l == 2)
//		cub3d->map_h = cub3d->count_rows;
//	free(str);
//	return (l);
}

int		gnl_2(t_cub3d *cub3d)
{
	char	*str;
	int		l;
	int		gnl;

	gnl = 1;
	l = 0;
	while (gnl > 0)
	{
		gnl = get_next_line(cub3d->fd, &str);
		l = extract_data(str, cub3d);
		if (l == 2)
			cub3d->map[cub3d->count++] = ft_substr(str, 0, cub3d->map_w);
		if (l == 0)
			break ;
	}
	free(str);
	return (l);
}

int		ft_map(char **argv, t_cub3d *cub3d)
{
	int		l;
	char	str;

	l = 0;
	if (!(cub3d->fd = open(argv[1], O_RDONLY)))
		ft_error("No se pudo abrir el mapa");
	gnl_1(&str, &l, cub3d);
	cub3d->map = (char **)malloc(sizeof(char *) * l + 1);
	cub3d->map_h = l;
	close(cub3d->fd);
	if (!(cub3d->fd = open(argv[1], O_RDONLY)))
		return (-1);
	cub3d->count = 0;
	cub3d->map = (char **)malloc(sizeof(char *) * cub3d->count_rows + 1);
	cub3d->map_h = cub3d->count_rows;
	l = gnl_2(cub3d);
	if (l > 0)
		l = check_map(cub3d);
	if (l == 0)
		l -= 1;
	close(cub3d->fd);
	return (1);
}
