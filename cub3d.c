/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by agarzon-          #+#    #+#             */
/*   Updated: 2020/02/03 17:24:37 by agarzon-         ###   ########.fr       */
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

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

void my_mlx_put_pixel(t_data *image, int x, int y, int color)
{
	char *dst;
	
	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
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
	t_data data;
	
	posX = 22;
	posY = 22;
	dirX = -1;
	dirY = 0;
	planeX = 0;
	planeY = 0.66;
	time = 0;
	oldtime = 0;
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
		
		x++;
	}
		data.img = mlx_new_image(ptr, screenWidth, screenHeight);
		data.addr = mlx_get_data_addr(ptr, &data.bits_per_pixel, &data.line_length, &data.endian);
		my_mlx_put_pixel(&data, drawStart, drawEnd, RGB_BLUE);
		mlx_put_image_to_window(ptr, window, data.img, 0, 0);
      /*	switch(worldMap[mapX][mapY])
      	{
        	case 1:  color = RGB_RED;  break; //red
        	case 2:  color = RGB_GREEN;  break; //green
        	case 3:  color = RGB_BLUE;   break; //blue
        	case 4:  color = RGB_WHITE;  break; //white
        	default: color = RGB_YELLOW; break; //yellow
      	}
      	if (side == 1)
			color = color / 2;*/
//	mlx_key_hook(window, deal_key, tab);
	mlx_loop(ptr);
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


