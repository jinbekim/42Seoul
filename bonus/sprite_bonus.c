/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 23:47:06 by jinbekim          #+#    #+#             */
/*   Updated: 2021/04/04 13:47:37 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
		distx = sprite[i].x - conf->pos.x;
		disty = sprite[i].y - conf->pos.y;
		sprite[i].dist = pow(distx, 2) + pow(disty, 2);
		sprite[i].re_pos.x = distx;
		sprite[i].re_pos.y = disty;
		sprite[i].trans_pos.x = \
		 invdet * (conf->dir.y * distx - conf->dir.x * disty);
		sprite[i].trans_pos.y = \
		 invdet * (-conf->plane.y * distx + conf->plane.x * disty);
		sprite[i].screenx = (int)((conf->screen.x / 2) \
		 * (1 + sprite[i].trans_pos.x / sprite[i].trans_pos.y));
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

static void	get_start_end(t_config *conf, t_sprite *sp)
{
	int	i;

	i = -1;
	while (++i < conf->sprite_num)
	{
		sp[i].draw_y.len = abs((int)(conf->screen.y / sp[i].trans_pos.y));
		sp[i].draw_y.start = -sp[i].draw_y.len / 2 + conf->middle_line;
		sp[i].draw_y.end = sp[i].draw_y.len / 2 + conf->middle_line;
		if (sp[i].draw_y.start < 0)
			sp[i].draw_y.start = 0;
		if (sp[i].draw_y.end >= conf->screen.y)
			sp[i].draw_y.end = conf->screen.y - 1;
		sp[i].draw_x.len = abs((int)(conf->screen.y / sp[i].trans_pos.y));
		sp[i].draw_x.start = -sp[i].draw_x.len / 2 + sp[i].screenx;
		sp[i].draw_x.end = sp[i].draw_x.len / 2 + sp[i].screenx;
		if (sp[i].draw_x.start < 0)
			sp[i].draw_x.start = 0;
		if (sp[i].draw_x.end >= conf->screen.x)
			sp[i].draw_x.end = conf->screen.x - 1;
	}
}

void	sprite(t_config *config)
{
	get_sprite_d(config, config->arr);
	sort_sprite(config, config->arr);
	get_start_end(config, config->arr);
	draw_sprite(config, config->arr);
}
