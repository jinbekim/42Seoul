/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:39:57 by jinbekim          #+#    #+#             */
/*   Updated: 2021/04/02 17:01:00 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	main_loop(t_config *config)
{
	floor_ceil(config);
	wall(config);
	sprite(config);
	mlx_sync(MLX_SYNC_IMAGE_WRITABLE, config->img);
	mlx_put_image_to_window(config->mlx, config->win, config->img, 0, 0);
	mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, config->win);
	return (0);
}

static void	start_loop(t_config *config)
{
	mlx_loop_hook(config->mlx, &main_loop, config);
	mlx_hook(config->win, KEY_PRESS, 0, &key_control, config);
	mlx_hook(config->win, MOUSE_MOTION, 0, &mouse_move, config);
	mlx_hook(config->win, RED_CROSS, 0, &game_close, 0);
	mlx_loop(config->mlx);
}

int	main(int ac, char *av[])
{
	t_config	config;

	ft_memset(&config, 0, sizeof(t_config));
	if (ac > 4 || ac < 2)
		error_exit();
	if (parse_config(av[1], &config) == -1)
		error_exit();
	init_ptr(&config);
	if (av[2] && ft_strncmp(av[2], "--save", 10) == 0)
		screenshot(&config);
	start_loop(&config);
	return (0);
}
