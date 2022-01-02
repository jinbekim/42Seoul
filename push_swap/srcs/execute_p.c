/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:08:55 by jinbekim          #+#    #+#             */
/*   Updated: 2021/05/30 18:19:21 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exe_push(t_list **to, t_list **from)
{
	t_list	*tmp;

	if (*from == NULL || from == NULL)
		return ;
	tmp = *from;
	*from = (*from)->next;
	if ((*from) != NULL)
		(*from)->prev = NULL;
	tmp->next = NULL;
	tmp->prev = NULL;
	ft_lstadd_front(to, tmp);
}

void		execute_p(t_list **astack, t_list **bstack, char *inst)
{
	if (ft_strncmp("pa", inst, 3) == 0)
		exe_push(astack, bstack);
	else if (ft_strncmp("pb", inst, 3) == 0)
		exe_push(bstack, astack);
}
