/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:54:48 by jinbekim          #+#    #+#             */
/*   Updated: 2020/12/21 15:58:59 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isdigit(int arg)
{
	if ('0' <= arg && arg <= '9')
		return (1);
	else
		return (0);
}