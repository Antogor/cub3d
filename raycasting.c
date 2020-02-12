/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:10:54 by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/12 13:25:59 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define mapWidth 5
#define mapHeight 5


int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1},
  {1,0,0,0,1},
  {1,0,0,0,1},
  {1,0,0,0,1},
  {1,1,1,1,1}
};

int frame(t_mlx *img)
{
	mlx_put_image_to_window(img->mlx_ptr, img->window, img->img, 0, 0);
	return (0);
}

int		raycasting(t_cub3d *cub3d)
{
	cub3d->player->pos_x = 3;
	cub3d->player->pos_y = 3;
	cub3d->player->dir_x = 0;
	cub3d->player->dir_y = -1;
	cub3d->player->plane_x = 0.66;
	cub3d->player->plane_y = 0;
	cub3d->color->color_r = create_trgb(0, 255, 0, 0);
	cub3d->color->color_g = create_trgb(0, 0, 255, 0);
	cub3d->color->color_b = create_trgb(0, 0, 0, 255);
	cub3d->color->color_t = create_trgb(255, 0, 0, 0);
	cub3d->color->color_w = create_trgb(0, 100, 0, 255);
	cub3d->mlx->mlx_ptr = mlx_init();
    cub3d->mlx->window = mlx_new_window(cub3d->mlx->mlx_ptr, screenWidth, screenHeight, "cub3D");
	cub3d->mlx->img = mlx_new_image(cub3d->mlx->mlx_ptr, 520, 360);
    cub3d->mlx->img_data = (int*)mlx_get_data_addr(cub3d->mlx->img, &cub3d->mlx->bpp, &cub3d->mlx->size_l,
                                 &cub3d->mlx->endian);
	cub3d->raycast->x = 0;
	while(cub3d->raycast->x < screenWidth)
	{
		cub3d->raycast->camera_x = 2 * cub3d->raycast->x / (double)screenWidth -1;
		cub3d->raycast->ray_dir_x = cub3d->player->dir_x + cub3d->player->plane_x * cub3d->raycast->camera_x;
		cub3d->raycast->ray_dir_y = cub3d->player->dir_y + cub3d->player->plane_y * cub3d->raycast->camera_x;
		printf("CAMERA: %f\n", cub3d->raycast->camera_x);
		printf("RAYDIRX: %d\n", cub3d->raycast->ray_dir_x);
		printf("RAYDIRY: %d\n", cub3d->raycast->ray_dir_y);
		cub3d->raycast->map_x = (int)cub3d->player->pos_x;
		cub3d->raycast->map_y = (int)cub3d->player->pos_y;
		printf("MAPX: %d\n", cub3d->raycast->map_x);
		printf("MAPY: %d\n", cub3d->raycast->map_y);
		cub3d->raycast->delta_dist_x = (cub3d->raycast->ray_dir_y == 0) ? 0 : ((cub3d->raycast->ray_dir_x == 0) ? 1 : abs(1 / cub3d->raycast->ray_dir_x));
    	cub3d->raycast->delta_dist_x = (cub3d->raycast->ray_dir_x == 0) ? 0 : ((cub3d->raycast->ray_dir_y == 0) ? 1 : abs(1 / cub3d->raycast->ray_dir_y));
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
        	cub3d->raycast->side_dist_y = ((cub3d->raycast->map_y + 1.0) - cub3d->player->pos_y) * cub3d->raycast->delta_dist_y;
			printf("sideDisY: %f\n", cub3d->raycast->side_dist_y);
     	 }
		cub3d->raycast->hit = 0;
		while (cub3d->raycast->hit == 0)
    	{
			printf("ASMAMSKSAK\n");
        	if (cub3d->raycast->side_dist_x < cub3d->raycast->side_dist_y)
        	{
          		cub3d->raycast->side_dist_x += cub3d->raycast->side_dist_x;
          		cub3d->raycast->map_x += cub3d->raycast->step_x;
          		cub3d->raycast->side = 0;
				printf("sideDisX: %f\n", cub3d->raycast->side_dist_x);
				printf("mapX: %d\n", cub3d->raycast->map_x);
				printf("SIDE: %d\n", cub3d->raycast->side);
        	}
        	else
        	{
          		cub3d->raycast->side_dist_y += cub3d->raycast->delta_dist_y;
          		cub3d->raycast->map_y += cub3d->raycast->step_y;
          		cub3d->raycast->side = 1;
				printf("sideDisY: %f\n", cub3d->raycast->side_dist_y);
				printf("mapY: %d\n", cub3d->raycast->map_y);
				printf("SIDE: %d\n", cub3d->raycast->side);
        	}
        	if (worldMap[cub3d->raycast->map_x][cub3d->raycast->map_y] == 1)
				cub3d->raycast->hit = 1;
			printf("HIT: %d\n", cub3d->raycast->hit);
      	}
		if (cub3d->raycast->side == 0)
		{
			if (cub3d->raycast->ray_dir_x == 0)
				cub3d->raycast->wall_dist = 0;
			else
				cub3d->raycast->wall_dist = (cub3d->raycast->map_x - cub3d->player->pos_x + (1 - cub3d->raycast->step_x) / 2) / cub3d->raycast->ray_dir_x;
		}
      	else
		{
			if (cub3d->raycast->ray_dir_y == 0)
				cub3d->raycast->wall_dist = 0;
			else
				cub3d->raycast->wall_dist = (cub3d->raycast->map_y - cub3d->player->pos_y + (1 - cub3d->raycast->step_y) / 2) / cub3d->raycast->ray_dir_y;
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
		printf("SSSS\n");
		paint(cub3d);
		cub3d->raycast->x++;
		printf("X = %d\n", cub3d->raycast->x);
		printf("\n");
	}
	mlx_loop_hook(cub3d->mlx->mlx_ptr, frame, cub3d->mlx);
	mlx_loop(cub3d->mlx->mlx_ptr);
	return (0);
}

