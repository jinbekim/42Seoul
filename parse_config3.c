/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 00:01:58 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/26 03:27:12 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	parser_r(char *line, t_config *config)
{
	int	idx;

	idx = 1;
	while (line[idx] == ' ')
		idx++;
	while (ft_isdigit(line[idx]))
		config->screen.x = config->screen.x * 10 + line[idx++] - '0';
	while (line[idx] == ' ')
		idx++;
	while (ft_isdigit(line[idx]))
		config->screen.y = config->screen.y * 10 + line[idx++] - '0';
	return (1);
}

int	parser_tex(char *line, t_tex *tex)
{
	char	*tmp;

	while (*line != '.')
		line++;
	tmp = ft_strdup(line);
	tex->img = (void *)tmp;
	return (1);
}

int	parser_bg(char *line, int *color)
{
	int	red;
	int green;
	int blue;

	red = 0;
	green = 0;
	blue = 0;
	while (!ft_isdigit(*line))
		line++;
	while (ft_isdigit(*line))
		red = red * 10 + *line++ - '0';
	while (!ft_isdigit(*line))
		line++;
	while (ft_isdigit(*line))
		green = green * 10 + *line++ - '0';
	while (!ft_isdigit(*line))
		line++;
	while (ft_isdigit(*line))
		blue = blue * 10 + *line++ - '0';
	*color = (red << 16) + (green << 8) + blue;
	return (1);
}
