/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:10:54 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/12 14:20:35 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1},
};

int		raycasting(t_cub3d *cub3d)
{
	cub3d->color->color_r = create_trgb(0, 50, 50, 0);
	cub3d->color->color_g = create_trgb(0, 0, 120, 100);
	cub3d->color->color_b = create_trgb(0, 0, 50, 120);
	cub3d->color->color_t = create_trgb(255, 0, 0, 0);
	cub3d->color->color_w = create_trgb(0, 100, 0, 255);
	cub3d->raycast->x = 0;
	while(cub3d->raycast->x < screenWidth)
	{
		cub3d->raycast->camera_x = 2 * cub3d->raycast->x / (double)screenWidth -1;
		cub3d->raycast->ray_dir_x = cub3d->player->dir_x + cub3d->player->plane_x * cub3d->raycast->camera_x;
		cub3d->raycast->ray_dir_y = cub3d->player->dir_y + cub3d->player->plane_y * cub3d->raycast->camera_x;
		printf("CAMERA: %f\n", cub3d->raycast->camera_x);
		printf("RAYDIRX: %f\n", cub3d->raycast->ray_dir_x);
		printf("RAYDIRY: %f\n", cub3d->raycast->ray_dir_y);
		cub3d->raycast->map_x = (int)cub3d->player->pos_x;
		cub3d->raycast->map_y = (int)cub3d->player->pos_y;
		printf("MAPX: %d\n", cub3d->raycast->map_x);
		printf("MAPY: %d\n", cub3d->raycast->map_y);
		cub3d->raycast->delta_dist_x = sqrt(1 + (cub3d->raycast->ray_dir_y * cub3d->raycast->ray_dir_y) / (cub3d->raycast->ray_dir_x * cub3d->raycast->ray_dir_x));//(cub3d->raycast->ray_dir_y == 0) ? 0 : ((cub3d->raycast->ray_dir_x == 0) ? 1 : abs(1 / cub3d->raycast->ray_dir_x));
    	cub3d->raycast->delta_dist_y = sqrt(1 + (cub3d->raycast->ray_dir_x * cub3d->raycast->ray_dir_x) / (cub3d->raycast->ray_dir_y * cub3d->raycast->ray_dir_y));//(cub3d->raycast->ray_dir_x == 0) ? 0 : ((cub3d->raycast->ray_dir_y == 0) ? 1 : abs(1 / cub3d->raycast->ray_dir_y));
		printf("deltaDistX: %f\n", cub3d->raycast->delta_dist_x);
		printf("deltaDistY: %f\n", cub3d->raycast->delta_dist_x);
		if (cub3d->raycast->ray_dir_x < 0)
      	{
			  cub3d->raycast->step_x = -1;
			  cub3d->raycast->side_dist_x = (cub3d->player->pos_x - cub3d->raycast->map_x) * cub3d->raycast->delta_dist_x;
			  printf("sideDisX: %f\n", cub3d->raycast->delta_dist_x);
      	}
      	else
     	{
        	cub3d->raycast->step_x = 1;
        	cub3d->raycast->side_dist_x = (cub3d->raycast->map_x + 1.0 - cub3d->player->pos_x) * cub3d->raycast->delta_dist_x;
			printf("sideDisX: %f\n", cub3d->raycast->side_dist_x);
      	}
     	 if (cub3d->raycast->ray_dir_y < 0)
      	{
        	cub3d->raycast->step_y = -1;
        	cub3d->raycast->side_dist_y = (cub3d->player->pos_y - cub3d->raycast->map_y) * cub3d->raycast->delta_dist_y;
			printf("sideDisY: %f\n", cub3d->raycast->side_dist_y);
      	}
		else
     	 {
     		cub3d->raycast->step_y = 1;
        	cub3d->raycast->side_dist_y = (cub3d->raycast->map_y + 1.0 - cub3d->player->pos_y) * cub3d->raycast->delta_dist_y;
			printf("sideDisY: %f\n", cub3d->raycast->side_dist_y);
     	 }
		cub3d->raycast->hit = 0;
		while (cub3d->raycast->hit == 0)
    	{
			printf("BUCLE GOLPEA MURO\n");
        	if (cub3d->raycast->side_dist_x < cub3d->raycast->side_dist_y)
        	{
          		cub3d->raycast->side_dist_x += cub3d->raycast->delta_dist_x;
          		cub3d->raycast->map_x += cub3d->raycast->step_x;
          		cub3d->raycast->side = 0;
				printf("sideDisX: %f\n", cub3d->raycast->side_dist_x);
				printf("mapX: %d\n", cub3d->raycast->map_x);
				printf("WE: %d\n", cub3d->raycast->side);
        	}
        	else
        	{
          		cub3d->raycast->side_dist_y += cub3d->raycast->delta_dist_y;
          		cub3d->raycast->map_y += cub3d->raycast->step_y;
          		cub3d->raycast->side = 1;
				printf("sideDisY: %f\n", cub3d->raycast->side_dist_y);
				printf("mapY: %d\n", cub3d->raycast->map_y);
				printf("NS: %d\n", cub3d->raycast->side);
        	}
        	if (worldMap[cub3d->raycast->map_x][cub3d->raycast->map_y] == 1)
				cub3d->raycast->hit = 1;
			printf("HIT: %d\n", cub3d->raycast->hit);
      	}
		if (cub3d->raycast->side == 0)
		{
			if (cub3d->raycast->ray_dir_x == 0)
			{
				cub3d->raycast->wall_dist = 0;
				printf("SIDE = 0 Y RAY DIR = %f\n", cub3d->raycast->ray_dir_x);
			}
			else
			{
				cub3d->raycast->wall_dist = (cub3d->raycast->map_x - cub3d->player->pos_x + (1 - cub3d->raycast->step_x) / 2) / cub3d->raycast->ray_dir_x;
				printf("SIDE = 1 Y RAY DIR X = %f MAP X = %d POS X = %f, STEP X = %d\n", cub3d->raycast->ray_dir_x, cub3d->raycast->map_x, cub3d->player->pos_x, cub3d->raycast->step_x);
			}
		}
      	else
		{
			if (cub3d->raycast->ray_dir_y == 0)
			{
				cub3d->raycast->wall_dist = 0;
				printf("SIDE = 1 Y RAY DIR = %f\n", cub3d->raycast->ray_dir_y);
			}
			else
			{
				cub3d->raycast->wall_dist = (cub3d->raycast->map_y - cub3d->player->pos_y + (1 - cub3d->raycast->step_y) / 2) / cub3d->raycast->ray_dir_y;
				printf("SIDE = 1 Y RAY DIR Y = %f MAP Y = %d POS Y = %f, STEP Y = %d\n", cub3d->raycast->ray_dir_y, cub3d->raycast->map_y, cub3d->player->pos_y, cub3d->raycast->step_y);
			}
		}
		printf("WALL: %f\n", cub3d->raycast->wall_dist);
		cub3d->raycast->line_height = (int)(screenHeight / cub3d->raycast->wall_dist);
		printf("LINEHEIGHT: %d\n", cub3d->raycast->line_height);
      	cub3d->raycast->draw_start = (cub3d->raycast->line_height * -1) / 2 + screenHeight / 2;
		printf("DRAWSTART: %d\n", cub3d->raycast->draw_start);
     	if(cub3d->raycast->draw_start < 0)
			cub3d->raycast->draw_start = 0;
      	cub3d->raycast->draw_end = cub3d->raycast->line_height / 2 + screenHeight / 2;
      	if(cub3d->raycast->draw_end >= screenHeight)
			cub3d->raycast->draw_end = screenHeight - 1;
		printf("DRAWSTART: %d\n", cub3d->raycast->draw_start);
		printf("DRAWEND: %d\n", cub3d->raycast->draw_end);
		paint(cub3d);
		cub3d->raycast->x++;
		printf("X = %d\n", cub3d->raycast->x);
		printf("\n");
	}
	mlx_put_image_to_window(cub3d->mlx->mlx_ptr, cub3d->mlx->window, cub3d->mlx->img, 0, 0);
	
	return (0);
}

