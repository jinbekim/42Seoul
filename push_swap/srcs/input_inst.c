/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_inst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:08:38 by jinbekim          #+#    #+#             */
/*   Updated: 2021/05/30 18:22:17 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_inst(char *inst)
{
	if (ft_strncmp("sa", inst, 3) == 0 \
	|| ft_strncmp("sb", inst, 3) == 0 \
	|| ft_strncmp("ss", inst, 3) == 0 \
	|| ft_strncmp("pa", inst, 3) == 0 \
	|| ft_strncmp("pb", inst, 3) == 0 \
	|| ft_strncmp("ra", inst, 3) == 0 \
	|| ft_strncmp("rb", inst, 3) == 0 \
	|| ft_strncmp("rr", inst, 3) == 0 \
	|| ft_strncmp("rra", inst, 4) == 0 \
	|| ft_strncmp("rrb", inst, 4) == 0 \
	|| ft_strncmp("rrr", inst, 4) == 0)
		return (0);
	return (-1);
}

void		add_instruct_ntimes(t_list **inst, char *instruct, int n)
{
	t_list	*new;
	char	*tmp;

	while (n > 0)
	{
		tmp = ft_strdup(instruct);
		new = ft_lstnew(tmp);
		ft_lstadd_back(inst, new);
		n--;
	}
}

void		input_inst(t_list **inst)
{
	char	*instruct;
	int		readline;

	readline = 1;
	while (readline == 1)
	{
		readline = get_next_line(0, &instruct);
		if (readline == 0 && *instruct == '\0')
		{
			free(instruct);
			break ;
		}
		if (is_valid_inst(instruct) == -1)
			error_exit();
		add_instruct_ntimes(inst, instruct, 1);
		free(instruct);
	}
}
