/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 23:01:26 by jinbekim          #+#    #+#             */
/*   Updated: 2021/01/19 23:04:15 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_declen(unsigned int arg)
{
	unsigned int	len;

	len = 1;
	while (arg /= 10)
		len++;
	return (len);
}

static char	*ft_to_arr_u(int prec, unsigned int arg)
{
	char	*arr;
	int		len;

	len = prec > ft_declen(arg) ? prec : ft_declen(arg);
	if (!(arr = malloc(len + 1)))
		return (NULL);
	arr[len] = '\0';
	ft_memset(arr, '0', len);
	if (prec == 0 && arg == 0)
	{
		arr[0] = '\0';
		return (arr);
	}
	while (arg > 0)
	{
		arr[--len] = arg % 10 + '0';
		arg = arg / 10;
	}
	return (arr);
}

char		*u_handler(t_format *flags, unsigned int arg)
{
	char	*arr;
	char	*nbr;
	char	*tmp;
	int		width;

	if (!(nbr = ft_to_arr_u(flags->prec, arg)))
		return (NULL);
	if ((width = flags->width - ft_strlen(nbr)) <= 0)
		return (nbr);
	if (!(tmp = malloc(width + 1)))
	{
		free(nbr);
		return (NULL);
	}
	tmp[width] = '\0';
	ft_memset(tmp, ' ', width);
	if (flags->fill_blank == '0' && flags->prec == -1)
		ft_memset(tmp, '0', width);
	if (flags->fill_blank == '0' || flags->fill_blank == -1)
		arr = ft_strjoin(tmp, nbr);
	else
		arr = ft_strjoin(nbr, tmp);
	free(nbr);
	free(tmp);
	return (arr);
}
