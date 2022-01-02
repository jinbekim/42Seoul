/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression_inst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:16:10 by jinbekim          #+#    #+#             */
/*   Updated: 2021/05/30 18:44:09 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_pare(t_list *tmp, char *pare)
{
	t_list	*tmp2;
	t_list	*tmp3;

	tmp2 = tmp;
	while (tmp2->next && (ft_strncmp((char *)tmp2->content, "rr", 3) == 0 \
	|| ft_strncmp((char *)tmp2->content, "ra", 3) == 0 \
	|| ft_strncmp((char *)tmp2->content, "rb", 3) == 0))
	{
		if (ft_strncmp((char *)tmp2->next->content, pare, 3) == 0)
		{
			((char *)tmp->content)[1] = 'r';
			tmp3 = tmp2->next;
			tmp2->next = tmp3->next;
			tmp3->next->prev = tmp2;
			free(tmp3->content);
			free(tmp3);
			break ;
		}
		tmp2 = tmp2->next;
	}
}

static void	find_pare3(t_list *tmp, char *pare)
{
	t_list	*tmp2;
	t_list	*tmp3;

	tmp2 = tmp;
	while (tmp2->next && (ft_strncmp((char *)tmp2->content, "rrr", 4) == 0 \
	|| ft_strncmp((char *)tmp2->content, "rra", 4) == 0 \
	|| ft_strncmp((char *)tmp2->content, "rrb", 4) == 0))
	{
		if (ft_strncmp((char *)tmp2->next->content, pare, 4) == 0)
		{
			((char *)tmp->content)[2] = 'r';
			tmp3 = tmp2->next;
			tmp2->next = tmp3->next;
			tmp3->next->prev = tmp2;
			free(tmp3->content);
			free(tmp3);
			break ;
		}
		tmp2 = tmp2->next;
	}
}

static void	change_tmp_ptr(t_list **inst, t_list **tmp, t_list *tmp2)
{
	if (tmp2->prev == NULL)
	{
		*inst = tmp2->next->next;
		(*inst)->prev = NULL;
		*tmp = *inst;
	}
	else
	{
		tmp2->prev->next = tmp2->next->next;
		if (tmp2->next->next)
			tmp2->next->next->prev = tmp2->prev;
		*tmp = tmp2->prev;
	}
}

static void	elimination(t_list **tmp, t_list **inst)
{
	char	pare[3];
	t_list	*tmp2;

	tmp2 = *tmp;
	ft_strlcpy(pare, "pa", 3);
	if (ft_strncmp((char *)tmp2->content, "pa", 3) == 0)
		ft_strlcpy(pare, "pb", 3);
	while (tmp2->next && (ft_strncmp((char *)tmp2->content, "pa", 3) == 0 \
	|| ft_strncmp((char *)tmp2->content, "pb", 3) == 0))
	{
		if (ft_strncmp((char *)tmp2->next->content, pare, 3) == 0)
		{
			free(tmp2->content);
			free(tmp2->next->content);
			change_tmp_ptr(inst, tmp, tmp2);
			free(tmp2->next);
			free(tmp2);
			break ;
		}
		tmp2 = tmp2->next;
	}
}

void		compression_inst(t_list **inst)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *inst;
	if (!tmp)
		return ;
	while (tmp->next)
	{
		tmp2 = tmp;
		if (ft_strncmp((char *)tmp->content, "p", 1) == 0)
		{
			elimination(&tmp, inst);
			if (tmp2 != tmp)
				continue ;
		}
		if (ft_strncmp((char *)tmp->content, "ra", 3) == 0)
			find_pare(tmp, "rb");
		else if (ft_strncmp((char *)tmp->content, "rb", 3) == 0)
			find_pare(tmp, "ra");
		else if (ft_strncmp((char *)tmp->content, "rra", 4) == 0)
			find_pare3(tmp, "rrb");
		else if (ft_strncmp((char *)tmp->content, "rrb", 4) == 0)
			find_pare3(tmp, "rra");
		tmp = tmp->next;
	}
}
