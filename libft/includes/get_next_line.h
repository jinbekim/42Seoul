/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 23:09:12 by jinbekim          #+#    #+#             */
/*   Updated: 2021/04/02 14:11:26 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define OPEN_MAX 256
# include "libft.h"

int			has_newline(char *backup);
int			get_next_line(int fd, char **line);
void		cut_with_newline(char **backup);
char		*ft_strjoin_free(char *s1, char *s2);
#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100000
#endif
