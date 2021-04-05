#include "cub3d_bonus.h"

void	life_bar_minimap(t_config *conf)
{
	int	y;
	int	x;

	x = -1;
	while (++x < 200)
	{
		y = -1 + conf->map.y;
		while (++y < conf->map.y + 30)
			conf->img_addr[y * conf->ls / 4 + x] = 0xff;
	}
	x = -1;
	while (++x < conf->map.x)
	{
		y = 0;
		while (x < conf->map.x && y < conf->map.y)
		{
			if (conf->cub[x][y] == '1')
				conf->img_addr[y * conf->ls / 4 + x] = 0xffffff;
			if (conf->cub[x][y] == '2' || conf->cub[x][y] == '3')
				conf->img_addr[y * conf->ls / 4 + x] = 0xff;
			if ((int)conf->pos.x == x && (int)conf->pos.y == y)
				conf->img_addr[y * conf->ls / 4 + x] = 0xff00;
			y++;
		}
	}
}

static int	is_wall(t_config *conf, int y, int x)
{
	int	len;
	int	start;
	int	end;

	len = (int)(conf->screen.y / conf->zbuff[x]);
	start = -len / 2 + conf->middle_line;
	end = len / 2 + conf->middle_line;
	if (start >= conf->screen.y)
		start = conf->screen.y - 1;
	if (end < 0)
		end = 0;
	if (y > start && y < end)
		return (1);
	return (0);
}

void	shadow(t_config *conf)
{
	int		x;
	int		y;
	double	rank;

	x = -1;
	while (++x < conf->screen.x)
	{
		rank = 1 / conf->zbuff[x];
		if (rank > 1)
			rank = 1;
		else if (rank < 0)
			rank = 0;
		y = -1;
		while (++y < conf->screen.y)
		{
			if (is_wall(conf, y, x))
			{
				conf->img_addr[y * conf->ls / 4 + x] = \
				((int)((conf->img_addr[y * conf->ls / 4 + x] \
				& 0xff0000) * rank) & 0xff0000) + \
				((int)((conf->img_addr[y * conf->ls / 4 + x] \
				& 0xff00) * rank) & 0xff00) + \
				((int)((conf->img_addr[y * conf->ls / 4 + x] \
				& 0xff) * rank) & 0xff);
			}
		}
	}
}

void	other_bonus(t_config *conf)
{
	shadow(conf);
	life_bar_minimap(conf);
}
