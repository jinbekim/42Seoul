/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:39:57 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/23 20:59:08 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

// int	main_loop(t_camera *parsed)
// {
// 	floor_ceil(parsed);
// 	wall(parsed);
// 	sprite(parsed);
// 	mlx_put_image_to_window(parsed->mlx, parsed->win, parsed->img, 0, 0);
// 	return (0);
// }

// static void	init(t_camera *parsed)
// {
// 	parsed->mlx = mlx_init();
// 	parsed->win = mlx_new_window(parsed->mlx, parsed->screen.x, parsed->screen.y, "cub3d");
// 	parsed->img = mlx_new_image(parsed->mlx, parsed->screen.x, parsed->screen.y);
// 	parsed->img_addr = (int *)mlx_get_data_addr(parsed->img, &parsed->bpp, &parsed->ls, &parsed->en);
// 	mlx_loop_hook(parsed->mlx, &main_loop, parsed);
// 	mlx_hook(parsed->win, KEY_PRESS, 0, &key_control, parsed);
// 	mlx_hook(parsed->win, MOUSE_MOTION, 0, &mouse_move, parsed);
// 	mlx_hook(parsed->win, RED_CROSS, 0, &game_close, 0);
// 	mlx_loop(parsed->mlx);
// }

int	main(int argc, char *argv[])
{
	t_camera	parsed;

	// if (argc > 3)
	// {
	// 	perror("Error\n");
	// 	return (0);
	// }
	parsing(argv[1], &parsed);
	// init(&parsed);
	return (0);
}
