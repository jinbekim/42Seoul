/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 23:04:28 by jinbekim          #+#    #+#             */
/*   Updated: 2021/04/05 16:19:40 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_around(t_config *config, int i, int j)
{
	int	x_max;
	int	y_max;

	x_max = config->map.x;
	y_max = config->map.y;
	if (i == 0 || j == 0)
		error_exit();
	if (i + 1 == x_max || j + 1 == y_max)
		error_exit();
	if (ft_strchr("0123NWES", config->cub[i][j - 1]) == 0)
		error_exit();
	if (ft_strchr("0123NWES", config->cub[i][j + 1]) == 0)
		error_exit();
	if (ft_strchr("0123NWES", config->cub[i + 1][j]) == 0)
		error_exit();
	if (ft_strchr("0123NWES", config->cub[i + 1][j]) == 0)
		error_exit();
	return (0);
}

static void	get_player_conf(t_config *config, int i, int j)
{
	if (config->pos.x != 0 && config->pos.y != 0)
		error_exit();
	config->pos.x = i;
	config->pos.y = j;
	check_around(config, i, j);
	config->dir.y = 1;
	config->plane.x = 0.66;
	if (config->cub[i][j] == 'S')
	{
		config->dir.y = -1;
		config->plane.x = -0.66;
	}
	else if (config->cub[i][j] == 'E')
	{
		config->dir.x = 1;
		config->plane.y = -0.66;
	}
	else if (config->cub[i][j] == 'W')
	{
		config->dir.x = -1;
		config->plane.y = 0.66;
	}
	config->cub[i][j] = '0';
}

static void	get_sprite_pos(t_config *config, int i, int j, char num)
{
	t_sprite	*new;
	t_list		*tmp;

	new = malloc(sizeof(t_sprite));
	if (new == NULL)
		error_exit();
	new->x = (double)i + 0.5;
	new->y = (double)j + 0.5;
	new->num_tex = num - '0';
	config->sprite_num++;
	tmp = ft_lstnew(new);
	ft_lstadd_back(&config->head, tmp);
}

void	set_map_conf(t_config *config)
{
	int	i;
	int	j;

	i = -1;
	get_map_size(config);
	copy_map_info(config);
	while (++i < config->map.x)
	{
		j = 0;
		while (config->cub[i][j])
		{
			if (config->cub[i][j] == '0')
				check_around(config, i, j);
			else if (config->cub[i][j] == '2' || config->cub[i][j] == '3')
				get_sprite_pos(config, i, j, config->cub[i][j]);
			else if (config->cub[i][j] == 'N' || config->cub[i][j] == 'W' || \
			 config->cub[i][j] == 'E' || config->cub[i][j] == 'S')
				get_player_conf(config, i, j);
			j++;
		}
	}
	if (config->pos.x == 0 && config->pos.y == 0)
		error_exit();
}
