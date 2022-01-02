#include "philo.h"

static int	check_argument(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (1);
	else if (
	ft_atoi(av[P_NUM]) <= 0 || ft_atoi(av[TTD]) <= 0 ||
	ft_atoi(av[TTE]) <= 0 || ft_atoi(av[TTS]) <= 0)
		return (1);
	return (0);
}

int	clean_table(t_env *env)
{
	int	i;

	i = -1;
	if (env->fork){
		while (++i < env->arg->p_num){
			pthread_mutex_unlock(&env->fork[i]);
			pthread_mutex_destroy(&env->fork[i]);
		}
		free(env->fork);
	}
	pthread_mutex_unlock(&env->printer);
	pthread_mutex_destroy(&env->printer);
	if (env->philo)
		free(env->philo);
	if (env->arg)
		free(env->arg);
	if (env)
		free(env);
	return (1);
}

int			main(int ac, char *av[])
{
	t_env	*env;

	if (check_argument(ac, av))
		return (1);
	if (set_env(&env, av))
		return (1);
	if (pthread_branch(env))
		return (1);
	monitor_philos(env);
	clean_table(env);
	return (0);
}
