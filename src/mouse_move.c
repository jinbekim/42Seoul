/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:11:43 by jinbekim          #+#    #+#             */
/*   Updated: 2021/04/02 16:51:23 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	mult_rot_matrix(t_config *conf, double rotate)
{
	double	prevdir;
	double	prevplane;

	prevdir = conf->dir.x;
	prevplane = conf->plane.x;
	conf->dir.x = \
	 conf->dir.x * cos(-RTSPD * rotate) - conf->dir.y * sin(-RTSPD * rotate);
	conf->dir.y = \
	 prevdir * sin(-RTSPD * rotate) + conf->dir.y * cos(-RTSPD * rotate);
	conf->plane.x = \
	 conf->plane.x * cos(-RTSPD * rotate) - \
	  conf->plane.y * sin(-RTSPD * rotate);
	conf->plane.y = \
	 prevplane * sin(-RTSPD * rotate) + conf->plane.y * cos(-RTSPD * rotate);
}

int	mouse_move(int x, int y, t_config *conf)
{
	static int	prevx;
	double		rotate;

	if (prevx > x)
	{
		rotate = -1;
		prevx = x;
	}
	else if (prevx < x)
	{
		rotate = 1;
		prevx = x;
	}
	else
		return (0);
	if (x > conf->screen.x || x < 0 || y > conf->screen.y || y < 0)
		rotate = 0;
	mult_rot_matrix(conf, rotate);
	return (0);
}
