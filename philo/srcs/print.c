#include "philo.h"

int	print(t_philo* philo, const char* msg)
{
	struct timeval	now;
	uint64_t		time;

	gettimeofday(&now, NULL);
	time = (now.tv_sec * 1000) + (now.tv_usec) / 1000;
	time -= (philo->start_time->tv_sec) * 1000 + (philo->start_time->tv_usec) / 1000;
	pthread_mutex_lock(philo->printer);
	printf("%llums %d %s\n", time, philo->id, msg);
	if (!strcmp(msg, "died."))
		return (1);
	pthread_mutex_unlock(philo->printer);
	return (0);
}
