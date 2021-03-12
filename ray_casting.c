/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:52:03 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/12 18:22:52 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static double	ft_abs(double x)
{
	if (x > 0)
		return (x);
	return (-x);
}

static void		basic_setter(t_ray *ray, t_data *param, int x)
{
	ray->camera_x = 2 * x / (double)screenWidth - 1;
	ray->dir_x = param->x_dir + param->x_plane * ray->camera_x;
	ray->dir_y = param->y_dir + param->y_plane * ray->camera_x;
	ray->delta_dist_x = ft_abs(1 / ray->dir_x);
	ray->delta_dist_y = ft_abs(1 / ray->dir_y);
	ray->map_x = (int)param->x_pos;
	ray->map_y = (int)param->y_pos;
}
void			side_dist(char axis, int step, t_ray *ray)
{
	if (step == -1 )
}

void			ray_casting(t_data *param)
{
	int		x;
	t_ray	ray;

	x = -1;
	while (++x < screenWidth)
	{
		basic_setter(&ray, param, x);
		if (ray.dir_x < 0)
		{
			ray.step_x = -1;
			ray.side_dist_x = (param->x_pos - ray.map_x) * ray.delta_dist_x;
		}
		else
		{
			ray.step_x = 1;
			ray.side_dist_x = (ray.map_x + 1.0 - param->x_pos) * ray.delta_dist_x;
		}
		if (ray.dir_y < 0)
		{
			ray.step_y = -1;
			ray.side_dist_y = (param->y_pos - ray.map_y) * ray.delta_dist_y;
		}
		else
		{
			ray.step_y = 1;
			ray.side_dist_y = (ray.map_y + 1.0 - param->y_pos) * ray.delta_dist_y;
		}
	}
}
