/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ptr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 03:29:36 by jinbekim          #+#    #+#             */
/*   Updated: 2021/04/05 16:24:11 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_tex_ptr(t_config *config, t_tex *tex)
{
	char	*path;

	path = (char *)tex->img;
	tex->img = \
	 mlx_xpm_file_to_image(config->mlx, path, &tex->width, &tex->height);
	if (tex->img == NULL)
		error_exit();
	tex->addr = \
	 (int *)mlx_get_data_addr(tex->img, &tex->bpp, &tex->ls, &tex->en);
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

static void	set_zbuff_len(t_config *config)
{
	config->zbuff = malloc(sizeof(double) * config->screen.x);
	if (config->zbuff == NULL)
		error_exit();
}

static t_sprite	*make_sprite_arr(t_config *config)
{
	int			i;
	t_sprite	*arr;
	t_list		*tmp;
	t_list		*tmp2;

	i = -1;
	tmp = config->head;
	arr = malloc(sizeof(t_sprite) * config->sprite_num);
	if (arr == NULL)
		error_exit();
	while (++i < config->sprite_num)
	{
		arr[i].x = ((t_sprite *)tmp->content)->x;
		arr[i].y = ((t_sprite *)tmp->content)->y;
		arr[i].num_tex = ((t_sprite *)tmp->content)->num_tex;
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2->content);
		free(tmp2);
	}
	config->head = NULL;
	return (arr);
}

void	init_ptr(t_config *conf)
{
	conf->sp2.img = ft_strdup("./textures/greenlight.xpm");
	conf->mlx = mlx_init();
	adjust_screen_size(conf);
	conf->win = \
	mlx_new_window(conf->mlx, conf->screen.x, conf->screen.y, "cub3D");
	conf->img = mlx_new_image(conf->mlx, conf->screen.x, conf->screen.y);
	conf->img_addr = \
	(int *)mlx_get_data_addr(conf->img, &conf->bpp, &conf->ls, &conf->en);
	get_tex_ptr(conf, &conf->no);
	get_tex_ptr(conf, &conf->we);
	get_tex_ptr(conf, &conf->ea);
	get_tex_ptr(conf, &conf->so);
	get_tex_ptr(conf, &conf->sp);
	get_tex_ptr(conf, &conf->sp2);
	set_zbuff_len(conf);
	conf->arr = make_sprite_arr(conf);
	conf->middle_line = conf->screen.y / 2;
	conf->mvs = 0.2;
}
