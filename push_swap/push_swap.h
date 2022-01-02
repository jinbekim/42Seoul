/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 20:20:23 by jinbekim          #+#    #+#             */
/*   Updated: 2021/05/30 20:20:23 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

void	error_exit(void);
void	print_exit(t_list *inst);
int		examine_sort(t_list *astack);
void	execute_inst(t_list **astack, t_list **bstack, t_list *inst);
void	execute_p(t_list **astack, t_list **bstack, char *inst);
void	execute_r(t_list **astack, t_list **bstack, char *inst);
void	execute_s(t_list **astack, t_list **bstack, char *inst);
void	input_inst(t_list **inst);
void	input_stack(char **av, t_list **astack);
void	push_sorted_chunk(t_list **astack, t_list **bstack, t_list **inst);
float	calculate_avrg(t_list *stack, int chunk_num);
void	rate_rank(t_list *astack);
void	arrange_stack(t_list **astack, t_list **bstack, t_list **inst);
void	arrange_small_stack(t_list **astack, t_list **bstack, t_list **inst);
void	arrange_small_stack2(t_list **astack, t_list **bstack, t_list **inst);
void	init_chunk_num(t_list *stack, int size);
int		pb_under_avrg(\
t_list **astack, t_list **bstack, t_list **inst, float avrg);
int		pa_over_avrg(t_list **astack, t_list **bstack, t_list **inst);
void	compression_inst(t_list **inst);
void	add_instruct_ntimes(t_list **inst, char *instruct, int n);
void	add_and_execute_inst(\
t_list **astack, t_list **bstack, t_list **inst, char *instruct);

#endif
