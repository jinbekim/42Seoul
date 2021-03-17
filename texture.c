/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:55:41 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/14 22:45:50 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	cast_ray(t_ray *ray, t_data *param)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->sd_x < ray->sd_y)
		{
			ray->sd_x += ray->dd_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
			if (ray->dir_x < 0)
				ray->side = 1;
		}
		else
		{
			ray->sd_y += ray->dd_y;
			ray->map_y += ray->step_y;
			ray->side = 2;
			if (ray->dir_y < 0)
				ray->side = 3;
		}
		if (g_worldMap[ray->map_x][ray->map_y] > 0)
			ray->hit = 1;
	}
}

static void	get_perp_wall_dist(t_ray *ray, t_data *param)
{
	if (ray->side == 0 || ray->side == 1)
		ray->pwd = (ray->map_x - param->x_pos \
		 + (1 - ray->step_x) / 2) / ray->dir_x;
	else
		ray->pwd = (ray->map_y - param->y_pos \
		 + (1 - ray->step_y) / 2) / ray->dir_y;
}

//Calculate height of line to draw on screen
//calculate lowest and highest pixel to fill in current stripe
static void	get_line_height(t_stripe *stripe, t_ray *ray, t_data *param)
{
	stripe->height = (int)(SC_H / ray->pwd);
	stripe->start = -stripe->height / 2 + SC_H / 2;
	stripe->end = stripe->height / 2 + SC_H / 2;
	if (stripe->start < 0)
		stripe->start = 0;
	if (stripe->end >= SC_H)
		stripe->end = SC_H - 1;
}

void	texture(t_ray *ray, t_data *param)
{
	t_stripe	stripe;

	cast_ray(ray, param);
	get_perp_wall_dist(&stripe, ray, param);

}

	double wallX; //where exactly the wall was hit
	if (ray->side == 0)
		wallX = posY + perpWallDist * ray->dir_y;
    else
		wallX = posX + perpWallDist * ray->dir_x;
    wallX -= floor(wallX);

	// choose wall color
      if (ray->side == 0) {color = 0xffffff;}
      if (ray->side == 1) {color = 0xff0000;}
      if (ray->side == 2) {color = 0x00ff00;}
      if (ray->side == 3) {color = 0x0000ff;}

      //draw the pixels of the stripe as a vertical line
      draw_ver_line(x, drawStart, drawEnd, color, (int **)&param->data);
	}
