/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:24:14 by agarzon-          #+#    #+#             */
/*   Updated: 2020/01/30 11:29:55 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_cub3d	*tab;
	int		l;
	int		x;
	int		y;

	x = 0;
	y = 0;
	l = 0;
	(void)argc;
	tab = (t_cub3d *)malloc(sizeof(t_cub3d *));
	ft_map(argv[1], tab);
/*	if (argc == 2 || argc == 3)
	{
//		if (ft_strncmp(argv[1], ".cub", 100) == 0)
		
		if (ft_strncmp(argv[2], "--save", 6) == 0)
			printf("FUNCION GUARDAR BMP");
	}
	else
		perror("No map");*/
	free(tab);
	tab = NULL;
	return (0);
}
