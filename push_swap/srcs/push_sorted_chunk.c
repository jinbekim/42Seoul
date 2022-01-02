/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sorted_chunk.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:24:39 by jinbekim          #+#    #+#             */
/*   Updated: 2021/05/30 20:01:16 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rrb_rotation_cost(t_list *bstack, int high, int low)
{
	int		rrb;
	t_list	*tmp;

	rrb = 0;
	while (bstack)
	{
		if (bstack->rank == high || bstack->rank == low)
			tmp = bstack;
		bstack = bstack->next;
	}
	return (ft_lstsize(tmp));
}

static int	rb_rotation_cost(t_list *bstack, int high, int low)
{
	int		rb;

	rb = 0;
	while (bstack)
	{
		if (bstack->rank == high || bstack->rank == low)
			break ;
		rb++;
		bstack = bstack->next;
	}
	return (rb);
}

static void	minimum_ratate(t_list **bstack, t_list **inst, int rb, int rrb)
{
	if (rb <= rrb)
		while (rb--)
			add_and_execute_inst(0, bstack, inst, "rb");
	else
		while (rrb--)
			add_and_execute_inst(0, bstack, inst, "rrb");
}

static void	init_high_low(t_list *bstack, int *high, int *low)
{
	*high = bstack->rank;
	*low = bstack->rank;
	while (bstack)
	{
		if (bstack->rank < *low)
			*low = bstack->rank;
		if (bstack->rank > *high)
			*high = bstack->rank;
		bstack = bstack->next;
	}
}

void		push_sorted_chunk(t_list **astack, t_list **bstack, t_list **inst)
{
	int		rb;
	int		rrb;
	int		high;
	int		low;

	init_high_low(*bstack, &high, &low);
	while (*bstack)
	{
		rb = rb_rotation_cost(*bstack, high, low);
		rrb = rrb_rotation_cost(*bstack, high, low);
		minimum_ratate(bstack, inst, rb, rrb);
		add_and_execute_inst(astack, bstack, inst, "pa");
		if ((*astack)->rank == high)
		{
			init_chunk_num(*astack, 1);
			high--;
		}
		else if ((*astack)->rank == low)
		{
			init_chunk_num(*astack, 0);
			add_and_execute_inst(astack, bstack, inst, "ra");
			low++;
		}
	}
}
