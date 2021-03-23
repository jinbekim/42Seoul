/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:34:12 by jinbekim          #+#    #+#             */
/*   Updated: 2020/12/28 15:00:22 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_calloc(size_t count, size_t size)
{
	void		*arr;
	size_t		len;

	len = count * size;
	if (!(arr = malloc(len)))
		return (0);
	ft_memset(arr, 0, len);
	return (arr);
}
