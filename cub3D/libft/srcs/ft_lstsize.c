/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 21:42:41 by jinbekim          #+#    #+#             */
/*   Updated: 2021/04/02 18:21:45 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*tmp;

	count = 0;
	if (lst != NULL)
	{
		count++;
		tmp = lst;
		while (tmp->next)
		{
			count++;
			tmp = tmp->next;
		}
	}
	return (count);
}
