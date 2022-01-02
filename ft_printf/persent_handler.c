/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   persent_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:47:23 by jinbekim          #+#    #+#             */
/*   Updated: 2021/01/20 02:34:14 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*persent_handler(t_format *flags, int arg)
{
	char	*arr;
	int		len;

	len = flags->width > 1 ? flags->width : 1;
	if (!(arr = malloc(len + 1)))
		return (NULL);
	arr[len] = '\0';
	ft_memset(arr, ' ', len);
	if (flags->fill_blank == '0')
	{
		ft_memset(arr, '0', len);
		arr[len - 1] = arg;
	}
	else if (flags->fill_blank == ' ')
		arr[0] = arg;
	else
		arr[len - 1] = arg;
	return (arr);
}
