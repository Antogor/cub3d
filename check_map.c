/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:45:30 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/17 18:17:47 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	extract_color(char *s, t_cub3d *cub3d)
{
	int l;

	l = 0;
	if (s[l] == 'F')
	{
		l++;
		if (!(cub3d->color->color_r = ft_atoi(&s[l])))
			return (0);
		l++;
		printf("%c", s[l]);
		while (s[l] >= '0' && s[l] <= '9')
			l++;
		return (1);
	}
	return (0);
}

int	extract_text_wes(char *s, t_cub3d *cub3d)
{
	int l;

	l = 0;
	if (s[l] == 'W')
	{
		cub3d->text->text_e = ft_strtrim(s, "WE ");
		if (!(ft_strnstr(cub3d->text->text_e, ".xpm",
			ft_strlen(cub3d->text->text_e))))
			return (0);
	}
	if (s[l] == 'E')
	{
		cub3d->text->text_o = ft_strtrim(s, "EA ");
		if (!(ft_strnstr(cub3d->text->text_o, ".xpm",
			ft_strlen(cub3d->text->text_o))))
			return (0);
	}
	if (s[l] == 'S')
	{
		cub3d->text->text_sprite = ft_strtrim(s, "S ");
		if (!(ft_strnstr(cub3d->text->text_sprite, ".xpm",
			ft_strlen(cub3d->text->text_sprite))))
			return (0);
	}
	return (1);
}

int	extract_text_ns(char *s, t_cub3d *cub3d)
{
	int l;

	l = 0;
	if (s[l] == 'N')
	{
		cub3d->text->text_n = ft_strtrim(s, "NO ");
		if (!(ft_strnstr(cub3d->text->text_n, ".xpm",
			ft_strlen(cub3d->text->text_n))))
			return (0);
	}
	if (s[l] == 'S' && s[l + 1] == 'O')
	{
		cub3d->text->text_s = ft_strtrim(s, "SO ");
		if (!(ft_strnstr(cub3d->text->text_s, ".xpm",
			ft_strlen(cub3d->text->text_s))))
			return (0);
	}
	return (1);
}

int	check_map(char *s, t_cub3d *cub3d)
{
	int l;

	l = 0;
	if (s[l] == 'R')
	{
		l++;
		if (!(cub3d->screen_w = ft_atoi(&s[l])))
			return (0);
		l++;
		while (s[l] >= '0' && s[l] <= '9')
			l++;
		if (!(cub3d->screen_h = ft_atoi(&s[l])))
			return (0);
		return (1);
	}
	if (s[l] == 'N' || (s[l] == 'S' && s[l + 1] == 'O'))
		return (extract_text_ns(s, cub3d));
	else if (s[l] == 'W' || s[l] == 'E' || s[l] == 'S')
		return (extract_text_wes(s, cub3d));
	else if (s[l] == 'F' || s[l] == 'C')
		return (extract_color(s, cub3d));
	return (0);
}
