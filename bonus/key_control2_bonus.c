#include "cub3d_bonus.h"

int	key_release(int key, t_config *conf)
{
	if (key == KEY_Z)
	{
		while (conf->middle_line < conf->screen.y / 2)
			conf->middle_line += 5;
		conf->mvs = 0.2;
	}
	return (0);
}
