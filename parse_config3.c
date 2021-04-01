/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 00:01:58 by jinbekim          #+#    #+#             */
/*   Updated: 2021/04/02 03:30:08 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	copy_map_info(t_config *conf)
{
	int		i;
	int		len;
	t_list	*tmp;
	t_list	*tmp2;

	i = -1;
	len = conf->map.y;
	tmp2 = conf->head;
	while (++i < conf->map.x)
	{
		tmp = tmp2;
		conf->cub[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (conf->cub[i] == NULL)
			error_exit();
		conf->cub[i][len] = '\0';
		ft_memset(conf->cub[i], 1, len);
		ft_memcpy(conf->cub[i], tmp->content, ft_strlen(tmp->content));
		tmp2 = tmp2->next;
		free(tmp->content);
		free(tmp);
	}
	conf->head = NULL;
}

void	get_map_size(t_config *conf)
{
	t_list	*tmp;
	int		len;

	tmp = conf->head;
	if (tmp == NULL)
		error_exit();
	conf->map.x = ft_lstsize(tmp);
	conf->cub = malloc(sizeof(char *) * (conf->map.x + 1));
	if (conf->cub == NULL)
		error_exit();
	conf->cub[conf->map.x] = (void *) 0;
	while (tmp)
	{
		len = ft_strlen((char *)tmp->content);
		if (conf->map.y < len)
			conf->map.y = len;
		tmp = tmp->next;
	}
}

int	parser_r(char *line, t_config *config)
{
	int	idx;

	idx = 1;
	while (line[idx] == ' ' && line[idx] != '\0')
		idx++;
	while (ft_isdigit(line[idx]) && line[idx] != '\0')
		config->screen.x = config->screen.x * 10 + line[idx++] - '0';
	while (line[idx] == ' ' && line[idx] != '\0')
		idx++;
	if (line[idx] == '\0')
		error_exit();
	while (ft_isdigit(line[idx]))
		config->screen.y = config->screen.y * 10 + line[idx++] - '0';
	return (1);
}

int	parser_tex(char *line, t_tex *tex)
{
	char	*tmp;

	while (*line != '.' && *line != '\0')
		line++;
	if (*line == '\0')
		error_exit();
	tmp = ft_strdup(line);
	tex->img = (void *)tmp;
	return (1);
}

int	parser_bg(char *line, int *color)
{
	int	red;
	int	green;
	int	blue;

	red = 0;
	green = 0;
	blue = 0;
	while (!ft_isdigit(*line) && *line != '\0')
		line++;
	while (ft_isdigit(*line) && *line != '\0')
		red = red * 10 + *line++ - '0';
	while (!ft_isdigit(*line) && *line != '\0')
		line++;
	while (ft_isdigit(*line) && *line != '\0')
		green = green * 10 + *line++ - '0';
	while (!ft_isdigit(*line) && *line != '\0')
		line++;
	if (*line == '\0')
		error_exit();
	while (ft_isdigit(*line))
		blue = blue * 10 + *line++ - '0';
	if (red > 255 || green > 255 || blue > 255)
		error_exit();
	*color = (red << 16) + (green << 8) + blue;
	return (1);
}
