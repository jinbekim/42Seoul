/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 23:04:28 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/25 06:43:26 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"


static void	get_player_conf(t_config *config, int i, int j)
{
	if (config->pos.x != 0 && config->pos.y != 0)
		error_exit();
	config->pos.x = i;
	config->pos.y = j;
	if (config->cub[i][j] == 'N')
	{
		config->dir.y = 1;
		config->plane.x = 0.66;
	}
	else if (config->cub[i][j] == 'S')
	{
		config->dir.y = -1;
		config->plane.x = -0.66;
	}
	else if (config->cub[i][j] == 'E')
	{
		config->dir.x = 1;
		config->plane.y = -0.66;
	}
	else
	{
		config->dir.x = -1;
		config->plane.y = 0.66;
	}
}

static void	get_sprite_pos(t_config *config, int i, int j)
{
	static int	num = -1;
	t_sprite	*new;
	t_list	*tmp;

	num++;
	new = malloc(sizeof(t_sprite));
	new->x = i + 0.5;
	new->y = j + 0.5;
	new->order = num;
	tmp = ft_lstnew(new);
	free(new);
	ft_lstadd_back(&config->head, tmp);
}


static int	check_around(t_config *config, int i, int j)
{
	int	x_max;
	int y_max;

	x_max = config->map.x;
	y_max = config->map.y;
	if (i == 0 || j == 0)
		error_exit();
	if (i + 1 == x_max || j + 1 == y_max)
		error_exit();
	if (ft_strchr("012NWES", config->cub[i][j - 1]) == 0)
		error_exit();
	if (ft_strchr("012NWES", config->cub[i][j + 1]) == 0)
		error_exit();
	if (ft_strchr("012NWES", config->cub[i + 1][j]) == 0)
		error_exit();
	if (ft_strchr("012NWES", config->cub[i + 1][j]) == 0)
		error_exit();
	return (0);
}

static void	get_map_size(t_config *config)
{
	t_list	*tmp;
	int	i;
	int	len;

	i = -1;
	tmp = config->head;
	config->map.x = ft_lstsize(config->head);
	if ((config->cub = malloc(sizeof(char *) * (config->map.x + 1))) == NULL)
		error_exit();
	config->cub[config->map.x] = (void *)'\0';
	while (tmp)
	{
		if (config->map.y < (len = ft_strlen(tmp->content)))
			config->map.y = len;
		tmp = tmp->next;
	}
	len = config->map.y;
	while (++i < config->map.x)
	{
		if ((config->cub[i] = malloc(len + 1)) == NULL)
			error_exit();
		config->cub[i][len] = '\0';
		ft_memset(config->cub[i], ' ', len);
		ft_memcpy(config->cub[i], \
		 config->head->content, ft_strlen(config->head->content));
		config->head = config->head->next;
	}
}

void	set_map_conf(t_config *config)
{
	int	i;
	int	j;

	i = -1;
	get_map_size(config);
	while (++i < config->map.x)
	{
		j = 0;
		while (config->cub[i][j])
		{
			printf("hi %d\n", j);
			printf("cub[i][j] = %c\n", config->cub[i][j]);
			if (config->cub[i][j] == '0')
				check_around(config, i, j);
			else if (config->cub[i][j] == '2')
				get_sprite_pos(config, i, j);
			else if (config->cub[i][j] == 'N' || config->cub[i][j] == 'W' || \
			 config->cub[i][j] == 'E' || config->cub[i][j] == 'S')
				get_player_conf(config, i, j);
			j++;
		}
	}
}
