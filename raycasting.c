/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:10:54 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/24 14:36:09 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_side(t_cub3d *cub3d)
{
	if (cub3d->raycast->ray_dir_x < 0)
	{
		cub3d->raycast->step_x = -1;
		cub3d->raycast->side_dist_x = (cub3d->player->pos_x -
			cub3d->raycast->map_x) * cub3d->raycast->delta_dist_x;
	}
	else
	{
		cub3d->raycast->step_x = 1;
		cub3d->raycast->side_dist_x = (cub3d->raycast->map_x + 1.0 -
			cub3d->player->pos_x) * cub3d->raycast->delta_dist_x;
	}
	if (cub3d->raycast->ray_dir_y < 0)
	{
		cub3d->raycast->step_y = -1;
		cub3d->raycast->side_dist_y = (cub3d->player->pos_y -
			cub3d->raycast->map_y) * cub3d->raycast->delta_dist_y;
	}
	else
	{
		cub3d->raycast->step_y = 1;
		cub3d->raycast->side_dist_y = (cub3d->raycast->map_y + 1.0 -
			cub3d->player->pos_y) * cub3d->raycast->delta_dist_y;
	}
}

void	hit_wall(t_cub3d *cub3d)
{
	cub3d->raycast->hit = 0;
	while (cub3d->raycast->hit == 0)
	{
		if (cub3d->raycast->side_dist_x < cub3d->raycast->side_dist_y)
		{
			cub3d->raycast->side_dist_x += cub3d->raycast->delta_dist_x;
			cub3d->raycast->map_x += cub3d->raycast->step_x;
			cub3d->raycast->side = 0;
		}
		else
		{
			cub3d->raycast->side_dist_y += cub3d->raycast->delta_dist_y;
			cub3d->raycast->map_y += cub3d->raycast->step_y;
			cub3d->raycast->side = 1;
		}
		if (cub3d->map[cub3d->raycast->map_y][cub3d->raycast->map_x] == '1')
			cub3d->raycast->hit = 1;
	}
}

void	wall_dist(t_cub3d *cub3d)
{
	if (cub3d->raycast->side == 0)
	{
		cub3d->raycast->wall_dist = (cub3d->raycast->map_x -
			cub3d->player->pos_x + (1 - cub3d->raycast->step_x) / 2) /
			cub3d->raycast->ray_dir_x;
	}
	else
	{
		cub3d->raycast->wall_dist = (cub3d->raycast->map_y -
			cub3d->player->pos_y + (1 - cub3d->raycast->step_y) / 2) /
			cub3d->raycast->ray_dir_y;
	}
}

void	calculate_line_height(t_cub3d *cub3d)
{
	cub3d->raycast->line_height = (int)(cub3d->screen_h /
		cub3d->raycast->wall_dist);
	cub3d->raycast->draw_start = (cub3d->raycast->line_height * -1) /
		2 + cub3d->screen_h / 2;
	if (cub3d->raycast->draw_start <= 0)
		cub3d->raycast->draw_start = 0;
	cub3d->raycast->draw_end = cub3d->raycast->line_height /
		2 + cub3d->screen_h / 2;
	if (cub3d->raycast->draw_end >= cub3d->screen_h)
		cub3d->raycast->draw_end = cub3d->screen_h;
}

int		raycasting(t_cub3d *cub3d)
{
	cub3d->raycast->x = 0;
	while (cub3d->raycast->x < cub3d->screen_w)
	{
		cub3d->raycast->camera_x = 2 * cub3d->raycast->x /
		(double)cub3d->screen_w - 1;
		cub3d->raycast->ray_dir_x = cub3d->player->dir_x +
		cub3d->player->plane_x * cub3d->raycast->camera_x;
		cub3d->raycast->ray_dir_y = cub3d->player->dir_y +
			cub3d->player->plane_y * cub3d->raycast->camera_x;
		cub3d->raycast->map_x = (int)cub3d->player->pos_x;
		cub3d->raycast->map_y = (int)cub3d->player->pos_y;
		cub3d->raycast->delta_dist_x = sqrt(1 + (cub3d->raycast->ray_dir_y *
			cub3d->raycast->ray_dir_y) / (cub3d->raycast->ray_dir_x *
			cub3d->raycast->ray_dir_x));
		cub3d->raycast->delta_dist_y = sqrt(1 + (cub3d->raycast->ray_dir_x *
			cub3d->raycast->ray_dir_x) / (cub3d->raycast->ray_dir_y *
			cub3d->raycast->ray_dir_y));
		calculate_side(cub3d);
		hit_wall(cub3d);
		wall_dist(cub3d);
		calculate_line_height(cub3d);
		paint(cub3d);
		cub3d->raycast->x++;
	}
	return (0);
}
