#include "philo.h"

static int	check_alive(t_philo *philo)
{
	uint64_t		timepast;
	struct timeval	check_death;
	int				i;

	i = 0;
	while (i < philo->arg->p_num)
	{
		gettimeofday(&check_death, NULL);
		timepast = (check_death.tv_sec - philo[i].start_eat_time.tv_sec) * 1000 \
		+ (check_death.tv_usec - philo[i].start_eat_time.tv_usec) / 1000;
		if (timepast > (uint64_t)philo[i].arg->ttd)
		{
			print(&philo[i], DIE);
			return (1);
		}
		usleep(100);
		i++;
	}
	return (0);
}

static void	wait_to_die(t_philo *philo)
{
	int		p_num;
	int		i;

	i = 0;
	p_num = philo->arg->p_num;
	while (1)
	{
		if (check_alive(philo) == 1)
			break ;
	}
}

static void	wait_to_done(t_philo *philo)
{
	int		p_num;
	int		i;

	i = 0;
	p_num = philo->arg->p_num;
	while (!check_alive(philo) && i < p_num)
	{
		if (philo[i].eat_time >= philo->arg->opt)
			i++;
	}
	printf("all philosopher ate %d times\n", philo->arg->opt);
}

int	monitor_philos(t_env *env)
{
	if (env->arg->opt)
		wait_to_done(env->philo);
	else
		wait_to_die(env->philo);
	return (0);
}
