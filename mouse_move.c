/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:11:43 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/25 23:15:19 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	mouse_move(int x, int y, t_config *config)
{
	static double s_rot;
	static int ex_x;
	double oldDirX = config->dir.x;
	double oldPlaneX = config->plane.x;

	if (ex_x > x)
	{
		s_rot = -1;
		ex_x = x;
	}
	else if (ex_x < x)
	{
		s_rot = 1;
		ex_x = x;
	}
	if (x > config->screen.x || x < 0 || y > config->screen.y || y < 0)
		s_rot = 0;
	config->dir.x = \
	 config->dir.x * cos(-RTSPD * s_rot) - config->dir.y * sin(-RTSPD * s_rot);
	config->dir.y = \
	 oldDirX * sin(-RTSPD * s_rot) + config->dir.y * cos(-RTSPD * s_rot);
	config->plane.x = \
	 config->plane.x * cos(-RTSPD * s_rot) - config->plane.y * sin(-RTSPD * s_rot);
	config->plane.y = \
	 oldPlaneX * sin(-RTSPD * s_rot) + config->plane.y * cos(-RTSPD * s_rot);
	return (0);
}
