/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_fc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:36:55 by agarzon-          #+#    #+#             */
/*   Updated: 2020/03/09 11:14:23 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	choose_color(t_color *color, t_text *text)
{
	if (text->text_floor && text->text_celing)
	{
		text->colorc = text->text_d_celing[text->ty * text->text_celing_h +
			text->tx];
		text->colorf = text->text_d_floor[text->ty * text->text_floor_h +
			text->tx];
	}
	else
	{
		text->colorc = color->celling;
		text->colorf = color->floor;
	}
}

void	put_fc(t_cub3d *cub3d, t_text *text, t_mlx *mlx, int y)
{
	int x;

	x = 0;
	while (x < cub3d->screen_w)
	{
		text->cell_x = (int)text->floor_x;
		text->cell_y = (int)text->floor_y;
		text->tx = (int)(text->text_floor_w * (text->floor_x - text->cell_x)) &
			(text->text_floor_w - 1);
		text->ty = (int)(text->text_floor_h * (text->floor_y - text->cell_y)) &
			(text->text_floor_h - 1);
		text->floor_x += text->floorstep_x;
		text->floor_y += text->floorstep_y;
		choose_color(cub3d->color, text);
		mlx->img_data[(cub3d->screen_h - y - 1) * cub3d->screen_w + x] =
			text->colorc;
		mlx->img_data[y * cub3d->screen_w + x] = text->colorf;
		x++;
	}
}

int		raycast_fc(t_cub3d *cub3d, t_text *text, t_mlx *mlx,
	t_player *player)
{
	int			y;

	y = cub3d->screen_h / 2 + 1;
	while (y < cub3d->screen_h)
	{
		text->raydir_x0 = player->dir_x - player->plane_x;
		text->raydir_y0 = player->dir_y - player->plane_y;
		text->raydir_x1 = player->dir_x + player->plane_x;
		text->raydir_y1 = player->dir_y + player->plane_y;
		text->p = y - cub3d->screen_h / 2;
		text->pos_z = 0.5 * cub3d->screen_h;
		text->row_dist = text->pos_z / text->p;
		text->floorstep_x = text->row_dist * (text->raydir_x1 - text->raydir_x0)
			/ cub3d->screen_w;
		text->floorstep_y = text->row_dist * (text->raydir_y1 - text->raydir_y0)
			/ cub3d->screen_w;
		text->floor_x = player->pos_x + text->row_dist * text->raydir_x0;
		text->floor_y = player->pos_y + text->row_dist * text->raydir_y0;
		put_fc(cub3d, text, mlx, y);
		y++;
	}

/*	 double floorXWall, floorYWall; //x, y position of the floor texel at the bottom of the wall

      //4 different wall directions possible
      if(cub3d->raycast->side == 0 && cub3d->raycast->ray_dir_x > 0)
      {
        floorXWall = cub3d->map_w;
        floorYWall = cub3d->map_h + cub3d->raycast->wall_x;
      }
      else if(cub3d->raycast->side == 0 && cub3d->raycast->ray_dir_x < 0)
      {
        floorXWall = cub3d->map_w + 1.0;
        floorYWall = cub3d->map_h + cub3d->raycast->wall_x;;
      }
      else if(cub3d->raycast->side == 1 && cub3d->raycast->ray_dir_y > 0)
      {
        floorXWall = cub3d->map_w + cub3d->raycast->wall_x;
        floorYWall = cub3d->map_h;
      }
      else
      {
        floorXWall = cub3d->map_w + cub3d->raycast->wall_x;
        floorYWall = cub3d->map_h + 1.0;
      }

      double distWall, distPlayer, currentDist;

      distWall = cub3d->raycast->wall_dist;
      distPlayer = 0.0;

      if(cub3d->raycast->draw_end < 0) cub3d->raycast->draw_end = cub3d->screen_h; //becomes < 0 when the integer overflows

      //draw the floor from drawEnd to the bottom of the screen
	  int y = cub3d->raycast->draw_end + 1;
      while(y < cub3d->screen_h)
      {
        currentDist = cub3d->screen_h / (2.0 * y - cub3d->screen_h); //you could make a small lookup table for this instead

        double weight = (currentDist - distPlayer) / (distWall - distPlayer);

        double currentFloorX = weight * floorXWall + (1.0 - weight) * player->pos_x;
        double currentFloorY = weight * floorYWall + (1.0 - weight) * player->pos_y;

        int floorTexX, floorTexY;
        floorTexX = (int)(currentFloorX * text->text_floor_w) & (text->text_floor_w - 1);
        floorTexY = (int)(currentFloorY * text->text_floor_h) & (text->text_floor_h - 1);

        int checkerBoardPattern = ((int)currentFloorX + (int)currentFloorY) & 1;
        int floorTexture;
        if(checkerBoardPattern == 0) floorTexture = 3;
        else floorTexture = 4;

        //floor
		mlx->img_data[y * cub3d->screen_w + cub3d->raycast->x] = text->text_d_floor[text->text_floor_w  * floorTexY + floorTexX];
        //ceiling (symmetrical)
       	mlx->img_data[cub3d->screen_h - y + cub3d->raycast->x] = text->text_d_celing[text->text_celing_w * floorTexY + floorTexX];
		y++;
	  }*/
	return (1);
}
