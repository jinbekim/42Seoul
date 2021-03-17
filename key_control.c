/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:13:58 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/17 16:33:23 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int key_control(int key, t_data *param)
{
	double oldd_x, oldp_x;
	if (key == 53)
		exit(0);

	param->vx_dir = param->x_dir * cos(1.571) - param->y_dir * sin(1.571);
	param->vy_dir = param->x_dir * sin(1.571) + param->y_dir * cos(1.571);

	if (key == KEY_W || key == AR_UP)
	{
		if (g_worldMap[(int)(param->x_pos + param->x_dir * MVSPD)][(int)param->y_pos] == 0)
			param->x_pos += param->x_dir * MVSPD;
		if (g_worldMap[(int)param->x_pos][(int)(param->y_pos + param->y_dir * MVSPD)] == 0)
			param->y_pos += param->y_dir * MVSPD;
	}
	if (key == KEY_S || key == AR_DW)
	{
		if (g_worldMap[(int)(param->x_pos - param->x_dir * MVSPD)][(int)param->y_pos] == 0)
			param->x_pos -= param->x_dir * MVSPD;
		if (g_worldMap[(int)param->x_pos][(int)(param->y_pos - param->y_dir * MVSPD)] == 0)
			param->y_pos -= param->y_dir * MVSPD;
	}
	if (key == KEY_A)
	{
		if (g_worldMap[(int)(param->x_pos + param->vx_dir * MVSPD)][(int)param->y_pos] == 0)
			param->x_pos += param->vx_dir * MVSPD;
		if (g_worldMap[(int)param->x_pos][(int)(param->y_pos + param->vy_dir * MVSPD)] == 0)
			param->y_pos += param->vy_dir * MVSPD;
	}
	if (key == KEY_D)
	{
		if (g_worldMap[(int)(param->x_pos - param->vx_dir * MVSPD)][(int)param->y_pos] == 0)
			param->x_pos -= param->vx_dir * MVSPD;
		if (g_worldMap[(int)param->x_pos][(int)(param->y_pos - param->vy_dir * MVSPD)] == 0)
			param->y_pos -= param->vy_dir * MVSPD;
	}
	if (key == AR_LT)
	{
		//both camera direction and camera plane must be rotated
		oldd_x = param->x_dir;
		param->x_dir = param->x_dir * cos(RTSPD) - param->y_dir * sin(RTSPD);
		param->y_dir = oldd_x * sin(RTSPD) + param->y_dir * cos(RTSPD);
		oldp_x = param->x_plane;
		param->x_plane = param->x_plane * cos(RTSPD) - param->y_plane * sin(RTSPD);
		param->y_plane = oldp_x * sin(RTSPD) + param->y_plane * cos(RTSPD);
	}
	if (key == AR_RT)
	{
		//both camera direction and camera plane must be rotated
		oldd_x = param->x_dir;
		param->x_dir = param->x_dir * cos(-RTSPD) - param->y_dir * sin(-RTSPD);
		param->y_dir = oldd_x * sin(-RTSPD) + param->y_dir * cos(-RTSPD);
		oldp_x = param->x_plane;
		param->x_plane = param->x_plane * cos(-RTSPD) - param->y_plane * sin(-RTSPD);
		param->y_plane = oldp_x * sin(-RTSPD) + param->y_plane * cos(-RTSPD);
	}
	return (0);
}
