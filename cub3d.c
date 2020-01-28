/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:24:14 by agarzon-          #+#    #+#             */
/*   Updated: 2020/01/28 17:26:23 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		deal_key(int key, t_mlx *tab)
{
	if (key == ESC)
		exit(ESC);
	else if (key == A)
	{
		mlx_pixel_put(tab->mlx_ptr, tab->window, 300, 600, 0x23BAC4);
	}
//	ft_putnbr_fd(key, 1);
	return(0);
}

int		main(int argc, char **argv)
{
	t_mlx *tab;
	int fd;
	int bwr;
	char *buff[4096];

	tab = (t_mlx *)malloc(sizeof(t_mlx *));
	if (argc == 2 || argc == 3)
	{
		fd = open(argv[1], O_RDONLY);
		while ((bwr = read(fd, buff, 4096)))
		{
			get_next_line(fd, &buff);
		}
		printf("%s", buff);
		tab->mlx_ptr = mlx_init();
		tab->window = mlx_new_window(tab->mlx_ptr, X, Y, "cub3d");
//		mlx_xpm_to_image (tab->mlx_ptr, &buff[bwr], (int *)100, (int *)50);
		mlx_key_hook(tab->window, deal_key, tab);
		mlx_loop(tab->mlx_ptr);
	}
	else
	{
		write(1, "Error\n", 6);
	}
	free(tab);
	tab = NULL;
	return (0);
}
