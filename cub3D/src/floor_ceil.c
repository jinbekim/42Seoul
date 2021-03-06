/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 23:38:22 by jinbekim          #+#    #+#             */
/*   Updated: 2021/04/05 22:55:36 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	floor_ceil(t_config *config)
{
	int	x;
	int	y;

	x = -1;
	while (++x < config->screen.x)
	{
		y = -1;
		while (++y < config->screen.y)
		{
			if (y < (config->middle_line))
				config->img_addr[y * config->ls / 4 + x] = \
			((int)((config->ceil_color & 0xff0000) * (config->middle_line - y) / config->middle_line + 0.1) & 0xff0000) + \
			((int)((config->ceil_color & 0xff00) * (config->middle_line - y) / config->middle_line + 0.1) & 0xff00) + \
			((int)((config->ceil_color & 0xff) * (config->middle_line - y) / config->middle_line + 0.1) & 0xff);
			else
				config->img_addr[y * config->ls / 4 + x] = \
			((int)((config->floor_color & 0xff0000) * (y - config->middle_line) / config->middle_line + 0.1) & 0xff0000) + \
			((int)((config->floor_color & 0xff00) * (y - config->middle_line) / config->middle_line + 0.1) & 0xff00) + \
			((int)((config->floor_color & 0xff) * (y - config->middle_line) / config->middle_line + 0.1) & 0xff);

		}
	}
}
