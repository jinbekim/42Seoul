/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:09:01 by jinbekim          #+#    #+#             */
/*   Updated: 2020/12/28 19:59:14 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *s1)
{
	size_t		len;
	char		*c1;

	len = ft_strlen(s1);
	if (!(c1 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len = 0;
	while (s1[len])
	{
		c1[len] = s1[len];
		len++;
	}
	c1[len] = 0;
	return (c1);
}
