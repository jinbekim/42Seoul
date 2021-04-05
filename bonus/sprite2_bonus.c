/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 01:17:27 by jinbekim          #+#    #+#             */
/*   Updated: 2021/04/05 17:59:09 by jinbekim         ###   ########.fr       */
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
		(int)((y - conf->middle_line + 0.5 * sprite[i].draw_y.len) \
		 * conf->sp.height / sprite[i].draw_y.len);
		if ((conf->sp.addr[sprite[i].texy * conf->sp.width + sprite[i].texx] \
		 & 0xffffff) != 0)
		{
			conf->img_addr[y * conf->ls / 4 + x] = \
			 conf->sp.addr[sprite[i].texy * conf->sp.width + sprite[i].texx];
		}
	}
}

static int	get_color(int color, int x, t_config *conf)
{
	int	r;
	int	g;
	int b;


}

static void	draw_line2(int i, int x, t_config *conf, t_sprite *sprite)
{
	int	y;

	y = sprite[i].draw_y.start - 1;
	while (++y < sprite[i].draw_y.end)
	{
		sprite[i].texy = \
		(int)((y - conf->middle_line + 0.5 * sprite[i].draw_y.len) \
		 * conf->sp2.height / sprite[i].draw_y.len);
		if ((conf->sp2.addr[sprite[i].texy * conf->sp.width + sprite[i].texx] \
		 & 0xffffff) != 0)
		{
			conf->img_addr[y * conf->ls / 4 + x] = \
			 get_color(conf->sp2.addr[sprite[i].texy * conf->sp.width + \
			 sprite[i].texx], x, conf);
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
		 && sprite[i].trans_pos.y < conf->zbuff[x] && sprite[i].num_tex == 2)
			draw_line(i, x, conf, sprite);
		else if (sprite[i].trans_pos.y > 0 && x > 0 && x < conf->screen.x \
		 && sprite[i].trans_pos.y < conf->zbuff[x] && sprite[i].num_tex == 3)
			draw_line2(i, x, conf, sprite);
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
