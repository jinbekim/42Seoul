/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_over_avrg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:05:13 by jinbekim          #+#    #+#             */
/*   Updated: 2021/05/30 20:03:01 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_target_rrb(t_list *stack, float avrg, int *chunk_num)
{
	t_list	*tmp;
	int		target;

	tmp = NULL;
	target = 0;
	while (stack)
	{
		if (stack->rank >= avrg)
		{
			tmp = stack;
			target++;
		}
		stack = stack->next;
	}
	if (chunk_num != NULL)
		*chunk_num = target;
	return (ft_lstsize(tmp));
}

static int	find_target_rb(t_list *stack, float avrg)
{
	int		target;

	target = 0;
	while (stack)
	{
		if (stack->rank >= avrg)
			break ;
		target++;
		stack = stack->next;
	}
	return (target);
}

static void	find_bigger_num(t_list *bstack, int *t_rb, int *t_rrb)
{
	t_list	*tmp;
	int		rb;
	int		rrb;

	rb = *t_rb;
	rrb = *t_rrb;
	while (bstack->next)
	{
		if (rb-- == 0)
			tmp = bstack;
		bstack = bstack->next;
	}
	while (bstack)
	{
		if (--rrb == 0)
			break ;
		bstack = bstack->prev;
	}
	if (tmp->rank > bstack->rank)
		(*t_rrb)++;
	else
		(*t_rb)++;
}

static void	rotate_minimum(t_list **bstack, t_list **inst, int t_rb, int t_rrb)
{
	if (t_rb == t_rrb)
		find_bigger_num(*bstack, &t_rb, &t_rrb);
	if (t_rb < t_rrb)
	{
		while (t_rb)
		{
			add_and_execute_inst(0, bstack, inst, "rb");
			t_rb--;
		}
	}
	while (t_rb && t_rrb)
	{
		add_and_execute_inst(0, bstack, inst, "rrb");
		t_rrb--;
	}
}

int			pa_over_avrg(t_list **astack, t_list **bstack, t_list **inst)
{
	float	avrg;
	int		chunk_num;
	int		t_rrb;
	int		t_rb;

	arrange_small_stack2(astack, bstack, inst);
	while (*bstack)
	{
		if (ft_lstsize(*bstack) <= 30)
			push_sorted_chunk(astack, bstack, inst);
		avrg = calculate_avrg(*bstack, ft_lstsize(*bstack));
		t_rb = find_target_rb(*bstack, avrg);
		t_rrb = find_target_rrb(*bstack, avrg, &chunk_num);
		while (t_rrb != 0)
		{
			rotate_minimum(bstack, inst, t_rb, t_rrb);
			(*bstack)->chunk_num = chunk_num;
			add_and_execute_inst(astack, bstack, inst, "pa");
			t_rb = find_target_rb(*bstack, avrg);
			t_rrb = find_target_rrb(*bstack, avrg, 0);
		}
	}
	return (0);
}
