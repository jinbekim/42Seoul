/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_setter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 04:46:44 by jinbekim          #+#    #+#             */
/*   Updated: 2021/01/21 19:36:56 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_spec_switch(char fmt, va_list ap, t_format *flags)
{
	char *spec;

	if (fmt == 'c')
		spec = c_handler(flags, va_arg(ap, int));
	else if (fmt == 's')
		spec = s_handler(flags, va_arg(ap, char *));
	else if (fmt == 'x')
		spec = x_handler(flags, va_arg(ap, unsigned int), 'x');
	else if (fmt == 'X')
		spec = x_handler(flags, va_arg(ap, unsigned int), 'X');
	else if (fmt == 'p')
		spec = p_handler(flags, (unsigned long)va_arg(ap, void *));
	else if (fmt == 'd' || fmt == 'i')
		spec = d_handler(flags, va_arg(ap, int));
	else if (fmt == 'u')
		spec = u_handler(flags, va_arg(ap, unsigned int));
	else if (fmt == '%')
		spec = persent_handler(flags, '%');
	else
		spec = NULL;
	return (spec);
}

static char	*ft_fill_blank(char *fmt, t_format *flags)
{
	while (*fmt == '0' || *fmt == '-')
	{
		if (flags->fill_blank == -1 && *fmt == '0')
			flags->fill_blank = '0';
		else if (*fmt == '-')
			flags->fill_blank = ' ';
		fmt++;
	}
	return (fmt);
}

static char	*ft_iswidth(char *fmt, va_list ap, t_format *flags)
{
	int	width;

	width = 0;
	if (ft_isdigit(*fmt))
	{
		while (ft_isdigit(*fmt))
		{
			width = width * 10 + (*fmt - '0');
			flags->width = width;
			fmt++;
		}
	}
	else if (*fmt == '*')
	{
		if ((flags->width = va_arg(ap, int)) < 0)
		{
			flags->fill_blank = ' ';
			flags->width *= -1;
		}
		fmt++;
	}
	return (fmt);
}

static char	*ft_isprec(char *fmt, va_list ap, t_format *flags)
{
	if (*fmt == '.')
	{
		fmt++;
		if (ft_isdigit(*fmt))
		{
			flags->prec = 0;
			while (ft_isdigit(*fmt))
			{
				flags->prec = flags->prec * 10 + (*fmt - '0');
				fmt++;
			}
		}
		else if (*fmt == '*')
		{
			if ((flags->prec = va_arg(ap, int)) < 0)
			{
				flags->prec = -1;
			}
			fmt++;
		}
		else
			flags->prec = 0;
	}
	return (fmt);
}

char		*ft_flag_setter(char *fmt, va_list ap, t_format *flags)
{
	fmt = ft_fill_blank(fmt, flags);
	fmt = ft_iswidth(fmt, ap, flags);
	fmt = ft_isprec(fmt, ap, flags);
	return (ft_spec_switch(*fmt, ap, flags));
}
