/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_small_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:05:20 by jinbekim          #+#    #+#             */
/*   Updated: 2021/05/30 20:09:11 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	arrange_three2(t_list **astack, t_list **bstack, t_list **inst)
{
	t_list	**t;

	t = astack;
	if (ft_lstsize(*t) != 3)
		return ;
	if ((*t)->rank > (*t)->next->rank && (*t)->rank > (*t)->next->next->rank)
		add_and_execute_inst(astack, bstack, inst, "ra");
	if ((*t)->next->rank > (*t)->rank \
	&& (*t)->next->rank > (*t)->next->next->rank)
		add_and_execute_inst(astack, bstack, inst, "rra");
	if ((*t)->rank > (*t)->next->rank && (*t)->rank < (*t)->next->next->rank)
		add_and_execute_inst(astack, bstack, inst, "sa");
}

static void	is_need_swap(t_list **stack, t_list **inst)
{
	if ((*stack)->rank > ((*stack)->next->rank))
		add_and_execute_inst(stack, 0, inst, "sa");
	init_chunk_num(*stack, 1);
	init_chunk_num((*stack)->next, 1);
}

static void	arrange_three(t_list **astack, t_list **bstack, t_list **inst)
{
	t_list	*tmp;

	tmp = *astack;
	init_chunk_num(tmp, 1);
	init_chunk_num(tmp->next, 1);
	init_chunk_num(tmp->next->next, 1);
	if (ft_lstsize(tmp) == 3)
		return (arrange_three2(astack, bstack, inst));
	tmp = *astack;
	if (tmp->rank > tmp->next->next->rank)
		add_and_execute_inst(astack, bstack, inst, "pb");
	is_need_swap(astack, inst);
	if ((*astack)->chunk_num == 1)
	{
		init_chunk_num(*astack, 0);
		add_and_execute_inst(astack, bstack, inst, "ra");
	}
	if (*bstack)
		add_and_execute_inst(astack, bstack, inst, "pa");
	is_need_swap(astack, inst);
	while ((*astack)->chunk_num == 1)
	{
		init_chunk_num(*astack, 0);
		add_and_execute_inst(astack, bstack, inst, "ra");
	}
}

void		arrange_small_stack2(\
t_list **astack, t_list **bstack, t_list **inst)
{
	if ((*astack)->chunk_num == 2)
		is_need_swap(astack, inst);
	else if ((*astack)->chunk_num == 3)
		arrange_three2(astack, bstack, inst);
}

void		arrange_small_stack(t_list **astack, t_list **bstack, t_list **inst)
{
	if ((*astack)->chunk_num == 1)
	{
		init_chunk_num(*astack, 0);
		add_and_execute_inst(astack, bstack, inst, "ra");
	}
	else if ((*astack)->chunk_num == 2)
		is_need_swap(astack, inst);
	else if ((*astack)->chunk_num == 3)
		arrange_three(astack, bstack, inst);
}
