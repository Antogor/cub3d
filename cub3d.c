/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/03 14:22:36 by agarzon-         ###   ########.fr       */
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
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int		deal_key(int key, t_mlx *tab)
{
	if (key == ESC)
		exit(ESC);
	else if (key == W)
	{
		if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
      	if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
	}
	else if (key == S)
	{
		f(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
      	if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
	}
	else if (key == A)
	{
		double oldDirX = dirX;
      	dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
      	dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
      	double oldPlaneX = planeX;
      	planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
      	planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
	}
	else if (key == D)
	{
		double oldDirX = dirX;
      	dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
      	dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
      	double oldPlaneX = planeX;
      	planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
      	planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
	}
	
	return(0);
}

int		main(int argc, char **argv)
{
	double posX = 22;
	double posY = 22;
	double dirX = -1; //a donde mira el jugador
	double dirY = 0;
	double planeX = 0; //el ancho de la camara
	double planeY = 0.66;
	double time = 0; //frame actual
	double oldtime = 0; //el tiempo del frame anterior
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

	cameraX = 0;
	x = 0;
	raydirX = 0;
	raydirY = 0;
	mapX = 0;
	mapY = 0;
	sideDistX = 0;
	sideDistY = 0;
	perpWallDist = 0;
	stepX = 0;
	stepY = 0;
	hit = 0;
	side = 0;
	rayDirX = 0;
	rayDirY = 0;
	h = 0;
	ptr = mlx_init();
	window = mlx_new_window(ptr, screenWidth, screenHeight, "cub3d");
	while(x < screenWidth)
	{
		cameraX = 2 * x / (double)screenWidth -1;
		raydirX = dirX + planeX * cameraX;
		raydirY = dirY + planeY * cameraX;
		mapX = (int)posX;
		mapY = (int)posY;
		deltaDistX = fabs(1 / raydirX);
		deltaDistY = fabs(1 / raydirY);
		if (rayDirX < 0)
      	{
			  stepX = -1;
			  sideDistX = (posX - mapX) * deltaDistX;
      	}
      	else
     	{
        	stepX = 1;
        	sideDistX = (mapX + 1.0 - posX) * deltaDistX;
      	}
     	 if (rayDirY < 0)
      	{
        	stepY = -1;
        	sideDistY = (posY - mapY) * deltaDistY;
      	}
		else
     	 {
     		stepY = 1;
        	sideDistY = (mapY + 1.0 - posY) * deltaDistY;
     	 }
		while (hit == 0)
    	{
        	if (sideDistX < sideDistY)
        	{
          		sideDistX += deltaDistX;
          		mapX += stepX;
          		side = 0;
        	}
        	else
        	{
          		sideDistY += deltaDistY;
          		mapY += stepY;
          		side = 1;
        	}
        	if (worldMap[mapX][mapY] > 0)
				hit = 1;
      	}
		if (side == 0)
			perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
      	else
		  	perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;
		lineHeight = (int)(screenHeight / perpWallDist);
      	drawStart = -lineHeight / 2 + screenHeight / 2;
     	if(drawStart < 0)
			drawStart = 0;
      	drawEnd = lineHeight / 2 + screenHeight / 2;
      	if(drawEnd >= screenHeight)
			drawEnd = screenHeight - 1;
      	switch(worldMap[mapX][mapY])
      	{
        	case 1:  color = RGB_RED;  break; //red
        	case 2:  color = RGB_GREEN;  break; //green
        	case 3:  color = RGB_BLUE;   break; //blue
        	case 4:  color = RGB_WHITE;  break; //white
        	default: color = RGB_YELLOW; break; //yellow
      	}
      	//give x and y sides different brightness
      	if (side == 1)
			color = color / 2;
      	//draw the pixels of the stripe as a vertical line
	  	mlx_pixel_put(ptr, window, drawStart, drawEnd, color);
		x++;
	}
	mlx_key_hook(window, deal_key, (void*) 0);
	mlx_loop(ptr);
	/*
	t_cub3d	*tab;

	(void)argc;
	tab = (t_cub3d *)malloc(sizeof(t_cub3d *));
	tab->fd = open(argv[1], O_RDONLY);
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


