/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 23:38:22 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/22 00:04:00 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
