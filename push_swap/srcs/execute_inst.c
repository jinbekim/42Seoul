/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_inst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:10:50 by jinbekim          #+#    #+#             */
/*   Updated: 2021/05/30 18:19:07 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_and_execute_inst(\
t_list **astack, t_list **bstack, t_list **inst, char *instruct)
{
	if (*instruct == 'p')
	{
		add_instruct_ntimes(inst, instruct, 1);
		execute_p(astack, bstack, instruct);
	}
	else if (*instruct == 'r')
	{
		add_instruct_ntimes(inst, instruct, 1);
		execute_r(astack, bstack, instruct);
	}
	else if (*instruct == 's')
	{
		add_instruct_ntimes(inst, instruct, 1);
		execute_s(astack, bstack, instruct);
	}
}

void	execute_inst(t_list **astack, t_list **bstack, t_list *inst)
{
	while (inst)
	{
		if (((char *)inst->content)[0] == 's')
			execute_s(astack, bstack, inst->content);
		else if (((char *)inst->content)[0] == 'p')
			execute_p(astack, bstack, inst->content);
		else if (((char *)inst->content)[0] == 'r')
			execute_r(astack, bstack, inst->content);
		inst = inst->next;
	}
}
