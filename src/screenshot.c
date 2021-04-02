/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:00:22 by jinbekim          #+#    #+#             */
/*   Updated: 2021/04/02 16:51:39 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_screen_data(t_config *conf)
{
	floor_ceil(conf);
	wall(conf);
	sprite(conf);
}

static void	write_bmp_header(int fd, t_config *conf)
{
	int	buf;

	write(fd, "BM", 2);
	buf = 14 + 40 + conf->screen.x * conf->screen.y * 4;
	write(fd, &buf, 4);
	buf = 0;
	write(fd, &buf, 2);
	write(fd, &buf, 2);
	buf = 54;
	write(fd, &buf, 4);
	buf = 40;
	write(fd, &buf, 4);
	write(fd, &conf->screen.x, 4);
	write(fd, &conf->screen.y, 4);
	buf = 1;
	write(fd, &buf, 2);
	write(fd, &conf->bpp, 2);
	buf = 0;
	write(fd, &buf, 4);
	write(fd, &buf, 4);
	write(fd, &buf, 4);
	write(fd, &buf, 4);
	write(fd, &buf, 4);
	write(fd, &buf, 4);
}

static void	write_bmp_data(int fd, t_config *conf)
{
	int	x;
	int	y;

	y = conf->screen.y;
	while (--y >= 0)
	{
		x = -1;
		while (++x < conf->screen.x)
			write(fd, &conf->img_addr[y * conf->ls / 4 + x], 4);
	}
}

void	screenshot(t_config *conf)
{
	int	fd;

	get_screen_data(conf);
	fd = open("screenshot.bmp", O_CREAT | O_RDWR);
	if (fd < 0)
		error_exit();
	write_bmp_header(fd, conf);
	write_bmp_data(fd, conf);
	close(fd);
	printf("Screenshot has been saved in \"./screenshot.bmp\"\n");
	exit(0);
}
