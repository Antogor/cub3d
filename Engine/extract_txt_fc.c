/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_txt_fc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:47:13 by agarzon-          #+#    #+#             */
/*   Updated: 2020/06/05 19:20:52 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	extract_txt_fc(char *s, t_tx *t)
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
	return (1);
}
