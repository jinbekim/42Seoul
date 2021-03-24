/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 03:13:37 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/25 04:16:15 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct	s_vec{
	double	x;
	double	y;
}				t_vec;

typedef struct	s_cord{
	int	x;
	int	y;
}				t_cord;

typedef struct	s_tex{
	void	*img;
	int	*addr;
	int	width;
	int	height;
	int	bpp;
	int	ls;
	int	en;

	double	wall_x;
	double	step;
	double	pos_t;
	t_cord	cord;
}				t_tex;

typedef struct	s_sprite{
	double	x;
	double	y;
	int	order;
}				t_sprite;

typedef struct	s_config{
	void	*mlx;
	void	*win;
	void	*img;

	int	*img_addr;
	int	bpp;
	int	ls;
	int	en;

	t_cord	map;
	t_vec	pos;
	t_vec	dir;
	t_vec	plane;
	char	**cub;
	t_list	*head;
	int	sprite_num;
	t_cord	screen;
	t_tex	sp;
	t_tex	no;
	t_tex	so;
	t_tex	we;
	t_tex	ea;
	int	floor_color;
	int	ceil_color;
}				t_config;

typedef struct	s_ray{
	t_vec	dir;
	t_vec	side_d;
	t_vec	delta_d;

	t_cord	map;
	t_cord	step;

	double	camera_x;
	double	perp_wd;
	int	hit;
	int	side;
}				t_ray;

typedef struct	s_stripe{
	int	height;
	int	start;
	int	end;
}				t_stripe;

#endif
