#include "philo.h"

static void			*make_philo(int philo_num, t_env *env)
{
	t_philo			*philo;
	int				i;

	i = 0;
	if ((philo = malloc(philo_num * sizeof(t_philo))) == 0)
		return (0);
	while (i < philo_num)
	{
		philo[i].id = i;
		philo[i].eat_time = 0;
		philo[i].arg = env->arg;
		philo[i].start_time = &env->start_time;
		philo[i].fork_right = env->fork + i;
		philo[i].fork_left = env->fork + ((i + 1) % env->arg->p_num);
		philo[i].printer = &env->printer;
		i++;
	}
	return (philo);
}

static void			*make_mutex_fork(int philo_num)
{
	pthread_mutex_t	*fork;
	int				i;

	i = 0;
	if ((fork = malloc(sizeof(pthread_mutex_t) * philo_num)) == NULL)
		return (0);
	memset(fork, 0, sizeof(pthread_mutex_t) * philo_num);
	while (i < philo_num)
	{
		if (pthread_mutex_init(&fork[i], NULL) < 0)
			return (0);
		i++;
	}
	return (fork);
}

int					set_env(t_env **env, char **av)
{
	if (((*env) = malloc(sizeof(t_env))) == NULL)
		return (1);
	if (((*env)->arg = malloc(sizeof(t_arg))) == NULL)
		return (clean_table(*env));
	(*env)->arg->p_num = ft_atoi(av[P_NUM]);
	(*env)->arg->ttd = ft_atoi(av[TTD]);
	(*env)->arg->tte = ft_atoi(av[TTE]);
	(*env)->arg->tts = ft_atoi(av[TTS]);
	(*env)->arg->opt = ft_atoi(av[OPT]);
	if (((*env)->fork = make_mutex_fork((*env)->arg->p_num)) == NULL)
		return (clean_table(*env));
	if (pthread_mutex_init(&(*env)->printer, NULL) < 0)
		return (clean_table(*env));
	if (((*env)->philo = make_philo((*env)->arg->p_num, (*env))) == NULL)
		return (clean_table(*env));
	return (0);
}
