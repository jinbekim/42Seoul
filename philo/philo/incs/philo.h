/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 09:51:31 by jinbekim          #+#    #+#             */
/*   Updated: 2021/06/25 16:53:51 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

# define ERR 1

# define FORK "has taken a fork"
# define EAT "is eating."
# define SLEEP "is sleeping"
# define THINK "is thinking."
# define DIE "died."

/*
** e_arg
** number_of_philosophers
** time_to_die
** time_to_eat
** time_to_sleep
** [number_of_times_each_philosopher_must_eat]
*/

enum			e_arg{
	P_NUM = 1,
	TTD,
	TTE,
	TTS,
	OPT
};

typedef struct	s_arg{
	int	p_num;
	int	ttd;
	int	tte;
	int	tts;
	int	opt;
	int	branch_done;
}				t_arg;

typedef struct	s_philo{
	int				id;
	int				eat_time;
	t_arg			*arg;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*printer;
	struct timeval	*start_time;
	struct timeval	start_eat_time;
}				t_philo;

typedef struct	s_env{
	t_philo			*philo;
	t_arg			*arg;
	pthread_mutex_t	*fork;
	pthread_mutex_t	printer;
	struct timeval	start_time;
}				t_env;

int				ft_atoi(const char *s);
int				set_env(t_env **env, char **av);
void			*routine(void *data);
int				pthread_branch(t_env *philo);
int				monitor_philos(t_env *philo);
int				print(t_philo* philo, const char* msg);
int				clean_table(t_env *env);
void			ft_usleep(int sleep);

#endif
