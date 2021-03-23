/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 19:22:33 by jinbekim          #+#    #+#             */
/*   Updated: 2021/03/23 21:14:01 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	eof_return(int readsize, char **backup, char **line)
{
	if (!(*backup))
	{
		if (readsize == -1)
			return (readsize);
		else
			*line = ft_strdup("");
	}
	else
	{
		*line = *backup;
		*backup = NULL;
	}
	return (readsize);
}

static char	*return_line(char *backup)
{
	int		i;
	int		j;
	char	*arr;

	j = 0;
	i = has_newline(backup);
	if (!(arr = malloc(i + 1)))
		return (NULL);
	arr[i] = '\0';
	while (j < i)
	{
		arr[j] = backup[j];
		j++;
	}
	return (arr);
}

int		get_next_line(int fd, char **line)
{
	int				readsize;
	char			buff[BUFFER_SIZE + 1];
	static char		*backup[OPEN_MAX];

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0 || !line)
		return (-1);
	while (has_newline(backup[fd]) == -1)
	{
		if ((readsize = read(fd, buff, BUFFER_SIZE)) <= 0)
			return (eof_return(readsize, &backup[fd], line));
		buff[readsize] = '\0';
		if (!backup[fd])
			backup[fd] = ft_strdup(buff);
		else
			backup[fd] = ft_strjoin_free(backup[fd], buff);
	}
	*line = return_line(backup[fd]);
	cut_with_newline(&backup[fd]);
	return (1);
}
