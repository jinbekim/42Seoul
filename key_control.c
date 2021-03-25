/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:13:58 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/26 04:02:44 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static void	move_left_right(int key, t_config *config)
{
	t_vec	vertical;

	vertical.x = config->dir.x * cos(1.571) - config->dir.y * sin(1.571);
	vertical.y = config->dir.x * sin(1.571) + config->dir.y * cos(1.571);
	if (key == KEY_A)
	{
		if (config->cub[(int)(config->pos.x + vertical.x * MVSPD)][(int)config->pos.y] == '0')
			config->pos.x += vertical.x * MVSPD;
		if (config->cub[(int)config->pos.x][(int)(config->pos.y + vertical.y * MVSPD)] == '0')
			config->pos.y += vertical.y * MVSPD;
	}
	if (key == KEY_D)
	{
		if (config->cub[(int)(config->pos.x - vertical.x * MVSPD)][(int)config->pos.y] == '0')
			config->pos.x -= vertical.x * MVSPD;
		if (config->cub[(int)config->pos.x][(int)(config->pos.y - vertical.y * MVSPD)] == '0')
			config->pos.y -= vertical.y * MVSPD;
	}
}

static void	move_fwd_bck(int key, t_config *config)
{
	if (key == KEY_W || key == AR_UP)
	{
		if (config->cub[(int)(config->pos.x + config->dir.x * MVSPD)][(int)config->pos.y] == '0')
			config->pos.x += config->dir.x * MVSPD;
		if (config->cub[(int)config->pos.x][(int)(config->pos.y + config->dir.y * MVSPD)] == '0')
			config->pos.y += config->dir.y * MVSPD;
	}
	if (key == KEY_S || key == AR_DW)
	{
		if (config->cub[(int)(config->pos.x - config->dir.x * MVSPD)][(int)config->pos.y] == '0')
			config->pos.x -= config->dir.x * MVSPD;
		if (config->cub[(int)config->pos.x][(int)(config->pos.y - config->dir.y * MVSPD)] == '0')
			config->pos.y -= config->dir.y * MVSPD;
	}
}

static void	rotate_fov(int key, t_config *config)
{
	double old_dir_x;
	double old_plane_x;

	if (key == AR_LT)
	{
		old_dir_x = config->dir.x;
		config->dir.x = config->dir.x * cos(RTSPD) - config->dir.y * sin(RTSPD);
		config->dir.y = old_dir_x * sin(RTSPD) + config->dir.y * cos(RTSPD);
		old_plane_x = config->plane.x;
		config->plane.x = config->plane.x * cos(RTSPD) - config->plane.y * sin(RTSPD);
		config->plane.y = old_plane_x * sin(RTSPD) + config->plane.y * cos(RTSPD);
	}
	if (key == AR_RT)
	{
		old_dir_x = config->dir.x;
		config->dir.x = config->dir.x * cos(-RTSPD) - config->dir.y * sin(-RTSPD);
		config->dir.y = old_dir_x * sin(-RTSPD) + config->dir.y * cos(-RTSPD);
		old_plane_x = config->plane.x;
		config->plane.x = config->plane.x * cos(-RTSPD) - config->plane.y * sin(-RTSPD);
		config->plane.y = old_plane_x * sin(-RTSPD) + config->plane.y * cos(-RTSPD);
	}
}

int	key_control(int key, t_config *config)
{
	if (key == KEY_ESC)
		exit(0);
	move_fwd_bck(key, config);
	move_left_right(key, config);
	rotate_fov(key, config);
	return (0);
}
