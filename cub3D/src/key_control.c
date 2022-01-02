/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:13:58 by jinbekim          #+#    #+#             */
/*   Updated: 2021/04/04 21:28:10 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_left_right(int key, t_config *conf)
{
	t_vec	vertical;

	vertical.x = conf->dir.x * cos(1.571) - conf->dir.y * sin(1.571);
	vertical.y = conf->dir.x * sin(1.571) + conf->dir.y * cos(1.571);
	if (key == KEY_A)
	{
		if (conf->cub[(int)(conf->pos.x + vertical.x * conf->mvs)] \
		[(int)conf->pos.y] != '1')
			conf->pos.x += vertical.x * conf->mvs;
		if (conf->cub[(int)conf->pos.x] \
		[(int)(conf->pos.y + vertical.y * conf->mvs)] != '1')
			conf->pos.y += vertical.y * conf->mvs;
	}
	if (key == KEY_D)
	{
		if (conf->cub[(int)(conf->pos.x - vertical.x * conf->mvs)] \
		[(int)conf->pos.y] != '1')
			conf->pos.x -= vertical.x * conf->mvs;
		if (conf->cub[(int)conf->pos.x] \
		[(int)(conf->pos.y - vertical.y * conf->mvs)] != '1')
			conf->pos.y -= vertical.y * conf->mvs;
	}
}

static void	move_fwd_bck(int key, t_config *conf)
{
	if (key == KEY_W)
	{
		if (conf->cub[(int)(conf->pos.x + conf->dir.x * conf->mvs)] \
		[(int)conf->pos.y] != '1')
			conf->pos.x += conf->dir.x * conf->mvs;
		if (conf->cub[(int)conf->pos.x] \
		[(int)(conf->pos.y + conf->dir.y * conf->mvs)] != '1')
			conf->pos.y += conf->dir.y * conf->mvs;
	}
	if (key == KEY_S)
	{
		if (conf->cub[(int)(conf->pos.x - conf->dir.x * conf->mvs)] \
		[(int)conf->pos.y] != '1')
			conf->pos.x -= conf->dir.x * conf->mvs;
		if (conf->cub[(int)conf->pos.x] \
		[(int)(conf->pos.y - conf->dir.y * conf->mvs)] != '1')
			conf->pos.y -= conf->dir.y * conf->mvs;
	}
}

static void	rotate_fov(int key, t_config *conf)
{
	double	old_dir_x;
	double	old_plane_x;

	if (key == AR_LT)
	{
		old_dir_x = conf->dir.x;
		conf->dir.x = conf->dir.x * cos(RTSPD) - conf->dir.y * sin(RTSPD);
		conf->dir.y = old_dir_x * sin(RTSPD) + conf->dir.y * cos(RTSPD);
		old_plane_x = conf->plane.x;
		conf->plane.x = conf->plane.x * cos(RTSPD) - conf->plane.y * sin(RTSPD);
		conf->plane.y = old_plane_x * sin(RTSPD) + conf->plane.y * cos(RTSPD);
	}
	if (key == AR_RT)
	{
		old_dir_x = conf->dir.x;
		conf->dir.x = conf->dir.x * cos(-RTSPD) - conf->dir.y * sin(-RTSPD);
		conf->dir.y = old_dir_x * sin(-RTSPD) + conf->dir.y * cos(-RTSPD);
		old_plane_x = conf->plane.x;
		conf->plane.x = \
		conf->plane.x * cos(-RTSPD) - conf->plane.y * sin(-RTSPD);
		conf->plane.y = old_plane_x * sin(-RTSPD) + conf->plane.y * cos(-RTSPD);
	}
}

static void	bonus_movement(int key, t_config *conf)
{
	if (key == AR_DW && conf->middle_line > conf->screen.y * 0.45)
		conf->middle_line -= 10;
	if (key == AR_UP && conf->middle_line < conf->screen.y * 0.55)
		conf->middle_line += 10;
	if (key == KEY_Z && conf->middle_line > conf->screen.y * 0.45)
	{
		conf->mvs = 0.05;
		while (conf->middle_line > conf->screen.y * 0.45)
			conf->middle_line -= 10;
	}
}

int	key_control(int key, t_config *conf)
{
	if (key == KEY_ESC)
	{
		printf("you pushed ESC key. Good Bye!\n");
		exit(0);
	}
	move_fwd_bck(key, conf);
	move_left_right(key, conf);
	bonus_movement(key, conf);
	rotate_fov(key, conf);
	return (0);
}
