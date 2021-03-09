/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:39:57 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/09 17:19:45 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double posX = 22, posY = 15;  //x and y start position
double dirX = -1, dirY = 0; //initial direction vector
double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane
double moveSpeed = 0.3;
double rotSpeed = 0.08;


double	ft_abs(double x)
{
	if (x > 0)
		return (x);
	return (-x);
}

void	draw_ver_line(int x, int drawStart, int drawEnd, int color, int **data)
{
	int i = 0;
	while (i < 480){
		// in order, wall, ceil, floor
		if (i >= drawStart && i <=drawEnd){
			(*data)[i * 640 + x] = color;
		}
		else if (i < 240) {
			(*data)[i * 640 + x] = 0x0000aa;
		}
		else{
			(*data)[i * 640 + x] = 0x000000;
		}
		i++;
	}
}

int	key_code(int key, void *param){
	if (key == 53)
		exit(0);
	double sdirX, sdirY;
	sdirX = dirX * cos(1.571) - dirY * sin(1.571);
    sdirY = dirX * sin(1.571) + dirY * cos(1.571);

	if (key == key_w || key == arr_up)
	{
      if(g_worldMap[(int)(posX + dirX * moveSpeed)][(int)posY] == 0)
	  	posX += dirX * moveSpeed;
      if(g_worldMap[(int)posX][(int)(posY + dirY * moveSpeed)] == 0)
	  	posY += dirY * moveSpeed;
    }
	if (key == key_s || key == arr_down)
	{
      if(g_worldMap[(int)(posX - dirX * moveSpeed)][(int)posY] == 0)
	  	posX -= dirX * moveSpeed;
      if(g_worldMap[(int)posX][(int)(posY - dirY * moveSpeed)] == 0)
	  	posY -= dirY * moveSpeed;
    }
	if (key == key_a)
	{
		if(g_worldMap[(int)(posX + sdirX * moveSpeed)][(int)posY] == 0)
	  		posX += sdirX * moveSpeed;
      	if(g_worldMap[(int)posX][(int)(posY + sdirY * moveSpeed)] == 0)
	  		posY += sdirY * moveSpeed;
	}
	if (key == key_d)
	{
		if(g_worldMap[(int)(posX - sdirX * moveSpeed)][(int)posY] == 0)
	  		posX -= sdirX * moveSpeed;
      	if(g_worldMap[(int)posX][(int)(posY - sdirY * moveSpeed)] == 0)
	  		posY -= sdirY * moveSpeed;
	}
	if (key == arr_left)
	{
      //both camera direction and camera plane must be rotated
      double oldDirX = dirX;
      dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
      dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
      planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
    }
	if (key == arr_right)
	{
      //both camera direction and camera plane must be rotated
      double oldDirX = dirX;
      dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
      dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
      planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
    }
	return (0);
}



int main_loop(t_data *data)
{

	int x = -1;
	while (++x < screenWidth)
	{
		double cameraX = 2 * x / (double)screenWidth - 1;
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;

		int mapX = (int)posX;
		int mapY = (int)posY;

		double sideDistX;
		double sideDistY;

		double deltaDistX = ft_abs(1 / rayDirX);
		double deltaDistY = ft_abs(1 / rayDirY);
		double perpWallDist;

		int stepX;
		int stepY;

		int hit = 0;
		int side;

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
        	//jump to next map square, OR in x-direction, OR in y-direction
        	if (sideDistX < sideDistY)
        	{
        		sideDistX += deltaDistX;
        		mapX += stepX;
				if (rayDirX > 0)
        			side = 0; // east texture
				else
					side = 1;  //west
       		}
        	else
        	{
        		sideDistY += deltaDistY;
        		mapY += stepY;
				if (rayDirY > 0)
					side = 2; // north
				else
					side = 3;  // south
        	}
        	//Check if ray has hit a wall
        	if (g_worldMap[mapX][mapY] > 0) hit = 1;
		}

		if (side == 0 || side == 1)
			perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
    	else
			perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

      //Calculate height of line to draw on screen
      int lineHeight = (int)(screenHeight / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + screenHeight / 2;
      if(drawStart < 0)drawStart = 0;
      int drawEnd = lineHeight / 2 + screenHeight / 2;
      if(drawEnd >= screenHeight)drawEnd = screenHeight - 1;

	//choose wall color
      int color;
      if (side == 0) {color = 0xffffff;}
      if (side == 1) {color = 0xff0000;}
      if (side == 2) {color = 0x00ff00;}
      if (side == 3) {color = 0x0000ff;}

      //draw the pixels of the stripe as a vertical line
      draw_ver_line(x, drawStart, drawEnd, color, (int **)&data->data);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int deal_key(void *param)
{
	return (0);
}

int main(int argc, char *argv[])
{
	int bbp;
	int size_line;
	int endian;
	t_data data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, screenWidth, screenHeight, "Raycasting");
	data.img = mlx_new_image(data.mlx, screenWidth, screenHeight);
	data.data = mlx_get_data_addr(data.img, &bbp, &size_line, &endian);

	mlx_hook(data.win, 2, 0, &key_code, &data);
	// mlx_hook(win, 17, 0, &key_code, 0); when you push red x
	mlx_loop_hook(data.mlx, &main_loop, &data);
	mlx_loop(data.mlx);
}
