/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:16:19 by jinbekim          #+#    #+#             */
/*   Updated: 2021/05/30 18:21:21 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exe_rotate(t_list **stack)
{
	t_list	*tmp;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	tmp->prev = ft_lstlast(*stack);
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
}

static void	exe_reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*first;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	last = ft_lstlast((*stack));
	last->next = *stack;
	last->prev->next = NULL;
	last->prev = NULL;
	first = *stack;
	first->prev = last;
	ft_lstadd_front(stack, last);
}

void		execute_r(t_list **astack, t_list **bstack, char *inst)
{
	if (ft_strncmp("ra", inst, 3) == 0)
		exe_rotate(astack);
	else if (ft_strncmp("rb", inst, 3) == 0)
		exe_rotate(bstack);
	else if (ft_strncmp("rr", inst, 3) == 0)
	{
		exe_rotate(astack);
		exe_rotate(bstack);
	}
	else if (ft_strncmp("rra", inst, 4) == 0)
		exe_reverse_rotate(astack);
	else if (ft_strncmp("rrb", inst, 4) == 0)
		exe_reverse_rotate(bstack);
	else if (ft_strncmp("rrr", inst, 4) == 0)
	{
		exe_reverse_rotate(astack);
		exe_reverse_rotate(bstack);
	}
}
