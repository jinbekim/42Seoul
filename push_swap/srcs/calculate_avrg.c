/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_avrg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:16:05 by jinbekim          #+#    #+#             */
/*   Updated: 2021/05/30 18:16:05 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	calculate_avrg(t_list *stack, int chunk_num)
{
	float	sum;
	int		times;

	sum = 0;
	times = chunk_num;
	if (!stack || !chunk_num)
		return (0);
	while (times--)
	{
		sum += stack->rank;
		stack = stack->next;
	}
	return (sum / chunk_num);
}
