/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:45:30 by agarzon-          #+#    #+#             */
/*   Updated: 2020/03/04 15:37:22 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	extract_resolution(char *s, t_cub3d *cub3d)
{
	int l;

	l = 0;
	if (s[l] == 'R')
	{
		l++;
		if (!(cub3d->screen_w = ft_atoi(&s[l])))
			ft_error("Fallo en la resolucion");
		l++;
		while (s[l] >= '0' && s[l] <= '9')
			l++;
		if (!(cub3d->screen_h = ft_atoi(&s[l])))
			ft_error("Fallo en la resolucion");
	}
	if (cub3d->screen_w > 1920)
		cub3d->screen_w = 1920;
	else if (cub3d->screen_w < 520)
		cub3d->screen_w = 520;
	if (cub3d->screen_h > 1080)
		cub3d->screen_h = 1080;
	else if (cub3d->screen_h < 360)
		cub3d->screen_h = 360;
	return (1);
}

int	extract_text_rns(char *s, t_text *text)
{
	int l;

	l = 0;
	if (s[l] == 'N')
	{
		text->text_n = ft_strtrim(s, "NO ");
		if (!(ft_strnstr(text->text_n, ".xpm", ft_strlen(text->text_n))))
			ft_error("La textura norte no es .xpm");
	}
	if (s[l] == 'S' && s[l + 1] == 'O')
	{
		text->text_s = ft_strtrim(s, "SO ");
		if (!(ft_strnstr(text->text_s, ".xpm", ft_strlen(text->text_s))))
			ft_error("La textura sur no es .xpm");
	}
	return (1);
}

int	extract_text_wes(char *s, t_text *text)
{
	int l;

	l = 0;
	if (s[l] == 'W')
	{
		text->text_w = ft_strtrim(s, "WE ");
		if (!(ft_strnstr(text->text_w, ".xpm", ft_strlen(text->text_w))))
			ft_error("La textura oeste no es .xpm");
	}
	if (s[l] == 'E')
	{
		text->text_e = ft_strtrim(s, "EA ");
		if (!(ft_strnstr(text->text_e, ".xpm", ft_strlen(text->text_e))))
			ft_error("La textura este no es .xpm");
	}
	if (s[l] == 'S')
	{
		text->text_sprite = ft_strtrim(s, "S ");
		if (!(ft_strnstr(text->text_sprite, ".xpm",
			ft_strlen(text->text_sprite))))
			ft_error("La textura sprite no es .xpm");
	}
	return (1);
}

int	check_data(char *s, t_cub3d *cub3d)
{
	int l;

	l = 0;
	if (s[l] == 'R')
		return (extract_resolution(s, cub3d));
	if (s[l] == 'N' || (s[l] == 'S' && s[l + 1] == 'O'))
		return (extract_text_rns(s, cub3d->text));
	if (s[l] == 'W' || s[l] == 'E' || s[l] == 'S')
		return (extract_text_wes(s, cub3d->text));
	if (s[l] == 'F' || s[l] == 'C')
		return (extract_color(s, cub3d->color));
	return (0);
}
