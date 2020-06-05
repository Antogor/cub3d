/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:24:33 by agarzon-          #+#    #+#             */
/*   Updated: 2020/06/05 10:46:22 by agarzon-         ###   ########.fr       */
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
#  include "Mlx/mlx.h"
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "./srcs/libft/libft.h"
# include <mlx.h>

typedef struct		s_lib_mlx
{
	void			*mlx_ptr;
	void			*window;
	void			*img;
	int				*img_data;
	int				bpp;
	int				size_l;
	int				endian;
}					t_mlx;

typedef struct			s_text_walls
{
	char			*north;
	void			*ptr_north;
	int				*data_north;
	int				north_bpp;
	int				north_sl;
	int				north_end;
	int				north_h;
	int				north_w;
	char			*south;
	void			*ptr_south;
	int				*data_south;
	int				south_bpp;
	int				south_sl;
	int				south_end;
	int				south_h;
	int				south_w;
	char			*east;
	void			*ptr_east;
	int				*data_east;
	int				east_bpp;
	int				east_sl;
	int				east_end;
	int				east_h;
	int				east_w;
	char			*west;
	void			*ptr_west;
	int				*data_west;
	int				west_bpp;
	int				west_sl;
	int				west_end;
	int				west_h;
	int				west_w;
} 					t_walls;

typedef	struct			s_tx_sprite
{
	char			*sprite;
	void			*ptr_sprite;
	int				*data_sprite;
	int				sprite_bpp;
	int				sprite_sl;
	int				sprite_end;
	int				sprite_h;
	int				sprite_w;
} 					t_tx_sprite;

typedef struct			s_tx_floor
{
	char			*floor;
	void			*ptr_floor;
	int				*data_floor;
	int				floor_bpp;
	int				floor_sl;
	int				floor_end;
	int				floor_h;
	int				floor_w;
	float			raydir_x0;
	float			raydir_y0;
	float			raydir_x1;
	float			raydir_y1;
	int				p;
	float			pos_z;
	float			row_dist;
	float			floorstep_x;
	float			floorstep_y;
	float			floor_x;
	float			floor_y;
}					t_floor;

typedef struct			s_tx_celling
{
	char			*celing;
	void			*ptr_celling;
	int				*data_celling;
	int				celling_bpp;
	int				celling_sl;
	int				celling_end;
	int				celling_h;
	int				celling_w;
	int				cell_x;
	int				cell_y;
	int				tx;
	int				ty;
}					t_celling;

typedef struct			s_tx
{
	int				colorc;
	int				colorf;
	int				colortx;
	t_walls		walls;
	t_tx_sprite	s;
	t_floor		f;
	t_celling	c;
}					t_tx;

typedef struct		s_lib_spritetools
{
	double			x;
	double			y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				screen_x;
	int				h;
	int				draw_start_y;
	int				draw_end_y;
	int				w;
	int				draw_start_x;
	int				draw_end_x;
	int				stripe;
	int				tex_x;
	int				s_y;
	int				d;
	int				tex_y;
}					t_spritetools;

typedef struct		s_lib_sprite
{
	double			x;
	double			y;
	double			z_buffer[4000];
	int				*sprite_order;
	int				sprite_nb;
	t_spritetools	tools;
}					t_sprite;


typedef struct		s_lib_color
{
	int				color_r;
	int				color_g;
	int				color_b;
	int				color_t;
	int				color_w;
	char			**color_floor;
	int				floor;
	char			**color_celling;
	int				celling;
}					t_color;

typedef struct		s_lib_raycast
{
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			wall_dist;
	double			wall_x;
	int				step_x;
	int				step_y;
	int				x;
	int				map_x;
	int				map_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
}					t_raycast;

typedef struct		s_libpalyer
{
	char			dir_player;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			speed;
	int				up;
	int				down;
	int				count_player;
}					t_player;

typedef struct		s_map
{
	char		**m;
	int		h;
	int		w;
	int				count_rows;
	int				count_colums;
}			t_map;

typedef struct		s_lib_cub3d
{
	char			*resolution;
	int				screen_w;
	int				screen_h;
//	char			**map;
//	int				map_h;
//	t_mlx			mlx;
	t_color			color;
//	t_raycast		*raycast;
//	t_player		player;
	t_tx			tx;
	t_sprite		sprite;
	t_map			map;
}					t_cub3d;

//int					raycasting(t_cub3d *cub3d, /*t_raycast *raycast,*/
//					t_player *player);
//int					ft_keys(t_cub3d *cub3d);
int					ft_map(char **argv, t_cub3d *cub3d);
int     extract_resolution(char *s, t_cub3d *cub);
int     extract_tx_ns(char *s, t_tx *t);
int     extract_tx_wes(char *s, t_tx *t);
int     extract_tx_fc(char *s, t_tx *t);
int					extract_color(char *s, t_color *c);



//void				paint(t_cub3d *cub3d, t_raycast rayc, t_text *text,
//					t_mlx *mlx);
int					create_trgb(int t, int r, int g, int b);
//int					movement(t_cub3d *cub3d);
//int					key_press(int key, t_cub3d *cub3d);
//int					key_release(int key, t_cub3d *cub3d);
//int					check_data(char *s, t_cub3d *cub3d);
//int					check_map(char **tmp, t_cub3d *cub3d);
//int					is_a_close_map(char **map, int x, int y, int limit);
//int					extract_textures(t_text *text, t_mlx *mlx);
//int					choose_texture(t_cub3d *cub3d, t_text *text, t_raycast rayc);
//int					extract_txt_fc(char *s, t_text *text);
//int					extract_sprite(t_cub3d *cub3d);
//int					raycast_fc(t_cub3d *cub3d, t_text *text, t_mlx *mlx,
//					t_player *player);
//int					raycast_sprite(t_cub3d *cub3d, t_text *text,
//					t_player *player);
void				ft_error(char *s);
//void				save_bitmap(const char *file_name, t_cub3d *cub);
//void				close_game(t_cub3d *cub3d);
#endif
