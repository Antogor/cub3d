/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:24:33 by agarzon-          #+#    #+#             */
/*   Updated: 2020/06/07 17:51:04 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
# define _CUB3D_H

# ifdef __linux__
#  define A 97
#  define W 119
#  define S 115
#  define D 100
#  define LEFT 65361
#  define RIGTH 65363
#  define ESC 65307
#  include <X11/Xlib.h>
# endif

# ifdef __APPLE__
#  define A 0
#  define W 13
#  define S 1
#  define D 2
#  define LEFT 123
#  define RIGTH 124
#  define ESC 53
#  include <mlx.h>
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "./srcs/libft/libft.h"
# include <mlx.h>

typedef struct	s_lib_mlx
{
	void		*ptr;
	void		*win;
	void		*img;
	int			*i_data;
	int			bpp;
	int			size_l;
	int			endian;
}				t_mlx;

typedef struct	s_text_walls
{
	char		*north;
	void		*p_no;
	int			*data_no;
	int			no_bpp;
	int			no_sl;
	int			no_end;
	int			no_h;
	int			no_w;
	char		*south;
	void		*p_so;
	int			*data_so;
	int			so_bpp;
	int			so_sl;
	int			so_end;
	int			so_h;
	int			so_w;
	char		*east;
	void		*p_ea;
	int			*data_ea;
	int			ea_bpp;
	int			ea_sl;
	int			ea_end;
	int			ea_h;
	int			ea_w;
	char		*west;
	void		*p_we;
	int			*data_we;
	int			we_bpp;
	int			we_sl;
	int			we_end;
	int			we_h;
	int			we_w;
}				t_walls;

typedef	struct	s_tx_sprite
{
	char		*sprite;
	void		*p_s;
	int			*data;
	int			bpp;
	int			sl;
	int			end;
	int			h;
	int			w;
}				t_tx_sprite;

typedef struct	s_tx_floor
{
	char		*floor;
	void		*p_f;
	int			*data;
	int			bpp;
	int			sl;
	int			end;
	int			h;
	int			w;
}				t_floor;

typedef struct	s_tx_celling
{
	char		*celing;
	void		*p_c;
	int			*data;
	int			bpp;
	int			sl;
	int			end;
	int			h;
	int			w;
}				t_celling;

typedef struct	s_fc_tools
{
	float		raydir_x0;
	float		raydir_y0;
	float		raydir_x1;
	float		raydir_y1;
	int			p;
	float		pos_z;
	float		row_dist;
	float		floorstep_x;
	float		floorstep_y;
	float		floor_x;
	float		floor_y;
	int			cell_x;
	int			cell_y;
	int			tx;
	int			ty;
}				t_fc_tools;

typedef struct	s_tx
{
	int			txt;
	int			*data;
	int			bpp;
	int			sl;
	int			end;
	int			h;
	int			w;
	int			colorc;
	int			colorf;
	int			colortx;
	char		wall_dir;
	t_walls		walls;
	t_tx_sprite	s;
	t_floor		f;
	t_celling	c;
	t_fc_tools	tool;
}				t_tx;

typedef struct	s_lib_spritetools
{
	double		x;
	double		y;
	double		inv_det;
	double		transform_x;
	double		transform_y;
	int			screen_x;
	int			h;
	int			draw_start_y;
	int			draw_end_y;
	int			w;
	int			draw_start_x;
	int			draw_end_x;
	int			stripe;
	int			tex_x;
	int			s_y;
	int			d;
	int			tex_y;
}				t_spritetools;

typedef struct	s_lib_sprite
{
	double		x;
	double		y;
}				t_sprite;

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
	char		dir_player;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		speed;
	int			up;
	int			down;
	int			count_player;
}				t_player;

typedef struct	s_map
{
	char		**m;
	int			h;
	int			w;
	int			count_rows;
	int			count_colums;
}				t_map;

typedef struct	s_check
{
	int			r;
	int			ns;
	int			wes;
	int			fc;
	int			tfc;
}				t_check;

typedef struct	s_lib_cub3d
{
	char		*resolution;
	int			screen_w;
	int			screen_h;
	double		z_buffer[4000];
	int			*s_order;
	int			s_nb;
	t_mlx		mlx;
	t_color		color;
	t_player	pl;
	t_tx		tx;
	t_sprite	*sprite;
	t_map		map;
	t_check		ch;
}				t_cub3d;

int				raycasting(t_cub3d *cub, t_player pl);
void			save_bitmap(const char *file_name, t_cub3d *cub);
int				ft_events(t_cub3d *cub3d);
int				ft_map(char **argv, t_cub3d *cub3d);
int				extract_resolution(char *s, t_cub3d *cub);
int				extract_tx_ns(char *s, t_tx *t);
int				extract_tx_wes(char *s, t_tx *t);
int				extract_tx_fc(char *s, t_tx *t);
int				extract_color(char *s, t_color *c);
void			paint(t_raycast rc, t_tx *t, t_mlx *ml, int h);
int				create_trgb(int t, int r, int g, int b);
int				movement(t_cub3d *cub3d);
t_player		extract_player(char **m, int limit);
int				extract_textures(t_tx *t, t_mlx mlx);
int				choose_texture(t_tx *t, t_raycast r);
int				extract_txt_fc(char *s, t_tx *text);
int				extract_sprite(t_cub3d *c, char **m);
int				raycast_fc(t_cub3d *c, t_fc_tools *t, t_mlx *ml, t_player pl);
int				raycast_sprite(t_cub3d *c, t_player pl);
void			ft_error(char *s);
void			close_game(t_cub3d *cub3d);
#endif
