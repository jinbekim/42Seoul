/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:39:57 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/11 17:01:00 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	ft_abs(double x)
{
	if (x > 0)
		return (x);
	return (-x);
}

int main_loop(t_data *param)
{
	ray_casting(param);
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
	return (0);
}

int main(int argc, char *argv[])
{
	t_data data;

	// from .cub file
	data.x_pos = 22;
	data.y_pos = 15;
	data.x_dir = -1;
	data.y_dir = 0;
	data.x_plane = 0;
	data.y_plane = 0.66;

	// start
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, screenWidth, screenHeight, "Raycasting");
	data.img = mlx_new_image(data.mlx, screenWidth, screenHeight);
	data.data = (int *)mlx_get_data_addr(data.img, &data.bpp, &data.ls, &data.en);
	// data.nr.ptr = mlx_xpm_file_to_image(data.mlx, "./textures/wood.xpm", &data.nr.t_width, &data.nr.t_height);
	// data.nr.data = (int *)mlx_get_data_addr(data.nr.ptr, &data.nr.bpp, &data.nr.ls, &data.nr.en);

	// mlx_hook(data.win, 6, 0, &mouse_move, &data);
	mlx_loop_hook(data.mlx, &main_loop, &data);
	mlx_hook(data.win, 2, 0, &key_control, &data);
	mlx_hook(data.win, 17, 0, &close, 0);
	mlx_loop(data.mlx);
}
