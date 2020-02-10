/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:24:33 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/10 17:02:05 by agarzon-         ###   ########.fr       */
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

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
# include "./libft/libft.h"
# include "./GNL/get_next_line.h"
//# include "./minilibx_opengl_20191021/mlx.h"
//# include "./minilibx_mms_20191025_beta/mlx.h"

typedef struct	s_lib_mlx
{
	void		*mlx_ptr;
	void		*window;
	void		*img;
	int			*img_data;
	int			bpp;
	int			size_l;
	int			endian;
	int x;
	int y;
}				t_mlx;

typedef struct	s_lib_color
{
	int colorR;
	int colorG;
	int colorB;
	int colorT;
}				t_color;

typedef struct	s_lib_cub3d
{
	char		**resolution;
	char		*text_n;
	char		*text_s;
	char		*text_e;
	char		*text_o;
	char		*text_sprite;
	int			floor_colors;
	int			celling_colors;
	char		**map;
	int			x;
	int			y;
	int			fd;
	t_mlx		*mlx;
	t_color		*color;
}				t_cub3d;

int				ft_keys(t_cub3d *tab);
int				ft_map(t_cub3d *map);
void			paint(t_mlx *print, int color, int fin_x, int fin_y);
int				create_trgb(int t, int r, int g, int b);
#endif
