/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/10 17:38:32 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define mapWidth 5
#define mapHeight 5
#define screenWidth 520
#define screenHeight 360
#define GREY 808080
#define RGB_RED 0xFF0000
#define RGB_GREEN 0x008000
#define RGB_BLUE 0x0000FF
#define RGB_WHITE 0xFFFFFF
#define RGB_YELLOW 0xFFFF00

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1},
  {1,0,0,0,1},
  {1,0,0,0,1},
  {1,0,0,0,1},
  {1,1,1,1,1}
};

void            my_mlx_pixel_put(t_mlx *data, int x, int start, t_color *color2, int end)
{
	int i = 0;
	int y = 0;
	while(i < start)
	{
		*(data->img_data + x + i * data->size_l / 4) = color2->colorR;
		i++;
	}
	while (i < end)
	{
		*(data->img_data + x + i * data->size_l / 4) = color2->colorG;
		i++;
	}
	while (i < screenHeight)
	{
		*(data->img_data + x + i * data->size_l / 4) = color2->colorB;
		i++;
	}
	
}

int frame(t_mlx *img)
{
	mlx_put_image_to_window(img->mlx_ptr, img->window, img->img, 0, 0);
}
int		main(int argc, char **argv)
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double cameraX;
	double raydirX;
	double raydirY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	int stepX;
	int stepY;
	int x;
	int mapX;
	int mapY;
	int hit;
	int side;
	int rayDirX;
	int rayDirY;
	int h;
	int lineHeight;
    int drawStart;
	int drawEnd;
	int color;
	void *ptr;
	void *window;
//	t_data data;
	
	posX = 1.8;
	posY = 1;
	dirX = 0;
	dirY = 1;
	planeX = 0.66;
	planeY = 0;
	hit = 0;
	t_mlx	*img;
	t_color	*color2;

	img = (t_mlx *)malloc(sizeof(t_mlx));
	color2 = (t_color *)malloc(sizeof(t_color));
	color2->colorR = create_trgb(0, 255, 0, 0);
	color2->colorG = create_trgb(0, 0, 255, 0);
	color2->colorB = create_trgb(255, 0, 0, 255);
	color2->colorT = create_trgb(255, 0, 0, 0);
	img->mlx_ptr = mlx_init();
    img->window = mlx_new_window(img->mlx_ptr, screenWidth, screenHeight, "cub3D");
	img->img = mlx_new_image(img->mlx_ptr, 520, 360);
    img->img_data = (int*)mlx_get_data_addr(img->img, &img->bpp, &img->size_l,
                                 &img->endian);
	x = 0;
	while(x < screenWidth)
	{
		cameraX = 2 * x / (double)screenWidth -1;
		rayDirX = dirX + planeX * cameraX;
		rayDirY = dirY + planeY * cameraX;
		printf("CAMERA: %f\n", cameraX);
		printf("RAYDIRX: %d\n", rayDirX);
		printf("RAYDIRY: %d\n", rayDirY);
		mapX = (int)posX;
		mapY = (int)posY;
		printf("MAPX: %d\n", mapX);
		printf("MAPY: %d\n", mapY);
		deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : fabs(1 / rayDirX));
    	deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : fabs(1 / rayDirY));
		printf("deltaDistX: %f\n", deltaDistX);
		printf("deltaDistY: %f\n", deltaDistY);
		if (rayDirX < 0)
      	{
			  stepX = -1;
			  sideDistX = (posX - mapX) * deltaDistX;
			  printf("sideDisX: %f\n", sideDistX);
      	}
      	else
     	{
        	stepX = 1;
        	sideDistX = (mapX + 1.0 - posX) * deltaDistX;
			printf("sideDisX: %f\n", sideDistX);
      	}
     	 if (rayDirY < 0)
      	{
        	stepY = -1;
        	sideDistY = (posY - mapY) * deltaDistY;
			printf("sideDisY: %f\n", sideDistY);
      	}
		else
     	 {
     		stepY = 1;
        	sideDistY = ((mapY + 1.0) - posY) * deltaDistY;
			printf("sideDisY: %f\n", sideDistY);
     	 }
		hit = 0;
		while (hit == 0)
    	{
			printf("ASMAMSKSAK\n");
        	if (sideDistX < sideDistY)
        	{
          		sideDistX += deltaDistX;
          		mapX += stepX;
          		side = 0;
				printf("sideDisX: %f\n", sideDistX);
				printf("mapX: %d\n", mapX);
        	}
        	else
        	{
          		sideDistY += deltaDistY;
          		mapY += stepY;
          		side = 1;
				printf("sideDisY: %f\n", sideDistY);
				printf("mapY: %d\n", mapX);
        	}
        	if (worldMap[mapX][mapY] == 1)
				hit = 1;
      	}
		printf("HIT: %d\n", hit);
		if (side == 0)
		{
			if (rayDirX == 0)
				perpWallDist = 0;
			else
				perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
		}
      	else
		{
			if (rayDirY == 0)
				perpWallDist = 0;
			else
				perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;
		}
		printf("WALL: %f\n", perpWallDist);
		//if (perpWallDist == 0)
		//	lineHeight = 0;
		//else
		lineHeight = (int)(screenHeight / perpWallDist);
		printf("LINEHEIGHT: %d\n", lineHeight);
      	drawStart = (lineHeight * -1) / 2 + screenHeight / 2;
		printf("DRAWSTART: %d\n", drawStart);
     	if(drawStart < 0)
			drawStart = 0;
      	drawEnd = lineHeight / 2 + screenHeight / 2;
      	if(drawEnd >= screenHeight)
			drawEnd = screenHeight - 1;
		printf("DRAWSTART: %d\n", drawStart);
		printf("DRAWEND: %d\n", drawEnd);
		printf("SSSS\n");
		my_mlx_pixel_put(img, x, drawStart, color2, drawEnd);
		mlx_loop_hook(img->mlx_ptr, frame, img);
		x++;
		printf("X = %d\n", x);
		printf("\n");
	}
	mlx_loop(img->mlx_ptr);
	/*
	t_cub3d	*tab;

	(void)argc;
	tab = (t_cub3d *)malloc(sizeof(t_cub3d *));
	fd = open(argv[1], O_RDONLY);
	ft_map(tab);
	if (argc == 0 || argc == 0)
	{
		if (ft_strncmp(argv[1], ".cub", 100) == 0)
		
		if (ft_strncmp(argv[2], "--save", 6) == 0)
			printf("FUNCION GUARDAR BMP");
	}
	else
		perror("No map");
	free(tab);
	tab = NULL;
//	system("leaks");
	return (0);*/
}


