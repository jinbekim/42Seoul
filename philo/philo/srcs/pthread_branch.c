#include "philo.h"

int	pthread_branch(t_env *env)
{
	int			i;
	pthread_t	tid;

	i = 0;
	if (gettimeofday(&env->start_time, NULL) == -1)
		return (1);
	while (i < (env->arg->p_num))
	{
		if (pthread_create(&tid, NULL, routine, &(env->philo[i])) < 0)
			return (1);
		pthread_detach(tid);
		usleep(100);
		i++;
	}
	return (0);
}
