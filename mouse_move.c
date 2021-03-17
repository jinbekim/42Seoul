/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:11:43 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/17 16:33:22 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int mouse_move(int x, int y, t_data *param)
{
	static double s_rot;
	static int ex_x;
	double oldDirX = param->x_dir;
	double oldPlaneX = param->x_plane;

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
	if (x > SC_W || x < 0 || y > SC_H || y < 0)
		s_rot = 0;
	//both camera direction and camera plane must be rotated
	param->x_dir = param->x_dir * cos(-RTSPD * s_rot) - param->y_dir * sin(-RTSPD * s_rot);
	param->y_dir = oldDirX * sin(-RTSPD * s_rot) + param->y_dir * cos(-RTSPD * s_rot);
	param->x_plane = param->x_plane * cos(-RTSPD * s_rot) - param->y_plane * sin(-RTSPD * s_rot);
	param->y_plane = oldPlaneX * sin(-RTSPD * s_rot) + param->y_plane * cos(-RTSPD * s_rot);
	return (0);
}
