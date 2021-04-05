/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:55:41 by jinbekim          #+#    #+#             */
/*   Updated: 2021/04/04 15:52:31 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	cal_hit_map(t_ray *ray, t_config *config)
{
	while (ray->hit == 0)
	{
		if (ray->side_d.x < ray->side_d.y)
		{
			ray->side_d.x += ray->delta_d.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
			if (ray->dir.x < 0)
				ray->side = 2;
		}
		else
		{
			ray->side_d.y += ray->delta_d.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
			if (ray->dir.y < 0)
				ray->side = 3;
		}
		if (config->cub[ray->map.x][ray->map.y] == '1')
			ray->hit = 1;
	}
}

static void	cal_wall_height(t_stripe *stripe, t_ray *ray, t_config *config)
{
	if (ray->side == 0 || ray->side == 2)
		ray->perp_wd \
		 = (ray->map.x - config->pos.x + (1 - ray->step.x) / 2) / ray->dir.x;
	else
		ray->perp_wd \
		 = (ray->map.y - config->pos.y + (1 - ray->step.y) / 2) / ray->dir.y;
	stripe->len = (int)(config->screen.y / ray->perp_wd);
	stripe->start = -stripe->len / 2 + config->middle_line;
	stripe->end = stripe->len / 2 + config->middle_line;
	if (stripe->start < 0)
		stripe->start = 0;
	if (stripe->end >= config->screen.y)
		stripe->end = config->screen.y - 1;
}

static void
	set_tex_conf(t_ray *ray, t_config *config, t_tex *tex, t_stripe stripe)
{
	if (ray->side == 0 || ray->side == 2)
		tex->wall_x = config->pos.y + ray->perp_wd * ray->dir.y;
	else
		tex->wall_x = config->pos.x + ray->perp_wd * ray->dir.x;
	tex->wall_x -= floor(tex->wall_x);
	tex->cord.x = (int)(tex->wall_x * (double)(tex->width));
	if (ray->side == 0 && ray->dir.x > 0)
		tex->cord.x = tex->width - tex->cord.x - 1;
	if (ray->side == 1 && ray->dir.y < 0)
		tex->cord.x = tex->width - tex->cord.x - 1;
	tex->step = 1.0 * tex->height / stripe.len;
	tex->pos_t \
	 = (stripe.start - config->middle_line + stripe.len / 2) * tex->step;
}

static void	put_on_tex(int x, t_config *config, t_tex *tex, t_stripe stripe)
{
	int	y;

	y = -1;
	while (++y < config->screen.y)
	{
		if (y >= stripe.start && y <= stripe.end)
		{
			tex->cord.y = (int)tex->pos_t & (tex->height - 1);
			tex->pos_t += tex->step;
			config->img_addr[y * config->ls / 4 + x] \
			 = tex->addr[tex->width * tex->cord.y + tex->cord.x];
		}
	}
}

void	ray_cast(int x, t_ray *ray, t_config *config)
{
	t_stripe	stripe;
	t_tex		*tex;

	cal_hit_map(ray, config);
	cal_wall_height(&stripe, ray, config);
	if (ray->side == 0)
		tex = &config->no;
	else if (ray->side == 1)
		tex = &config->so;
	else if (ray->side == 2)
		tex = &config->ea;
	else
		tex = &config->we;
	set_tex_conf(ray, config, tex, stripe);
	put_on_tex(x, config, tex, stripe);
	config->zbuff[x] = ray->perp_wd;
}
