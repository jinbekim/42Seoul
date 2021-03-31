/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 23:47:06 by jinbekim          #+#    #+#             */
/*   Updated: 2021/04/01 02:30:18 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static void	get_sprite_d(t_config *conf, t_sprite *sprite)
{
	int		i;
	double	distx;
	double	disty;
	double	invdet;

	i = -1;
	invdet = 1.0 / (conf->plane.x * conf->dir.y - conf->dir.x * conf->plane.y);
	while (++i < conf->sprite_num)
	{
		distx = conf->pos.x - sprite[i].x;
		disty = conf->pos.y - sprite[i].y;
		sprite[i].dist = pow(distx, 2) + pow(disty, 2);
		sprite[i].re_pos.x = distx;
		sprite[i].re_pos.y = disty;
		sprite[i].trans_pos.x = \
		 invdet * (conf->dir.y * distx - conf->dir.x * disty);
		sprite[i].trans_pos.y = \
		 invdet * (-conf->plane.y * distx + conf->plane.y * disty);
	}
}

static void	sort_sprite(t_config *config, t_sprite *sprite)
{
	t_sprite	tmp;
	int			i;
	int			j;

	i = config->sprite_num;
	while (--i > 0)
	{
		j = -1;
		while (++j < i)
		{
			if (sprite[j].dist < sprite[j + 1]. dist)
			{
				tmp = sprite[j];
				sprite[j] = sprite[j + 1];
				sprite[j + 1] = tmp;
			}
		}
	}
}

static t_sprite	*make_sprite_arr(t_config *config)
{
	int			i;
	t_sprite	*arr;

	i = -1;
	arr = malloc(sizeof(t_sprite) * config->sprite_num);
	if (arr == NULL)
		error_exit();
	while (++i < config->sprite_num)
	{
		arr[i].x = ((t_sprite *)config->head->content)->x;
		arr[i].y = ((t_sprite *)config->head->content)->y;
	}
	return (arr);
}

static void	get_start_end(t_config *conf, t_sprite *sprite)
{
	int	i;
	int	screenx;

	i = -1;
	while (++i < conf->sprite_num)
	{
		sprite[i].screenx = (int)((conf->screen.x / 2) \
		 * (1 + sprite->trans_pos.x / sprite->trans_pos.y));
		sprite[i].draw_x.len = abs((int)(conf->screen.y / sprite->trans_pos.y));
		sprite[i].draw_x.start = -sprite[i].draw_x.len / 2 + sprite[i].screenx;
		sprite[i].draw_x.end = sprite[i].draw_x.len / 2 + sprite[i].screenx;
		if (sprite[i].draw_x.start < 0)
			sprite[i].draw_x.start = 0;
		if (sprite[i].draw_x.end >= conf->screen.x)
			sprite[i].draw_x.end = conf->screen.x - 1;
		sprite[i].draw_y.len = abs((int)(conf->screen.y / sprite->trans_pos.y));
		sprite[i].draw_y.start = -sprite[i].draw_y.len / 2 + conf->screen.y / 2;
		sprite[i].draw_y.end = sprite[i].draw_y.len / 2 + conf->screen.y / 2;
		if (sprite[i].draw_y.start < 0)
			sprite[i].draw_y.start = 0;
		if (sprite[i].draw_y.end >= conf->screen.y)
			sprite[i].draw_y.end = conf->screen.y - 1;
	}
}

void	sprite(t_config *config)
{
	t_sprite	*sprite;

	sprite = make_sprite_arr(config);
	get_sprite_d(config, sprite);
	sort_sprite(config, sprite);
	get_start_end(config, sprite);
	draw_sprite(config, sprite);
}
