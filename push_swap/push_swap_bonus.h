/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 20:20:19 by jinbekim          #+#    #+#             */
/*   Updated: 2021/05/30 20:20:20 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft.h"

void	error_exit(void);
void	print_exit(t_list *inst);
int		examine_sort(t_list *astack);
void	input_inst(t_list **inst);
void	input_stack(char **av, t_list **astack);
void	execute_inst(t_list **astack, t_list **bstack, t_list *inst);
void	execute_p(t_list **astack, t_list **bstack, char *inst);
void	execute_r(t_list **astack, t_list **bstack, char *inst);
void	execute_s(t_list **astack, t_list **bstack, char *inst);
void	rate_rank(t_list *astack);
void	arrange_stack(t_list **astack, t_list **bstack, t_list **inst);
void	add_instruct_ntimes(t_list **inst, char *instruct, int n);
void	add_and_execute_inst(\
t_list **astack, t_list **bstack, t_list **inst, char *instruct);

#endif
