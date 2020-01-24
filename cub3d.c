/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:24:14 by agarzon-          #+#    #+#             */
/*   Updated: 2020/01/24 13:09:56 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	int l;
	char *r_line;
	int line;
	
	if (argc == 2)
	{
		l = open(*argv, O_RDONLY);
		line = get_next_line(l, &r_line);
		if (line == 1)
		{
			printf("%s", r_line);
		}
	}
	return (0);
}
