/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:16:31 by jinbekim          #+#    #+#             */
/*   Updated: 2021/05/30 20:16:27 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(t_list **astack, t_list **bstack, t_list **inst)
{
	*astack = NULL;
	*bstack = NULL;
	*inst = NULL;
}

static void	ra_check(t_list *astack, t_list **inst)
{
	int		size;
	int		ra_num;
	t_list	*tmp;

	tmp = *inst;
	ra_num = 0;
	size = ft_lstsize(astack);
	while (tmp->next)
		tmp = tmp->next;
	while (ft_strncmp((char *)tmp->content, "ra", 3) == 0)
	{
		ra_num++;
		if (tmp->prev == NULL)
			break ;
		tmp = tmp->prev;
	}
	if (size - ra_num < ra_num)
	{
		ft_lstclear(&(tmp->next), free);
		tmp->next = NULL;
		add_instruct_ntimes(inst, "rra", size - ra_num);
	}
}

int			main(int ac, char **av)
{
	t_list	*astack;
	t_list	*bstack;
	t_list	*inst;

	if (ac < 2)
		return (0);
	init_stack(&astack, &bstack, &inst);
	input_stack(av, &astack);
	rate_rank(astack);
	if (examine_sort(astack) == ac - 1)
		print_exit(NULL);
	arrange_stack(&astack, &bstack, &inst);
	ra_check(astack, &inst);
	compression_inst(&inst);
	print_exit(inst);
	return (0);
}

/*
**	system("leaks push_swap > leaks_result; cat leaks_result |
** grep leaked && rm -rf leaks_result");
*/
