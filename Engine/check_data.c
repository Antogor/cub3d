/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:45:30 by agarzon-          #+#    #+#             */
/*   Updated: 2020/06/05 12:48:30 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	extract_resolution(char *s, t_cub3d *cub)
{
	int l;

	l = 0;
	if (s[l] == 'R')
	{
		l++;
		if (!(cub->screen_w = ft_atoi(&s[l])))
			ft_error("RESOLUTION ERROR");
		l++;
		while (s[l] >= '0' && s[l] <= '9')
			l++;
		if (!(cub->screen_h = ft_atoi(&s[l])))
			ft_error("RESOLUTION ERROR");
	}
	if (cub->screen_w > 1920)
		cub->screen_w = 1920;
	else if (cub->screen_w < 520)
		cub->screen_w = 520;
	if (cub->screen_h > 1080)
		cub->screen_h = 1080;
	else if (cub->screen_h < 360)
		cub->screen_h = 360;
	return (0);
}

int	extract_tx_ns(char *s, t_tx *t)
{
	int l;

	l = 0;
	if (s[l] == 'N')
	{
		t->walls.north = ft_strtrim(s, "NO ");
		if (!(ft_strnstr(t->walls.north, ".xpm", ft_strlen(t->walls.north))))
			ft_error("FAIL .xpm in text NO");
	}
	if (s[l] == 'S' && s[l + 1] == 'O')
	{
		t->walls.south = ft_strtrim(s, "SO ");
		if (!(ft_strnstr(t->walls.south, ".xpm", ft_strlen(t->walls.south))))
			ft_error("FAIL .xpm in text SO");
	}
	return (0);
}

int	extract_tx_wes(char *s, t_tx *t)
{
	int l;

	l = 0;
	if (s[l] == 'W')
	{
		t->walls.west = ft_strtrim(s, "WE ");
		if (!(ft_strnstr(t->walls.west, ".xpm", ft_strlen(t->walls.west))))
			ft_error("FAIL .xpm in text WE");
	}
	if (s[l] == 'E')
	{
		t->walls.east = ft_strtrim(s, "EA ");
		if (!(ft_strnstr(t->walls.east, ".xpm", ft_strlen(t->walls.east))))
			ft_error("FAIL .xpm in text EA");
	}
	if (s[l] == 'S')
	{
		t->s.sprite = ft_strtrim(s, "S ");
		if (!(ft_strnstr(t->s.sprite, ".xpm",
			ft_strlen(t->s.sprite))))
			ft_error("FAIL .xpm in text sprite");
	}
	return (0);
}

 int     extract_tx_fc(char *s, t_tx *t)
 {
         int l;
 
         l = 0; 
         if (s[l] == 'F' && s[l + 1] == 'T') 
         { 
                 t->f.floor = ft_strtrim(s, "FT "); 
                 if (!(ft_strnstr(t->f.floor, ".xpm", 
                         ft_strlen(t->f.floor)))) 
                         ft_error("FAIL .xpm in text floor"); 
         } 
         if (s[l] == 'C' && s[l + 1] == 'T') 
         { 
                 t->c.celing = ft_strtrim(s, "CT "); 
                 if (!(ft_strnstr(t->c.celing, ".xpm", 
                         ft_strlen(t->c.celing)))) 
                         ft_error("FAIL .xpm in text celing"); 
         } 
         return (0); 
 } 

