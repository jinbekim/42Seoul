/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:55:41 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/17 16:52:34 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	cast_ray(t_ray *ray)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->sd_x < ray->sd_y)
		{
			ray->sd_x += ray->dd_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sd_y += ray->dd_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (g_worldMap[ray->map_x][ray->map_y] > 0)
			ray->hit = 1;
	}
}

static void	get_perp_wall_dist(t_ray *ray, t_data *param)
{
	if (ray->side == 0)
		ray->pwd = (ray->map_x - param->x_pos \
		 + (1 - ray->step_x) / 2) / ray->dir_x;
	else
		ray->pwd = (ray->map_y - param->y_pos \
		 + (1 - ray->step_y) / 2) / ray->dir_y;
}

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

static void	draw_ver_line(int x, t_stripe stripe, t_data *param, t_ray *ray)
{
	int i;
	int color = 0x0000ee;
	if (ray->side == 1)
		color /= 2;

	i = 0;
	while (i < SC_H)
	{
		if (i > stripe.start && i < stripe.end)
			param->data[i * SC_W + x] = color;
		else
			param->data[i * SC_W + x] = 0x000000;
		i++;
	}
}


void	texture(int x, t_ray *ray, t_data *param)
{
	t_stripe	stripe;

	cast_ray(ray);
	get_perp_wall_dist(ray, param);
	get_line_height(&stripe, ray, param);
	draw_ver_line(x, stripe, param, ray);
}
