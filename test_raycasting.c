/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/10 14:45:32 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480
#define GREY 808080
#define RGB_RED 0xFF0000
#define RGB_GREEN 0x008000
#define RGB_BLUE 0x0000FF
#define RGB_WHITE 0xFFFFFF
#define RGB_YELLOW 0xFFFF00

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int		main(int argc, char **argv)
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double time;
	double oldtime;
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
	double frameTime;
	double moveSpeed;
	double rotSpeed;
	int color;
	void *ptr;
	void *window;
//	t_data data;
	
	posX = 22;
	posY = 3;
	dirX = -1;
	dirY = 0;
	planeX = 0;
	planeY = 0.66;
	time = 0;
	oldtime = 0;
	hit = 0;
	rayDirX = 0;
	rayDirY = 0;
	deltaDistX = 0;
	deltaDistY = 0;
	t_mlx	*img;
	t_color	*color2;

	img = (t_mlx *)malloc(sizeof(t_mlx));
	color2 = (t_color *)malloc(sizeof(t_color));
	img->mlx_ptr = mlx_init();
    img->window = mlx_new_window(img->mlx_ptr, screenWidth, screenHeight, "cub3D");
	while(x < screenWidth)
	{
		cameraX = 2 * x / screenWidth -1;
		rayDirX = dirX + planeX * cameraX;
		rayDirY = dirY + planeY * cameraX;
		printf("CAMERA: %f\n", cameraX);
		printf("RAYDIRX: %d\n", rayDirX);
		printf("RAYDIRY: %d\n", rayDirY);
		mapX = (int)posX;
		mapY = (int)posY;
		printf("MAPX: %d\n", mapX);
		printf("MAPY: %d\n", mapY);
		deltaDistX = fabs(1 / raydirX);
		deltaDistY = fabs(1 / raydirY);
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
        	sideDistY = (mapY + 1.0 - posY) * deltaDistY;
			printf("sideDisY: %f\n", sideDistY);
     	 }
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
        	if (worldMap[mapX][mapY] > 0)
				hit = 1;
      	}
		printf("HIT: %d\n", hit);
		if (side == 0)
			perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
      	else
		  	perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;
		printf("WALL: %f\n", perpWallDist);
		lineHeight = (int)(screenHeight / perpWallDist);
		printf("LINEHEIGHT: %d\n", lineHeight);
      	drawStart = lineHeight / 2 + screenHeight / 2;
		printf("DRAWSTART: %d\n", drawStart);
     	if(drawStart < 0)
			drawStart = 0;
      	drawEnd = lineHeight / 2 + screenHeight / 2;
      	if(drawEnd >= screenHeight)
			drawEnd = screenHeight - 1;
		printf("DRAWSTART: %d\n", drawStart);
		printf("DRAWEND: %d\n", drawEnd);
		x++;
		printf("X = %d\n", x);
		printf("\n");
	}
	img->img = mlx_new_image(img->mlx_ptr, 520, 360);
    img->img_data = mlx_get_data_addr(img->img, &img->bpp, &img->size_l,
                                 &img->endian);
	color2->colorR = create_trgb(0, 255, 0, 0);
	color2->colorG = create_trgb(0, 0, 255, 0);
	color2->colorB = create_trgb(0, 0, 0, 255);
	color2->colorT = create_trgb(255, 0, 0, 0);
	paint(img, color2->colorR, drawEnd, drawStart);
	mlx_put_image_to_window(img->mlx_ptr, img->window, img->img, drawEnd, drawStart);
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


