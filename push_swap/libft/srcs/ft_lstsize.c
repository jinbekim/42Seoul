/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 21:42:41 by jinbekim          #+#    #+#             */
/*   Updated: 2021/04/13 19:58:21 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*tmp;

	count = 1;
	tmp = lst;
	if (lst == NULL)
		return (0);
	while (tmp->next)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
