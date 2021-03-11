/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:55:41 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/11 17:10:04 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
