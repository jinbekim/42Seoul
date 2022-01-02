/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 23:38:25 by jinbekim          #+#    #+#             */
/*   Updated: 2021/01/20 01:15:37 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_declen(int arg)
{
	int				declen;

	declen = 1;
	while (arg /= 10)
		declen++;
	return (declen);
}

static void	ft_cat(char **arr, int len, int arg)
{
	if (arg < 0)
	{
		(*arr)[--len] = (arg % 10 * -1) + '0';
		while (arg /= 10)
			(*arr)[--len] = (arg % 10 * -1) + '0';
	}
	else if (arg > 0)
	{
		(*arr)[--len] = arg % 10 + '0';
		while (arg /= 10)
			(*arr)[--len] = arg % 10 + '0';
	}
}

static char	*ft_to_arr(int prec, int arg)
{
	char	*arr;
	int		len;

	len = prec > ft_declen(arg) ? prec : ft_declen(arg);
	if (!(arr = malloc(len + 1)))
		return (NULL);
	arr[len] = '\0';
	ft_memset(arr, '0', len);
	if (arg < 0 || arg > 0)
		ft_cat(&arr, len, arg);
	else if (prec == 0)
		arr[0] = '\0';
	return (arr);
}

static void	ft_add(t_format *flags, char *nbr, char *arr, int arg)
{
	int	width;

	width = flags->width - ft_strlen(nbr);
	if (flags->fill_blank == '0' && flags->prec == -1)
		ft_memset(arr, '0', flags->width);
	else
		ft_memset(arr, ' ', flags->width);
	if (flags->fill_blank == ' ' && arg < 0)
		ft_memcpy(arr + 1, nbr, ft_strlen(nbr));
	else if (flags->fill_blank == ' ' && arg >= 0)
		ft_memcpy(arr, nbr, ft_strlen(nbr));
	else if (flags->fill_blank == '0' || flags->fill_blank == -1)
		ft_memcpy(arr + width, nbr, ft_strlen(nbr));
	if (arg < 0)
	{
		if (flags->fill_blank == '0' && flags->prec == -1)
			arr[0] = '-';
		else if (flags->fill_blank == ' ')
			arr[0] = '-';
		else
			arr[width - 1] = '-';
	}
}

char		*d_handler(t_format *flags, int arg)
{
	char	*arr;
	char	*nbr;
	int		width;

	if (!(nbr = ft_to_arr(flags->prec, arg)))
		return (NULL);
	if ((width = flags->width - ft_strlen(nbr)) > 0)
	{
		if (!(arr = malloc(flags->width + 1)))
			return (NULL);
		arr[flags->width] = '\0';
		ft_add(flags, nbr, arr, arg);
		free(nbr);
	}
	else
	{
		if (arg < 0)
		{
			arr = ft_strjoin("-", nbr);
			free(nbr);
		}
		else
			arr = nbr;
	}
	return (arr);
}
