/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 03:29:36 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/26 05:18:16 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static void	get_tex_ptr(t_config *config, t_tex *tex)
{
	char	*path;

	path = (char *)tex->img;
	tex->img = mlx_xpm_file_to_image(config->mlx, path, &tex->width, &tex->height);
	tex->addr = (int *)mlx_get_data_addr(tex->img, &tex->bpp, &tex->ls, &tex->en);
	free(path);
}

static void	adjust_screen_size(t_config *config)
{
	int	width;
	int	height;

	mlx_get_screen_size(config->mlx, &width, &height);
	if (config->screen.x > width)
		config->screen.x = width;
	if (config->screen.y > height)
		config->screen.y = height;
}

void	init_config(t_config *config)
{
	ft_memset(config, 0, sizeof(t_config));
}

static void	set_zbuff_len(t_config *config)
{
	config->zbuff = malloc(sizeof(double) * config->screen.x);
	if (config->zbuff == NULL)
		error_exit();
}

void	init_ptr(t_config *config)
{
	config->mlx = mlx_init();
	adjust_screen_size(config);
	config->win = mlx_new_window(config->mlx, config->screen.x, config->screen.y, "cub3D");
	config->img = mlx_new_image(config->mlx, config->screen.x, config->screen.y);
	config->img_addr = (int *)mlx_get_data_addr(config->img, &config->bpp, &config->ls, &config->en);
	get_tex_ptr(config, &config->no);
	get_tex_ptr(config, &config->we);
	get_tex_ptr(config, &config->ea);
	get_tex_ptr(config, &config->so);
	get_tex_ptr(config, &config->sp);
	set_zbuff_len(config);
}
