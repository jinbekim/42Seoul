/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:55:41 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/12 18:13:46 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

		double perpWallDist;
		int hit = 0;
		int side;

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
					side = 1; //west
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				if (rayDirY > 0)
					side = 2; // south
				else
					side = 3; // north
			}
			//Check if ray has hit a wall
			if (g_worldMap[mapX][mapY] > 0)
				hit = 1;
		}


		if (side == 0 || side == 1)
			perpWallDist = (mapX - param->x_pos + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - param->y_pos + (1 - stepY) / 2) / rayDirY;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(screenHeight / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + screenHeight / 2;
		int drawEnd = lineHeight / 2 + screenHeight / 2;
		if (drawStart < 0)
			drawStart = 0;
		if (drawEnd >= screenHeight)
			drawEnd = screenHeight - 1;

	double wallX; //where exactly the wall was hit
	if (side == 0)
		wallX = posY + perpWallDist * rayDirY;
    else
		wallX = posX + perpWallDist * rayDirX;
    wallX -= floor(wallX);

    //x coordinate on the texture
    // int texX = (int)(wallX * (double)tex.t_width);
    // if(side == 0 || side == 3)
	// 	texX = tex.t_width - texX - 1;


	// // How much to increase the texture coordinate per screen pixel
	// double step = 1.0 * tex.t_height / lineHeight;
    //   // Starting texture coordinate
    // double texPos = (drawStart - screenHeight / 2 + lineHeight / 2) * step;
    int color;
	// for(int y = drawStart; y<drawEnd; y++)
    // {
    //     // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
    //     int texY = (int)texPos & (tex.t_height - 1);
    //     texPos += step;
    //     param->data[y * screenHeight + x] = tex.data[tex.t_height * texY + texX];
    //     //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"

    // }

	// choose wall color
      if (side == 0) {color = 0xffffff;}
      if (side == 1) {color = 0xff0000;}
      if (side == 2) {color = 0x00ff00;}
      if (side == 3) {color = 0x0000ff;}

      //draw the pixels of the stripe as a vertical line
      draw_ver_line(x, drawStart, drawEnd, color, (int **)&param->data);
	}
