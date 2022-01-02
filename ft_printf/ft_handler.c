/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 21:56:30 by jinbekim          #+#    #+#             */
/*   Updated: 2021/01/20 22:26:07 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fmt_init(t_format *flags)
{
	flags->fill_blank = -1;
	flags->width = -1;
	flags->prec = -1;
	flags->len = -1;
}

static int	ft_putchar(char arg)
{
	write(1, &arg, 1);
	return (1);
}

static int	ft_putstr(char *str, t_format flags)
{
	int		count;

	count = 0;
	if (flags.len != -1)
	{
		while (flags.len != 0)
		{
			count += ft_putchar(*str);
			str++;
			flags.len--;
		}
	}
	else
	{
		while (*str != '\0')
		{
			count += ft_putchar(*str);
			str++;
		}
	}
	return (count);
}

int			ft_handler(const char *fmt, va_list ap)
{
	int			count;
	t_format	flags;
	char		*spec;

	count = 0;
	while (*fmt != '\0')
	{
		if (*fmt != '%')
		{
			count += ft_putchar(*fmt);
			fmt++;
			continue ;
		}
		fmt_init(&flags);
		if (!(spec = ft_flag_setter((char *)++fmt, ap, &flags)))
			return (count = -1);
		count += ft_putstr(spec, flags);
		free(spec);
		while (!ft_strchr("csudipxX%", *fmt))
			fmt++;
		fmt++;
	}
	return (count);
}
