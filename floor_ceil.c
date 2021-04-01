/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 23:38:22 by jinbekim          #+#    #+#             */
/*   Updated: 2021/04/02 00:24:54 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

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
			if (y < (config->screen.y / 2))
				config->img_addr[y * config->screen.x + x] = \
				 config->ceil_color;
			else
				config->img_addr[y * config->screen.x + x] = \
				 config->floor_color;
		}
	}
}
