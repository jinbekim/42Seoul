/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:48:15 by jinbekim          #+#    #+#             */
/*   Updated: 2021/01/19 23:02:27 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>

typedef	struct	s_format
{
	int			fill_blank;
	int			width;
	int			prec;
	int			len;
}				t_format;

int				ft_printf(const char *fmt, ...);
int				ft_handler(const char *fmt, va_list ap);
char			*ft_flag_setter(char *fmt, va_list ap, t_format *flags);
char			*c_handler(t_format *flags, int arg);
char			*d_handler(t_format *flags, int arg);
char			*u_handler(t_format *flags, unsigned int arg);
char			*p_handler(t_format *flags, unsigned long arg);
char			*x_handler(t_format *flags, unsigned int arg, int capital);
char			*s_handler(t_format *flags, char *arg);
char			*c_handler(t_format *flags, int arg);
char			*u_handler(t_format *flags, unsigned int arg);
char			*persent_handler(t_format *flags, int arg);

#endif
