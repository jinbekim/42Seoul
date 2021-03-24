/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:36:09 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/25 05:27:16 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static void	make_map_lst(char *line, t_config *config)
{
	t_list	*new;

	new = ft_lstnew(line);
	ft_lstadd_back(&config->head, new);
}

static int	set_config(char *line, t_config *config)
{
	if (line[0] == 'R' && line[1] == ' ')
		return (parser_r(line, config));
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		return (parser_tex(line, &config->no, config) << 1);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		return (parser_tex(line, &config->so, config) << 2);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		return (parser_tex(line, &config->we, config) << 3);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		return (parser_tex(line, &config->ea, config) << 4);
	else if (line[0] == 'S' && line[1] == ' ')
		return (parser_tex(line, &config->sp, config) << 5);
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
	int	fd;
	int	read_code;
	unsigned char	parsing_done;
	char	*line;

	parsing_done = 0;
	read_code = 1;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (read_code > 0)
	{
		if ((read_code = get_next_line(fd, &line)) == -1)
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
