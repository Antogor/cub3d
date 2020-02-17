/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:24:33 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/17 14:23:03 by agarzon-         ###   ########.fr       */
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

# define screenWidth 520
# define screenHeight 360
# define mapWidth 10
# define mapHeight 10

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
# include "./libft/libft.h"
# include "./GNL/get_next_line.h"

typedef struct	s_lib_mlx
{
	void		*mlx_ptr;
	void		*window;
	void		*img;
	int			text_h;
	int			text_w;
	int			*img_data;
	int			bpp;
	int			size_l;
	int			endian;
}				t_mlx;

typedef struct	s_lib_text
{
	char		*text_n;
	void		*text_ptr_n;
	int			*text_d_n;
	char		*text_s;
	void		*text_ptr_s;
	int			*text_d_s;
	char		*text_e;
	void		*text_ptr_e;
	int			*text_d_e;
	char		*text_o;
	void		*text_ptr_o;
	int			*text_d_o;
	char		*text_sprite;
}				t_text;

typedef struct	s_lib_color
{
	int			color_r;
	int			color_g;
	int			color_b;
	int			color_t;
	int			color_w;
	char		**floor_colors;
	char		**celling_colors;
	int			color_floor;
	int			color_celling;
}				t_color;

typedef struct	s_lib_raycast
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		wall_dist;
	int			step_x;
	int			step_y;
	int			x;
	int			map_x;
	int			map_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_raycast;

typedef struct	s_libpalyer
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		speed;
	int			up;
	int			down;
}				t_player;

typedef struct	s_lib_cub3d
{
	char		*read_map;
	char		**map_data;
	char		*resolution;
	int			screen_w;
	int			screen_h;
	char		**map;
	int			map_w;
	int			map_h;
	int			fd;
	t_mlx		*mlx;
	t_color		*color;
	t_raycast	*raycast;
	t_player	*player;
	t_text		*text;
}				t_cub3d;

int				raycasting(t_cub3d *cub3d);
int				ft_keys(t_cub3d *tab);
int				ft_map(char **argv, t_cub3d *map);
void			paint(t_cub3d *cub3d);
int				create_trgb(int t, int r, int g, int b);
int				movement(t_cub3d *cub3d);
int				key_press(int key, t_cub3d *cub3d);
int				key_release(int key, t_cub3d *cub3d);
#endif
