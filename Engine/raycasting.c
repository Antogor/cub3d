/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:10:54 by agarzon-          #+#    #+#             */
/*   Updated: 2020/06/05 19:00:55 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_side(t_raycast *rc, t_player pl)
{
	if (rc->ray_dir_x < 0)
	{
		rc->step_x = -1;
		rc->side_dist_x = (pl.pos_x -
			rc->map_x) * rc->delta_dist_x;
	}
	else
	{
		rc->step_x = 1;
		rc->side_dist_x = (rc->map_x + 1.0 -
			pl.pos_x) * rc->delta_dist_x;
	}
	if (rc->ray_dir_y < 0)
	{
		rc->step_y = -1;
		rc->side_dist_y = (pl.pos_y -
			rc->map_y) * rc->delta_dist_y;
	}
	else
	{
		rc->step_y = 1;
		rc->side_dist_y = (rc->map_y + 1.0 -
			pl.pos_y) * rc->delta_dist_y;
	}
}

void	hit_wall(char **m, t_raycast *rc)
{
	rc->hit = 0;
	while (rc->hit == 0)
	{
		if (rc->side_dist_x < rc->side_dist_y)
		{
			rc->side_dist_x += rc->delta_dist_x;
			rc->map_x += rc->step_x;
			rc->side = 0;
		}
		else
		{
			rc->side_dist_y += rc->delta_dist_y;
			rc->map_y += rc->step_y;
			rc->side = 1;
		}
		if (m[rc->map_x][rc->map_y] == '1')
			rc->hit = 1;
	}
}

void	wall_dist(t_raycast *rc, t_player pl, t_tx *t, t_cub3d *c)
{
	if (rc->side == 0)
	{
		if (rc->map_x < pl.pos_x)
			t->wall_dir = 'N';
		else
			t->wall_dir = 'S';
		rc->wall_dist = (rc->map_x - pl.pos_x +
			(1 - rc->step_x) / 2) / rc->ray_dir_x;
		rc->wall_x = pl.pos_y + rc->wall_dist *
			rc->ray_dir_y;
	}
	else
	{
		if (rc->map_y < pl.pos_y)
			t->wall_dir = 'W';
		else
			t->wall_dir = 'E';
		rc->wall_dist = (rc->map_y - pl.pos_y +
			(1 - rc->step_y) / 2) / rc->ray_dir_y;
		rc->wall_x = pl.pos_x + rc->wall_dist *
			rc->ray_dir_x;
	}
	rc->wall_x -= floor((rc->wall_x));
	c->z_buffer[rc->x] = rc->wall_dist;
}

void	calculate_line_height(int h, t_raycast *rc)
{
	rc->line_height = (int)(h / rc->wall_dist);
	rc->draw_start = (rc->line_height * -1) / 2 + h / 2;
	if (rc->draw_start <= 0)
		rc->draw_start = 0;
	rc->draw_end = rc->line_height / 2 + h / 2;
	if (rc->draw_end >= h)
		rc->draw_end = h;
}

int		raycasting(t_cub3d *cub, t_player pl)
{
    	t_raycast rc;
	rc.x = 0;
	while (rc.x < cub->screen_w)
	{
		rc.camera_x = 2 * rc.x / (double)cub->screen_w - 1;
		rc.ray_dir_x = pl.dir_x + pl.plane_x * rc.camera_x;
		rc.ray_dir_y = pl.dir_y + pl.plane_y * rc.camera_x;
		rc.map_x = (int)pl.pos_x;
		rc.map_y = (int)pl.pos_y;
		rc.delta_dist_x = sqrt(1 + (rc.ray_dir_y *
			rc.ray_dir_y) / (rc.ray_dir_x * rc.ray_dir_x));
		rc.delta_dist_y = sqrt(1 + (rc.ray_dir_x *
			rc.ray_dir_x) / (rc.ray_dir_y * rc.ray_dir_y));
		calculate_side(&rc, pl);
		hit_wall(cub->map.m, &rc);
		wall_dist(&rc, pl, &cub->tx, cub);
		calculate_line_height(cub->screen_h, &rc);
		choose_texture(&cub->tx, rc);
		paint(rc, &cub->tx, &cub->mlx, cub->screen_h);
		rc.x++;
	}
	return (0);
}
