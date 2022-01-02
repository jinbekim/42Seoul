#include "libasm.h"
#include "fcntl.h"
#include <string.h>

int	main(void)
{
/**----------------------------------------------------------**/
	int fd = open("./test.txt", O_RDONLY);
	char tmp[1000];
	ft_read(fd, tmp, 11);
	printf("\x1b[31m" "result ft_read : \nam i read properly? : %s\n", tmp);
	ft_read(1, tmp, 15);
	printf("%s\n" "\x1b[0m", strerror(errno));
/**----------------------------------------------------------**/
	printf("\x1b[36m" "--------------------------\n");
	ft_write(1, "result ft_write: test\n", 22);
	ft_write(-1, "ft_write: test\n", 15);
	perror("if fd == -1 :");
	printf("--------------------------" "\x1b[0m" "\n");
/**----------------------------------------------------------**/
	char s1[100] = "cpy nothing happen";
	printf("\x1b[32m" "before ft_strcpy s1 : %s\n", s1);
	char s2[100] = "cpy succeed!";
	printf("before ft_strcpy s2 :%s\n", s2);
	ft_strcpy(s1, s2);
	printf("result ft_strcpy : %s\n" "\x1b[0m", s1);
/**----------------------------------------------------------**/
	char *dup;
	char *srcc = "strdup succeed!";
	dup = ft_strdup(srcc);
	printf("\x1b[33m" "this is src ft_strdup :%s\n", srcc);
	printf("result ft_strdup :%s\n" "\x1b[0m" , dup);
/**----------------------------------------------------------**/
	int i = ft_strcmp("hi", "hi\n");
	printf("\x1b[34m" "result ft_strcmp(\"hi\", \"hi\\n\")" "\x1b[0m" ": %d\n", i);
	i = ft_strcmp("hello\n", "hello");
	printf("\x1b[34m" "result ft_strcmp(\"hello\\n\", \"hello\")" "\x1b[0m" ": %d\n", i);
	i = ft_strcmp("bye", "bye");
	printf("\x1b[34m" "result ft_strcmp(\"bye\", \"bye\")" "\x1b[0m" ": %d\n", i);
/**----------------------------------------------------------**/
	int j = ft_strlen("hi");
	printf("\x1b[35m" "result ft_strlen(\"hi\") : " "\x1b[0m" "%d\n", j);
	j = ft_strlen("hello");
	printf("\x1b[35m" "result ft_strlen(\"hello\") : " "\x1b[0m" "%d\n", j);
}
