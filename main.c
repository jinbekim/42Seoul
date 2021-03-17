/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:39:57 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/14 05:24:39 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main_loop(t_data *param)
{
	ray_casting(param);
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	data.x_pos = 22;
	data.y_pos = 15;
	data.x_dir = -1;
	data.y_dir = 0;
	data.x_plane = 0;
	data.y_plane = 0.66;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, SC_W, SC_H, "Raycasting");
	data.img = mlx_new_image(data.mlx, SC_W, SC_H);
	data.data = (int *)mlx_get_data_addr(data.img, &data.bpp, &data.ls, &data.en);
	// data.nr.ptr = mlx_xpm_file_to_image(data.mlx, "./textures/wood.xpm", &data.nr.t_width, &data.nr.t_height);
	// data.nr.data = (int *)mlx_get_data_addr(data.nr.ptr, &data.nr.bpp, &data.nr.ls, &data.nr.en);
	// mlx_hook(data.win, 6, 0, &mouse_move, &data);
	mlx_loop_hook(data.mlx, &main_loop, &data);
	mlx_hook(data.win, 2, 0, &key_control, &data);
	mlx_hook(data.win, 17, 0, &close, 0);
	mlx_loop(data.mlx);
}
