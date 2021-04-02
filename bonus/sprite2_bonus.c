/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 01:17:27 by jinbekim          #+#    #+#             */
/*   Updated: 2021/04/02 17:01:29 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	draw_line(int i, int x, t_config *conf, t_sprite *sprite)
{
	int	y;

	y = sprite[i].draw_y.start - 1;
	while (++y < sprite[i].draw_y.end)
	{
		sprite[i].texy = \
		(int)((y - 0.5 * conf->screen.y + 0.5 * sprite[i].draw_y.len) \
		 * conf->sp.height / sprite[i].draw_y.len);
		if ((conf->sp.addr[sprite[i].texy * conf->sp.width + sprite[i].texx] \
		 & 0xffffff) != 0)
		{
			conf->img_addr[y * conf->ls / 4 + x] = \
			 conf->sp.addr[sprite[i].texy * conf->sp.width + sprite[i].texx];
		}
	}
}

static void	draw_i_sprite(int i, t_config *conf, t_sprite *sprite)
{
	int	x;

	x = sprite[i].draw_x.start - 1;
	while (++x < sprite[i].draw_x.end)
	{
		sprite[i].texx = (int)((x - (-sprite[i].draw_x.len \
		 / 2 + sprite[i].screenx)) * conf->sp.width / sprite[i].draw_x.len);
		if (sprite[i].trans_pos.y > 0 && x > 0 && x < conf->screen.x \
		 && sprite[i].trans_pos.y < conf->zbuff[x])
			draw_line(i, x, conf, sprite);
	}
}

void	draw_sprite(t_config *conf, t_sprite *sprite)
{
	int	i;

	i = -1;
	while (++i < conf->sprite_num)
	{
		draw_i_sprite(i, conf, sprite);
	}
}
