/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:52:03 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/11 17:10:01 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ray_casting(t_data *param)
{
	int		x;
	t_ray	ray;

	x = -1;
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
					side = 2; // south
				else
					side = 3;  // north
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
      int drawEnd = lineHeight / 2 + screenHeight / 2;
      if(drawStart < 0)
	  	drawStart = 0;
      if(drawEnd >= screenHeight)
	  	drawEnd = screenHeight - 1;
	}
}
