/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:24:33 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/24 14:12:44 by agarzon-         ###   ########.fr       */
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

typedef struct	s_lib_mlx
{
	void		*mlx_ptr;
	void		*window;
	void		*img;
	int			*img_data;
	int			bpp;
	int			size_l;
	int			endian;
}				t_mlx;

typedef struct	s_lib_text
{
	int			text;
	char		text_wall_dir;
	int			*text_dat;
	int			text_sl;
	int			text_h;
	int			text_wi;
	char		*text_n;
	void		*text_ptr_n;
	int			*text_d_n;
	int			text_n_bpp;
	int			text_n_sl;
	int			text_n_end;
	int			text_n_h;
	int			text_n_w;
	char		*text_s;
	void		*text_ptr_s;
	int			*text_d_s;
	int			text_s_bpp;
	int			text_s_sl;
	int			text_s_end;
	int			text_s_h;
	int			text_s_w;
	char		*text_e;
	void		*text_ptr_e;
	int			*text_d_e;
	int			text_e_bpp;
	int			text_e_sl;
	int			text_e_end;
	int			text_e_h;
	int			text_e_w;
	char		*text_w;
	void		*text_ptr_w;
	int			*text_d_w;
	int			text_w_bpp;
	int			text_w_sl;
	int			text_w_end;
	int			text_w_h;
	int			text_w_w;
	char		*text_sprite;
	char		*text_floor;
	char		*text_celing;
}				t_text;

typedef struct	s_lib_color
{
	int			color_r;
	int			color_g;
	int			color_b;
	int			color_t;
	int			color_w;
	char		**color_floor;
	int			floor;
	char		**color_celling;
	int			celling;
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
	double		wall_x;
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
	char		*resolution;
	int			screen_w;
	int			screen_h;
	char		dir_player;
	char		**map;
	int			map_w;
	int			map_h;
	int			fd;
	int			count_rows;
	int			count;
	t_mlx		*mlx;
	t_color		*color;
	t_raycast	*raycast;
	t_player	*player;
	t_text		*text;
}				t_cub3d;

int				raycasting(t_cub3d *cub3d);
int				ft_keys(t_cub3d *cub3d);
int				ft_map(char **argv, t_cub3d *map);
void			paint(t_cub3d *cub3d);
int				create_trgb(int t, int r, int g, int b);
int				movement(t_cub3d *cub3d);
int				key_press(int key, t_cub3d *cub3d);
int				key_release(int key, t_cub3d *cub3d);
int				check_data(char *s, t_cub3d *cub3d);
int				check_map(t_cub3d *cub3d);
int				extract_color(char *s, t_cub3d *cub3d);
int				extract_textures(t_cub3d *cub3d);
int				choose_texture(t_cub3d *cub3d);
int				extract_txt_fc(char *s, t_cub3d *cub3d);

#endif
