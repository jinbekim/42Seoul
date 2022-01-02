/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:35:30 by jinbekim          #+#    #+#             */
/*   Updated: 2021/01/20 23:30:15 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_prec(t_format *flags, char *arg)
{
	char	*arr;
	int		len;

	len = (int)ft_strlen(arg) > flags->prec ? flags->prec : (int)ft_strlen(arg);
	if (!(arr = malloc(len + 1)))
		return (NULL);
	arr[len] = '\0';
	ft_memcpy(arr, arg, len);
	return (arr);
}

static char	*ft_width(t_format *flags, char *arg)
{
	char	*arr;
	int		len;
	int		strlen;

	len = flags->width;
	strlen = (int)ft_strlen(arg);
	if (len <= strlen)
		return (arr = ft_strdup(arg));
	if (!(arr = malloc(len + 1)))
		return (NULL);
	arr[len] = '\0';
	ft_memset(arr, ' ', len);
	if (flags->fill_blank == ' ')
		ft_memcpy(arr, arg, strlen);
	else if (flags->fill_blank == -1)
		ft_memcpy((arr + (len - strlen)), arg, strlen);
	return (arr);
}

static char	*ft_prec_width(t_format *flags, char *arg)
{
	char	*arr;
	char	*prec;

	if (flags->width >= flags->prec)
	{
		if (flags->prec >= (int)ft_strlen(arg))
			arr = ft_width(flags, arg);
		else
		{
			if (!(prec = ft_substr(arg, 0, flags->prec)))
				return (NULL);
			arr = ft_width(flags, prec);
			free(prec);
		}
	}
	else if (flags->prec >= (int)ft_strlen(arg))
		arr = ft_width(flags, arg);
	else
	{
		if (!(arr = malloc(flags->prec + 1)))
			return (NULL);
		arr[flags->prec] = '\0';
		ft_memcpy(arr, arg, flags->prec);
	}
	return (arr);
}

char		*s_handler(t_format *flags, char *arg)
{
	char	*arr;

	if (arg == NULL)
		arg = "(null)";
	if (flags->width == -1 && flags->prec == -1)
		arr = ft_strdup(arg);
	else if (flags->width == -1 && flags->prec >= 0)
		arr = ft_prec(flags, arg);
	else if (flags->width >= 0 && flags->prec == -1)
		arr = ft_width(flags, arg);
	else
		arr = ft_prec_width(flags, arg);
	return (arr);
}

char		*c_handler(t_format *flags, int arg)
{
	char	*arr;
	int		len;

	len = flags->width > 0 ? flags->width : 1;
	if (!(arr = malloc(len + 1)))
		return (NULL);
	arr[len] = '\0';
	if (flags->fill_blank == '0')
		ft_memset(arr, '0', len);
	else
		ft_memset(arr, ' ', len);
	if (flags->fill_blank == ' ')
		arr[0] = arg;
	else
		arr[len - 1] = arg;
	flags->len = len;
	return (arr);
}
