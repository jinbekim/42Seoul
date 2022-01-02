#ifndef LIBASM_H
# define LIBASM_H

# include <stdio.h>
# include <errno.h>
# include <unistd.h>

int     ft_strcmp(char *s1, char *s2);
int	    ft_strlen(char *src);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *src);
ssize_t	ft_write(int fd, char *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);

#endif