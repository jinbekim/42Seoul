#include "philo.h"

static int			ft_isspace(int c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int			ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int					ft_atoi(const char *s)
{
	size_t			i;
	int				c;
	int				neg;

	i = 0;
	c = 0;
	neg = 1;
	if (s == NULL)
		return (0);
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			neg = -1;
		i++;
	}
	while (ft_isdigit(s[i]))
	{
		c = (c * 10) + neg * (s[i] - '0');
		i++;
	}
	return (c);
}
