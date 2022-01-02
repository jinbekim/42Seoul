/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 23:30:47 by jinbekim          #+#    #+#             */
/*   Updated: 2021/01/20 01:56:08 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned long arg)
{
	int hexlen;

	hexlen = 1;
	while (arg /= 16)
		hexlen++;
	return (hexlen);
}

static char	*ft_tohex(unsigned int arg, int prec, int flag)
{
	char	*arr;
	char	digit[16];
	int		hexlen;

	hexlen = ft_hexlen(arg);
	if (prec > hexlen)
		hexlen = prec;
	if (flag == 'x')
		ft_memcpy(digit, "0123456789abcdef", 16);
	else if (flag == 'X')
		ft_memcpy(digit, "0123456789ABCDEF", 16);
	if (!(arr = malloc(hexlen + 1)))
		return (NULL);
	arr[hexlen] = '\0';
	ft_memset(arr, '0', hexlen);
	if (prec == 0 && arg == 0)
		arr[0] = '\0';
	while (arg != 0)
	{
		arr[--hexlen] = digit[arg % 16];
		arg /= 16;
	}
	return (arr);
}

static char	*ft_to_malloc(int width, char *hex)
{
	char	*arr;

	if (!(arr = malloc(width + 1)))
	{
		free(hex);
		return (NULL);
	}
	return (arr);
}

char		*x_handler(t_format *flags, unsigned int arg, int capital)
{
	char	*arr;
	char	*hex;
	char	*tmp;
	int		width;

	if (!(hex = ft_tohex(arg, flags->prec, capital)))
		return (NULL);
	if ((width = flags->width - ft_strlen(hex)) <= 0)
		return (hex);
	if (!(tmp = ft_to_malloc(width, hex)))
		return (NULL);
	tmp[width] = '\0';
	ft_memset(tmp, ' ', width);
	if (flags->fill_blank == ' ')
		arr = ft_strjoin(hex, tmp);
	else
	{
		if (flags->fill_blank == '0' && flags->prec == -1)
			ft_memset(tmp, '0', width);
		arr = ft_strjoin(tmp, hex);
	}
	free(tmp);
	free(hex);
	return (arr);
}
