/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:36:09 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/23 23:55:01 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static void	parser_r(char *line, t_camera *parsed)
{
	int	idx;

	idx = 1;
	parsed->screen.x = 0;
	parsed->screen.y = 0;
	while (line[idx] == ' ')
		idx++;
	while (ft_isdigit(line[idx]))
		parsed->screen.x = parsed->screen.x * 10 + line[idx++] - '0';
	while (line[idx] == ' ')
		idx++;
	while (ft_isdigit(line[idx]))
		parsed->screen.y = parsed->screen.y * 10 + line[idx++] - '0';
	printf("resolution : %d %d\n", parsed->screen.x, parsed->screen.y);
}

static void	parser_tex(char *line, t_tex *tex)
{
	while (*line != '.')
		line++;
	tex->img = ft_strdup(line);
	printf("xpm file path : %s\n", (char *)tex->img);
}

static void	parser_bg(char *line, int *color)
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
	while (ft_isdigit(*++line))
		green = green * 10 + *line - '0';
	while (ft_isdigit(*++line))
		blue = blue * 10 + *line - '0';
	*color = (red << 16) + (green << 8) + blue;
	printf("red : %d g: %d b: %d\n", red, green, blue);
	printf("color : %d\n", *color);
}

static int	parser(char *line, t_camera *parsed)
{
	if (line[0] == 'R')
		parser_r(line, parsed);
	else if (line[0] == 'N' && line[1] == 'O')
		parser_tex(line, &parsed->no);
	else if (line[0] == 'S' && line[1] == 'O')
		parser_tex(line, &parsed->so);
	else if (line[0] == 'W' && line[1] == 'E')
		parser_tex(line, &parsed->we);
	else if (line[0] == 'E' && line[1] == 'A')
		parser_tex(line, &parsed->ea);
	else if (line[0] == 'S')
		parser_tex(line, &parsed->sprite);
	else if (line[0] == 'F')
		parser_bg(line, &parsed->floor_color);
	else if (line[0] == 'C')
		parser_bg(line, &parsed->ceil_color);
	else
		error_handling(EINVAL);
	return (1);
}

void	parsing(const char *file_path, t_camera *parsed)
{
	int	fd;
	int	read_code;
	int	done;
	char	*line;

	done = 0;
	read_code = 1;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (error_handling(EBADF));
	if (is_cub(file_path))
		return (error_handling(EINVAL));
	while (read_code > 0)
	{
		read_code = get_next_line(fd, &line);
		if (*line == '\n')
			;
		else if (done < 8)
			done += parser(line, parsed);
		else
			parser_map(line, parsed);
		free(line);
	}
}
	// data.x_pos = 22;
	// data.y_pos = 15;
	// data.x_dir = -1;
	// data.y_dir = 0;
	// data.x_plane = 0;
	// data.y_plane = 0.66;


	// data.nr.ptr = mlx_xpm_file_to_image(data.mlx, "./textures/wood.xpm", &data.nr.t_width, &data.nr.t_height);
	// data.nr.data = (int *)mlx_get_data_addr(data.nr.ptr, &data.nr.bpp, &data.nr.ls, &data.nr.en);
	// data.st.ptr = mlx_xpm_file_to_image(data.mlx, "./textures/greystone.xpm", &data.st.t_width, &data.st.t_height);
	// data.st.data = (int *)mlx_get_data_addr(data.st.ptr, &data.st.bpp, &data.st.ls, &data.st.en);
	// data.we.ptr = mlx_xpm_file_to_image(data.mlx, "./textures/purplestone.xpm", &data.we.t_width, &data.we.t_height);
	// data.we.data = (int *)mlx_get_data_addr(data.we.ptr, &data.we.bpp, &data.we.ls, &data.we.en);
	// data.ea.ptr = mlx_xpm_file_to_image(data.mlx, "./textures/redbrick.xpm", &data.ea.t_width, &data.ea.t_height);
	// data.ea.data = (int *)mlx_get_data_addr(data.ea.ptr, &data.ea.bpp, &data.ea.ls, &data.ea.en);
