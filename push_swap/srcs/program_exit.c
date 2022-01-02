/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:16:35 by jinbekim          #+#    #+#             */
/*   Updated: 2021/05/30 18:16:35 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 7);
	exit(1);
}

void	print_exit(t_list *inst)
{
	if (inst == NULL)
		exit(0);
	while (inst)
	{
		ft_putstr_fd((char *)inst->content, 1);
		ft_putchar_fd('\n', 1);
		inst = inst->next;
	}
	exit(0);
}
