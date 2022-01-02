/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:05:22 by jinbekim          #+#    #+#             */
/*   Updated: 2021/05/30 19:55:52 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_rest_chunk(t_list *stack)
{
	int		head;
	int		size;
	t_list	*tmp;

	size = 0;
	tmp = stack;
	head = stack->chunk_num;
	if (head == 0)
		return ;
	while (tmp && tmp->chunk_num == head)
	{
		size++;
		tmp = tmp->next;
	}
	while (stack && stack->chunk_num == head)
	{
		stack->chunk_num = size;
		stack = stack->next;
	}
}

void		arrange_stack(t_list **astack, t_list **bstack, t_list **inst)
{
	float	avrg;

	init_chunk_num(*astack, ft_lstsize(*astack));
	while ((*astack)->chunk_num != 0)
	{
		avrg = calculate_avrg(*astack, (*astack)->chunk_num);
		if ((*astack)->chunk_num > 3)
		{
			pb_under_avrg(astack, bstack, inst, avrg);
			init_rest_chunk(*astack);
			pa_over_avrg(astack, bstack, inst);
		}
		arrange_small_stack(astack, bstack, inst);
	}
}
