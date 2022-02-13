#include "philo.h"

static int			pick_a_fork(pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	return (0);
}

static int			drop_a_fork(pthread_mutex_t *fork)
{
	pthread_mutex_unlock(fork);
	return (0);
}

static int			eating(t_philo *philo)
{
	pick_a_fork(philo->fork_right);
	print(philo, FORK);
	pick_a_fork(philo->fork_left);
	print(philo, FORK);
	gettimeofday(&philo->start_eat_time, NULL);
	print(philo, EAT);
	ft_usleep(philo->arg->tte);
	philo->eat_time++;
	drop_a_fork(philo->fork_left);
	drop_a_fork(philo->fork_right);
	return (0);
}

void				*routine(void *data)
{
	t_philo			*philo;

	philo = data;
	gettimeofday(&philo->start_eat_time, NULL);
	while (1)
	{
		eating(philo);
		print(philo, SLEEP);
		ft_usleep(philo->arg->tts);
		print(philo, THINK);
	}
	return (NULL);
}
