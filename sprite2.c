/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 01:17:27 by jinbekim          #+#    #+#             */
/*   Updated: 2021/04/01 02:30:53 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	draw_sprite(t_config *conf, t_sprite *sprite)
{
	int	i;
	int	j;
	int	y;

	i = -1;
	while (++i < conf->sprite_num)
	{
		y = sprite->draw_x.start - 1;
		while (++y < sprite->draw_x.end)
		{
			sprite[i].texx = (int)((y - (-sprite[i].draw_x.len \
			 / 2 + sprite[i].screenx)) * conf->sp.width / sprite[i].draw_x.len);
			j = sprite->draw_y.start - 1;
			if (sprite[i].trans_pos.y > 0 && y > 0 && y < conf->screen.x && sprite[i].trans_pos.y < conf->zbuff[y])
				while (++j < sprite->draw_y.end)
				{
					sprite[i].texy = (int)((j - 0.5 * conf->screen.y + 0.5 * sprite[i].draw_y.len) * conf->sp.height / sprite[i].draw_y.len);
					if ((conf->sp.addr[sprite[i].texy * conf->sp.width + sprite[i].texx] & 0xffffff) != 0)
						conf->img_addr[j * conf->screen.x + y] = conf->sp.addr[sprite[i].texy * conf->sp.width + sprite[i].texx];
				}
		}
	}
}
