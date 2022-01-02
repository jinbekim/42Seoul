/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:06:12 by jinbekim          #+#    #+#             */
/*   Updated: 2021/05/30 18:20:15 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	init_list(t_list **astack, t_list **bstack, t_list **inst)
{
	*astack = NULL;
	*bstack = NULL;
	*inst = NULL;
}

int			main(int ac, char **av)
{
	t_list	*astack;
	t_list	*bstack;
	t_list	*inst;

	if (ac == 1)
		return (0);
	init_list(&astack, &bstack, &inst);
	input_stack(av, &astack);
	input_inst(&inst);
	rate_rank(astack);
	execute_inst(&astack, &bstack, inst);
	if (examine_sort(astack) != ac - 1)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	ft_lstclear(&astack, free);
	ft_lstclear(&bstack, free);
	ft_lstclear(&inst, free);
	return (0);
}
