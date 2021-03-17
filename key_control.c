/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:13:58 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/17 17:52:32 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	move_left_right(int key, t_data *param)
{
	param->orthogonal_x = param->x_dir * cos(1.571) - param->y_dir * sin(1.571);
	param->orthogonal_y = param->x_dir * sin(1.571) + param->y_dir * cos(1.571);
	if (key == KEY_A)
	{
		if (g_worldMap[(int)(param->x_pos + param->orthogonal_x * MVSPD)][(int)param->y_pos] == 0)
			param->x_pos += param->orthogonal_x * MVSPD;
		if (g_worldMap[(int)param->x_pos][(int)(param->y_pos + param->orthogonal_y * MVSPD)] == 0)
			param->y_pos += param->orthogonal_y * MVSPD;
	}
	if (key == KEY_D)
	{
		if (g_worldMap[(int)(param->x_pos - param->orthogonal_x * MVSPD)][(int)param->y_pos] == 0)
			param->x_pos -= param->orthogonal_x * MVSPD;
		if (g_worldMap[(int)param->x_pos][(int)(param->y_pos - param->orthogonal_y * MVSPD)] == 0)
			param->y_pos -= param->orthogonal_y * MVSPD;
	}
}

static void	move_fwd_bck(int key, t_data *param)
{
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
}

static void	rotate_fov(int key, t_data *param)
{
	double old_dir_x;
	double old_plane_x;

	if (key == AR_LT)
	{
		old_dir_x = param->x_dir;
		param->x_dir = param->x_dir * cos(RTSPD) - param->y_dir * sin(RTSPD);
		param->y_dir = old_dir_x * sin(RTSPD) + param->y_dir * cos(RTSPD);
		old_plane_x = param->x_plane;
		param->x_plane = param->x_plane * cos(RTSPD) - param->y_plane * sin(RTSPD);
		param->y_plane = old_plane_x * sin(RTSPD) + param->y_plane * cos(RTSPD);
	}
	if (key == AR_RT)
	{
		old_dir_x = param->x_dir;
		param->x_dir = param->x_dir * cos(-RTSPD) - param->y_dir * sin(-RTSPD);
		param->y_dir = old_dir_x * sin(-RTSPD) + param->y_dir * cos(-RTSPD);
		old_plane_x = param->x_plane;
		param->x_plane = param->x_plane * cos(-RTSPD) - param->y_plane * sin(-RTSPD);
		param->y_plane = old_plane_x * sin(-RTSPD) + param->y_plane * cos(-RTSPD);
	}
}

int	key_control(int key, t_data *param)
{
	if (key == 53)
		exit(0);
	move_fwd_bck(key, param);
	move_left_right(key, param);
	rotate_fov(key, param);
	return (0);
}
