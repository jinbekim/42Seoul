/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:29:49 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/23 22:50:48 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"


void	error_handling(int errnum)
{
	perror("Error\n");
	printf("%s\n", strerror(errnum));
	exit(0);
}
