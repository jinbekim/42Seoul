/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:16:28 by jinbekim          #+#    #+#             */
/*   Updated: 2021/05/30 18:25:45 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_dupl(t_list *stack, int num)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (num == *(int *)tmp->content)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

static int	check_int(char *str, int num)
{
	if (num == -1 && str[0] != '-')
		return (-1);
	if (num == 0 && str[0] != '0' && str[0] != '+')
		return (-1);
	if (str[0] == '+' && str[1] == '\0')
		return (-1);
	while (*str)
	{
		if (ft_isdigit(*str) == 0 && *str != '+' && *str != '-')
			return (-1);
		str++;
	}
	return (0);
}

void		input_stack(char **av, t_list **astack)
{
	int		i;
	int		*tmp;
	t_list	*new;

	i = 0;
	while (av[++i])
	{
		tmp = malloc(sizeof(int));
		if (tmp == NULL)
			error_exit();
		*tmp = ft_atoi(av[i]);
		if (check_int(av[i], *tmp) == -1)
			error_exit();
		if (check_dupl(*astack, *tmp) == -1)
			error_exit();
		new = ft_lstnew(tmp);
		ft_lstadd_back(astack, new);
	}
}
