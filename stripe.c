/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stripe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:55:41 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/23 04:02:34 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

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
			if (ray->dir_x < 0)
				ray->side = 2;
		}
		else
		{
			ray->sd_y += ray->dd_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
			if (ray->dir_y < 0)
				ray->side = 3;
		}
		if (g_worldMap[ray->map_x][ray->map_y] == 1)
			ray->hit = 1;
	}
}

static void	get_stripe_dist(t_stripe *stripe, t_ray *ray, t_data *param)
{
	if (ray->side == 0 || ray->side == 2)
		ray->pwd \
		 = (ray->map_x - param->x_pos + (1 - ray->step_x) / 2) / ray->dir_x;
	else
		ray->pwd \
		 = (ray->map_y - param->y_pos + (1 - ray->step_y) / 2) / ray->dir_y;
	stripe->height = (int)(SC_H / ray->pwd);
	stripe->start = -stripe->height / 2 + SC_H / 2;
	stripe->end = stripe->height / 2 + SC_H / 2;
	if (stripe->start < 0)
		stripe->start = 0;
	if (stripe->end >= SC_H)
		stripe->end = SC_H - 1;
}

static void	get_tx_ty(t_ray *ray, t_data *param, t_tex *aspect, t_stripe stripe)
{
	if (ray->side == 0 || ray->side == 2)
		aspect->wall_x = param->y_pos + ray->pwd * ray->dir_y;
	else
		aspect->wall_x = param->x_pos + ray->pwd * ray->dir_x;
	aspect->wall_x -= floor(aspect->wall_x);
	aspect->cord_tx = (int)(aspect->wall_x * (double)(aspect->t_width));
	if (ray->side == 0 && ray->dir_x > 0)
		aspect->cord_tx = aspect->t_width - aspect->cord_tx - 1;
	if (ray->side == 1 && ray->dir_y < 0)
		aspect->cord_tx = aspect->t_width - aspect->cord_tx - 1;
	aspect->step = 1.0 * aspect->t_height / stripe.height;
	aspect->pos_t \
	 = (stripe.start - SC_H / 2 + stripe.height / 2) * aspect->step;
}

static void	set_color(int x, t_data *param, t_tex *tex, t_stripe stripe)
{
	int	y;

	y = -1;
	while (++y < SC_H)
	{
		if (y >= stripe.start && y <= stripe.end)
		{
			tex->cord_ty = (int)tex->pos_t & (tex->t_height - 1);
			tex->pos_t += tex->step;
			param->data[y * SC_W + x] \
			 = tex->data[tex->t_width * tex->cord_ty + tex->cord_tx];
		}
	}
}

void	stripe(int x, t_ray *ray, t_data *param)
{
	t_stripe	stripe;
	t_tex		*tex;

	cast_ray(ray);
	get_stripe_dist(&stripe, ray, param);
	if (ray->side == 0)
		tex = &param->nr;
	else if (ray->side == 1)
		tex = &param->st;
	else if (ray->side == 2)
		tex = &param->ea;
	else
		tex = &param->we;
	get_tx_ty(ray, param, tex, stripe);
	set_color(x, param, tex, stripe);
}
