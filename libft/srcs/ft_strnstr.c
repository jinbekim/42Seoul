/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:56:47 by jinbekim          #+#    #+#             */
/*   Updated: 2020/12/30 02:06:34 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *hay, const char *nee, size_t len)
{
	size_t	n;

	n = ft_strlen(nee);
	if (n == 0)
		return ((char *)hay);
	while (*hay && len >= n)
	{
		if (*hay == *nee && !(ft_strncmp(hay, nee, n)))
			return ((char *)hay);
		hay++;
		len--;
	}
	return (NULL);
}
