#include "philo.h"

void	ft_usleep(int sleep)
{
	struct timeval	checker;
	uint64_t		time;
	uint64_t		past;

	past = 0;
	gettimeofday(&checker, NULL);
	time = (checker.tv_sec * 1000) + (checker.tv_usec) / 1000;
	while (past < time + sleep)
	{
		gettimeofday(&checker, NULL);
		past = (checker.tv_sec * 1000) + (checker.tv_usec) / 1000;
		usleep (100);
	}
}
