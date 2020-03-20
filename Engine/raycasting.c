/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:10:54 by agarzon-          #+#    #+#             */
/*   Updated: 2020/03/09 11:49:11 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_side(t_raycast *raycast, t_player *player)
{
	if (raycast->ray_dir_x < 0)
	{
		raycast->step_x = -1;
		raycast->side_dist_x = (player->pos_x -
			raycast->map_x) * raycast->delta_dist_x;
	}
	else
	{
		raycast->step_x = 1;
		raycast->side_dist_x = (raycast->map_x + 1.0 -
			player->pos_x) * raycast->delta_dist_x;
	}
	if (raycast->ray_dir_y < 0)
	{
		raycast->step_y = -1;
		raycast->side_dist_y = (player->pos_y -
			raycast->map_y) * raycast->delta_dist_y;
	}
	else
	{
		raycast->step_y = 1;
		raycast->side_dist_y = (raycast->map_y + 1.0 -
			player->pos_y) * raycast->delta_dist_y;
	}
}

void	hit_wall(t_cub3d *cub3d, t_raycast *raycast)
{
	raycast->hit = 0;
	while (raycast->hit == 0)
	{
		if (raycast->side_dist_x < raycast->side_dist_y)
		{
			raycast->side_dist_x += raycast->delta_dist_x;
			raycast->map_x += raycast->step_x;
			raycast->side = 0;
		}
		else
		{
			raycast->side_dist_y += raycast->delta_dist_y;
			raycast->map_y += raycast->step_y;
			raycast->side = 1;
		}
		if (cub3d->map[raycast->map_x][raycast->map_y] == '1')
			raycast->hit = 1;
	}
}

void	wall_dist(t_raycast *raycast, t_player *player, t_text *text)
{
	if (raycast->side == 0)
	{
		if (raycast->map_x < player->pos_x)
			text->text_wall_dir = 'W';
		else
			text->text_wall_dir = 'E';
		raycast->wall_dist = (raycast->map_x - player->pos_x +
			(1 - raycast->step_x) / 2) / raycast->ray_dir_x;
		raycast->wall_x = player->pos_y + raycast->wall_dist *
			raycast->ray_dir_y;
	}
	else
	{
		if (raycast->map_y < player->pos_y)
			text->text_wall_dir = 'N';
		else
			text->text_wall_dir = 'S';
		raycast->wall_dist = (raycast->map_y - player->pos_y +
			(1 - raycast->step_y) / 2) / raycast->ray_dir_y;
		raycast->wall_x = player->pos_x + raycast->wall_dist *
			raycast->ray_dir_x;
	}
	raycast->wall_x -= floor((raycast->wall_x));
}

void	calculate_line_height(t_cub3d *cub3d, t_raycast *raycast)
{
	raycast->line_height = (int)(2 * cub3d->screen_h / raycast->wall_dist);
	raycast->draw_start = (raycast->line_height * -1) / 2 + cub3d->screen_h / 2;
	if (raycast->draw_start <= 0)
		raycast->draw_start = 0;
	raycast->draw_end = raycast->line_height / 2 + cub3d->screen_h / 2;
	if (raycast->draw_end >= cub3d->screen_h)
		raycast->draw_end = cub3d->screen_h;
	choose_texture(cub3d, cub3d->text);
}

int		raycasting(t_cub3d *cub3d, t_raycast *raycast, t_player *player)
{
	raycast->x = 0;
	while (raycast->x < cub3d->screen_w)
	{
		raycast->camera_x = 2 * raycast->x / (double)cub3d->screen_w - 1;
		raycast->ray_dir_x = player->dir_x + player->plane_x *
			raycast->camera_x;
		raycast->ray_dir_y = player->dir_y + player->plane_y *
			raycast->camera_x;
		raycast->map_x = (int)player->pos_x;
		raycast->map_y = (int)player->pos_y;
		raycast->delta_dist_x = sqrt(1 + (raycast->ray_dir_y *
			raycast->ray_dir_y) / (raycast->ray_dir_x * raycast->ray_dir_x));
		raycast->delta_dist_y = sqrt(1 + (raycast->ray_dir_x *
			raycast->ray_dir_x) / (raycast->ray_dir_y * raycast->ray_dir_y));
		calculate_side(raycast, player);
		hit_wall(cub3d, raycast);
		wall_dist(raycast, player, cub3d->text);
		cub3d->z_buffer[raycast->x] = raycast->wall_dist;
		calculate_line_height(cub3d, raycast);
		paint(cub3d, raycast, cub3d->text, cub3d->mlx);
	//	raycast_fc(cub3d, cub3d->text, cub3d->mlx, cub3d->player);
		raycast->x++;
	}
	return (0);
}
