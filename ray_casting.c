/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:52:03 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/17 16:43:22 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static double	ft_abs(double x)
{
	if (x > 0)
		return (x);
	return (-x);
}

static void	basic_setter(t_ray *ray, t_data *param, int x)
{
	ray->camera_x = 2 * x / (double)SC_W - 1;
	ray->dir_x = param->x_dir + param->x_plane * ray->camera_x;
	ray->dir_y = param->y_dir + param->y_plane * ray->camera_x;
	ray->dd_x = ft_abs(1 / ray->dir_x);
	ray->dd_y = ft_abs(1 / ray->dir_y);
	ray->map_x = (int)param->x_pos;
	ray->map_y = (int)param->y_pos;
}

static void	set_step_and_sd(t_ray *ray, t_data *param)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sd_x = (param->x_pos - ray->map_x) * ray->dd_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sd_x = (ray->map_x + 1.0 - param->x_pos) * ray->dd_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sd_y = (param->y_pos - ray->map_y) * ray->dd_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sd_y = (ray->map_y + 1.0 - param->y_pos) * ray->dd_y;
	}
}

void	ray_casting(t_data *param)
{
	int		x;
	t_ray	ray;

	x = -1;
	while (++x < SC_W)
	{
		basic_setter(&ray, param, x);
		set_step_and_sd(&ray, param);
		texture(x, &ray, param);
	}
}
