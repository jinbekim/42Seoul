/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:36:09 by jinbekim          #+#    #+#             */
/*   Updated: 2021/04/02 16:51:27 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_cubfile(const char *path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	if (path[i - 4] == '.' && \
		path[i - 3] == 'c' && \
		path[i - 2] == 'u' && \
		path[i - 1] == 'b')
		return (0);
	return (1);
}

static void	make_map_lst(char *line, t_config *config)
{
	t_list	*new;
	char	*tmp;

	tmp = ft_strdup(line);
	new = ft_lstnew(tmp);
	ft_lstadd_back(&config->head, new);
}

static int	set_config(char *line, t_config *config)
{
	if (line[0] == 'R' && line[1] == ' ')
		return (parser_r(line, config));
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		return (parser_tex(line, &config->no) << 1);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		return (parser_tex(line, &config->so) << 2);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		return (parser_tex(line, &config->we) << 3);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		return (parser_tex(line, &config->ea) << 4);
	else if (line[0] == 'S' && line[1] == ' ')
		return (parser_tex(line, &config->sp) << 5);
	else if (line[0] == 'F' && line[1] == ' ')
		return (parser_bg(line, &config->floor_color) << 6);
	else if (line[0] == 'C' && line[1] == ' ')
		return (parser_bg(line, &config->ceil_color) << 7);
	else
		error_exit();
	return (0);
}

int	parse_config(const char *file_path, t_config *config)
{
	int				fd;
	int				read_code;
	unsigned char	parsing_done;
	char			*line;

	parsing_done = 0;
	read_code = 1;
	fd = open(file_path, O_RDONLY);
	if (fd < 0 || is_cubfile(file_path))
		return (-1);
	while (read_code > 0)
	{
		read_code = get_next_line(fd, &line);
		if (read_code == -1)
			return (-1);
		if (parsing_done != 255 && *line != '\0')
			parsing_done |= set_config(line, config);
		else if (parsing_done == 255 && *line != '\0')
			make_map_lst(line, config);
		free(line);
	}
	set_map_conf(config);
	return (0);
}
