/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_chunk_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:16:25 by jinbekim          #+#    #+#             */
/*   Updated: 2021/05/30 18:16:26 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_chunk_num(t_list *stack, int size)
{
	int	times;

	times = size;
	if (size == 0)
		times = 1;
	while (times--)
	{
		stack->chunk_num = size;
		stack = stack->next;
	}
}
