/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:10:54 by agarzon-          #+#    #+#             */
/*   Updated: 2020/06/04 13:30:33 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_side(t_raycast *rc, t_player *player)
{
	if (rc->ray_dir_x < 0)
	{
		rc->step_x = -1;
		rc->side_dist_x = (player->pos_x -
			rc->map_x) * rc->delta_dist_x;
	}
	else
	{
		rc->step_x = 1;
		rc->side_dist_x = (rc->map_x + 1.0 -
			player->pos_x) * rc->delta_dist_x;
	}
	if (rc->ray_dir_y < 0)
	{
		rc->step_y = -1;
		rc->side_dist_y = (player->pos_y -
			rc->map_y) * rc->delta_dist_y;
	}
	else
	{
		rc->step_y = 1;
		rc->side_dist_y = (rc->map_y + 1.0 -
			player->pos_y) * rc->delta_dist_y;
	}
}

void	hit_wall(t_cub3d *cub3d, t_raycast *rc)
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
		if (cub3d->map[rc->map_x][rc->map_y] == '1')
			rc->hit = 1;
	}
}

void	wall_dist(t_raycast *rc, t_player *player, t_text *text, t_cub3d *cub3d)
{
	if (rc->side == 0)
	{
		if (rc->map_x < player->pos_x)
			text->text_wall_dir = 'N';
		else
			text->text_wall_dir = 'S';
		rc->wall_dist = (rc->map_x - player->pos_x +
			(1 - rc->step_x) / 2) / rc->ray_dir_x;
		rc->wall_x = player->pos_y + rc->wall_dist *
			rc->ray_dir_y;
	}
	else
	{
		if (rc->map_y < player->pos_y)
			text->text_wall_dir = 'W';
		else
			text->text_wall_dir = 'E';
		rc->wall_dist = (rc->map_y - player->pos_y +
			(1 - rc->step_y) / 2) / rc->ray_dir_y;
		rc->wall_x = player->pos_x + rc->wall_dist *
			rc->ray_dir_x;
	}
	rc->wall_x -= floor((rc->wall_x));
	cub3d->z_buffer[rc->x] = rc->wall_dist;
}

void	calculate_line_height(t_cub3d *cub3d, t_raycast *rc)
{
	rc->line_height = (int)(cub3d->screen_h / rc->wall_dist);
	rc->draw_start = (rc->line_height * -1) / 2 + cub3d->screen_h / 2;
	if (rc->draw_start <= 0)
		rc->draw_start = 0;
	rc->draw_end = rc->line_height / 2 + cub3d->screen_h / 2;
	if (rc->draw_end >= cub3d->screen_h)
		rc->draw_end = cub3d->screen_h;
	choose_texture(cub3d, cub3d->text, (*rc));
}

int		raycasting(t_cub3d *cub3d, /*t_raycast *raycast,*/ t_player *player)
{
    	t_raycast rc;
	rc.x = 0;
	while (rc.x < cub3d->screen_w)
	{
		rc.camera_x = 2 * rc.x / (double)cub3d->screen_w - 1;
		rc.ray_dir_x = player->dir_x + player->plane_x *
			rc.camera_x;
		rc.ray_dir_y = player->dir_y + player->plane_y *
			rc.camera_x;
		rc.map_x = (int)player->pos_x;
		rc.map_y = (int)player->pos_y;
		rc.delta_dist_x = sqrt(1 + (rc.ray_dir_y *
			rc.ray_dir_y) / (rc.ray_dir_x * rc.ray_dir_x));
		rc.delta_dist_y = sqrt(1 + (rc.ray_dir_x *
			rc.ray_dir_x) / (rc.ray_dir_y * rc.ray_dir_y));
		calculate_side(&rc, player);
		hit_wall(cub3d, &rc);
		wall_dist(&rc, player, cub3d->text, cub3d);
		calculate_line_height(cub3d, &rc);
		paint(cub3d, rc, cub3d->text, cub3d->mlx);
		rc.x++;
	}
	return (0);
}
