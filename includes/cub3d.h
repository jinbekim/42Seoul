/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 02:56:52 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/23 23:03:08 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include "keycode.h"
# include "structure.h"
# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"

# define MVSPD 0.2
# define RTSPD 0.08

int	mouse_move(int x, int y, t_camera *parsed);
int	key_control(int key, t_camera *parsed);
int	game_close(void *param);
void	parsing(const char *file_path, t_camera *parsed);
void	error_handling(int errnum);

#endif
