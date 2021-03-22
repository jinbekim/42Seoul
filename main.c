/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:39:57 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/22 00:08:35 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int g_worldMap[MAP_W][MAP_H] =
{
  {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
  {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,0,7,7,7,7,7},
  {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,7,7,7,1},
  {4,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,8},
  {4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
  {4,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,8},
  {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,7,7,7,1},
  {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,7,7,7,7,1},
  {6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
  {6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
  {4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
};

int	main_loop(t_data *param)
{
	floor_ceil(param);
	wall(param);
	sprite(param);
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
	data.win = mlx_new_window(data.mlx, SC_W, SC_H, "Raycasting");
	data.img = mlx_new_image(data.mlx, SC_W, SC_H);

	data.data = (int *)mlx_get_data_addr(data.img, &data.bpp, &data.ls, &data.en);
	data.nr.ptr = mlx_xpm_file_to_image(data.mlx, "./textures/wood.xpm", &data.nr.t_width, &data.nr.t_height);
	data.nr.data = (int *)mlx_get_data_addr(data.nr.ptr, &data.nr.bpp, &data.nr.ls, &data.nr.en);
	data.st.ptr = mlx_xpm_file_to_image(data.mlx, "./textures/greystone.xpm", &data.st.t_width, &data.st.t_height);
	data.st.data = (int *)mlx_get_data_addr(data.st.ptr, &data.st.bpp, &data.st.ls, &data.st.en);
	data.we.ptr = mlx_xpm_file_to_image(data.mlx, "./textures/purplestone.xpm", &data.we.t_width, &data.we.t_height);
	data.we.data = (int *)mlx_get_data_addr(data.we.ptr, &data.we.bpp, &data.we.ls, &data.we.en);
	data.ea.ptr = mlx_xpm_file_to_image(data.mlx, "./textures/redbrick.xpm", &data.ea.t_width, &data.ea.t_height);
	data.ea.data = (int *)mlx_get_data_addr(data.ea.ptr, &data.ea.bpp, &data.ea.ls, &data.ea.en);

	mlx_loop_hook(data.mlx, &main_loop, &data);
	mlx_hook(data.win, 6, 0, &mouse_move, &data);
	mlx_hook(data.win, 2, 0, &key_control, &data);
	mlx_hook(data.win, 17, 0, &close, 0);
	mlx_loop(data.mlx);
}
