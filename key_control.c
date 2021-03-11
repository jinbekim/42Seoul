/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:13:58 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/11 17:09:47 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		key_control(int key, t_data *param)
{
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
