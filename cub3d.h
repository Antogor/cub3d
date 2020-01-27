/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:24:33 by agarzon-          #+#    #+#             */
/*   Updated: 2020/01/27 13:32:53 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
# define _CUB3D_H
# define A 0
# define W 13
# define S 1
# define D 2
# define LEFT 123
# define RIGTH 124
# define ESC 53

# include "./libft/libft.h"
# include "./GNL/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "./minilibx_opengl_20191021/mlx.h"
//# include "./minilibx/mlx.h"

typedef struct	s_lib_cub3d
{
	float		x;
	float		y;
	char		**map;
}				t_vetor;

typedef struct	s_lib_mlx
{
	void *mlx_ptr;
	void *window;
	int *image;
	char *image_data;

}				t_mlx;

#endif
