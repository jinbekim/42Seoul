/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:52:03 by jinbekim          #+#    #+#             */
/*   Updated: 2021/04/02 16:51:54 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_abs(double x)
{
	if (x > 0)
		return (x);
	return (-x);
}

static void	set_ray_conf(t_ray *ray, t_config *config, int x)
{
	ray->camera_x = 2 * x / (double)config->screen.x - 1;
	ray->dir.x = config->dir.x + config->plane.x * ray->camera_x;
	ray->dir.y = config->dir.y + config->plane.y * ray->camera_x;
	ray->delta_d.x = ft_abs(1 / ray->dir.x);
	ray->delta_d.y = ft_abs(1 / ray->dir.y);
	ray->map.x = (int)config->pos.x;
	ray->map.y = (int)config->pos.y;
	ray->hit = 0;
}

static void	set_ray_step_sd(t_ray *ray, t_config *config)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_d.x = (config->pos.x - ray->map.x) * ray->delta_d.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_d.x = (ray->map.x + 1.0 - config->pos.x) * ray->delta_d.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_d.y = (config->pos.y - ray->map.y) * ray->delta_d.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_d.y = (ray->map.y + 1.0 - config->pos.y) * ray->delta_d.y;
	}
}

void	wall(t_config *config)
{
	int		x;
	t_ray	ray;

	x = -1;
	while (++x < config->screen.x)
	{
		set_ray_conf(&ray, config, x);
		set_ray_step_sd(&ray, config);
		ray_cast(x, &ray, config);
	}
}
