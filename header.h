/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 02:56:52 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/17 16:46:42 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "./mlx/mlx.h"
# include "./get_next_line/get_next_line.h"

# define MAP_W 24
# define MAP_H 24
# define SC_W 640
# define SC_H 480

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define AR_LT 123
# define AR_RT 124
# define AR_UP 126
# define AR_DW 125

# define MVSPD 0.2
# define RTSPD 0.08

extern int g_worldMap[MAP_W][MAP_H];

typedef struct  s_tex
{
  void  *ptr;
  int *data;
  int  t_width;
  int  t_height;
  int  bpp;
  int  ls;
  int  en;
} t_tex;

typedef struct	s_data{
	void          *mlx;
	void        	*win;
	void	        *img;
	int	          *data;

  int           bpp;
  int           ls;
  int           en;

  double        x_pos;
  double        y_pos;
  double        x_dir;
  double        y_dir;
  double        x_plane;
  double        y_plane;

  double        vx_dir;
  double        vy_dir;

  t_tex         nr;
  t_tex         st;
  t_tex         ea;
  t_tex         we;
}			            t_data;

typedef struct  s_ray{
    double      camera_x;
    double      dir_x;
		double      dir_y;

		int         map_x;
		int         map_y;

		double      sd_x;
		double      sd_y;

		double      dd_x;
		double      dd_y;
		double      pwd;

		int         step_x;
		int         step_y;

		int         hit;
		int         side;
}               t_ray;

typedef struct  s_stripe{
  int height;
  int start;
  int end;
}              t_stripe;


int key_control(int key, t_data *param);
int mouse_move(int x, int y, t_data *param);
int close(void *param);
void  ray_casting(t_data *param);
void	texture(int x, t_ray *ray, t_data *param);

#endif
