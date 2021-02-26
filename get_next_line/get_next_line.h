/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 23:09:12 by jinbekim          #+#    #+#             */
/*   Updated: 2021/01/06 23:15:56 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# define OPEN_MAX 256

int			ft_strlen(char *s);
int			has_newline(char *backup);
int			get_next_line(int fd, char **line);
char		*ft_strdup(char *s1);
void		cut_with_newline(char **backup);
char		*ft_strjoin_free(char *s1, char *s2);
int			eof_return(int readsize, char **backup, char **line);
char		*return_line(char *backup);
#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100000
#endif
