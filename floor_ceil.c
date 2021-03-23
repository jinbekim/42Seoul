/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 23:38:22 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/23 04:02:05 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	floor_ceil(t_data *param)
{
	int	x;
	int	y;

	x = -1;
	while (++x < SC_W)
	{
		y = -1;
		while (++y < SC_H)
		{
			if (y < (SC_H / 2))
				param->data[y * SC_W + x] = 0x00ff00;
			else
				param->data[y * SC_W + x] = 0x0000ff;
		}
	}
}
