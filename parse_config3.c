/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 00:01:58 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/25 05:13:38 by jinbekim         ###   ########.fr       */
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
	printf("resolution : %d %d\n", config->screen.x, config->screen.y);
    return (1);
}

int	parser_tex(char *line, t_tex *tex, t_config *config)
{
	while (*line != '.')
		line++;
	tex->img = mlx_xpm_file_to_image(config->mlx, line, &tex->width, &tex->height);
	tex->addr = (int *)mlx_get_data_addr(tex->img, &tex->bpp, &tex->ls, &tex->en);
	printf("xpm file path : %s\n", line);
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
	printf("red : %d g: %d b: %d\n", red, green, blue);
	printf("color : %d\n", *color);
    return (1);
}
