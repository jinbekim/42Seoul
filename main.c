/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:39:57 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/25 06:37:43 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static int	is_cubfile(const char *path)
{
	int i;

	i = 0;
	while (path[i])
		i++;
    if (path[i - 4] == '.' && \
		path[i - 3] == 'c' && \
		path[i - 2] == 'u' && \
		path[i - 1] == 'b')
		return (1);
	return (0);
}

static void	init_config(t_config *config)
{
	ft_memset(config, 0, sizeof(t_config));
	config->mlx = mlx_init();
	config->win = mlx_new_window(config->mlx, config->screen.x, config->screen.y, "cub3D");
	config->img = mlx_new_image(config->mlx, config->screen.x, config->screen.y);
	config->img_addr = (int *)mlx_get_data_addr(config->img, &config->bpp, &config->ls, &config->en);
}

// static int	main_loop(t_config *config)
// {
// 	floor_ceil(config);
// 	wall(config);
// 	sprite(config);
// 	mlx_put_image_to_window(config->mlx, config->win, config->img, 0, 0);
// 	return (0);
// }

// static void	init(t_config *config)
// {
// 	mlx_loop_hook(config->mlx, &main_loop, config);
// 	mlx_hook(config->win, KEY_PRESS, 0, &key_control, config);
// 	mlx_hook(config->win, MOUSE_MOTION, 0, &mouse_move, config);
// 	mlx_hook(config->win, RED_CROSS, 0, &game_close, 0);
// 	mlx_loop(config->mlx);
// }

int	main(int ac, char *av[])
{
	t_config	config;
	t_sprite	tmp;

	init_config(&config);
	if (ac > 4 || ac < 2)
		error_exit();
	if (is_cubfile(av[1]) == -1)
		error_exit();
	if (parse_config(av[1], &config) == -1)
		error_exit();
	while (config.head)
	{
		printf("whiat\n");
		tmp = *(t_sprite *)config.head->content;
		printf("sprite x: %f, y: %f, order: %d\n", tmp.x, tmp.y, tmp.order);
		config.head = config.head->next;
	}
	printf("good work");
	exit(0);
	// init(&config);
	return (0);
}
