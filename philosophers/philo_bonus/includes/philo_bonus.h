/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:36 by makhtar           #+#    #+#             */
/*   Updated: 2022/03/05 15:19:37 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <signal.h>
# include <fcntl.h>

# define FORMAT "\033[0m"
# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define GREEN "\033[1;32m"
# define BLUE "\033[1;34m"
# define NAVY "\033[1;36m"

typedef struct s_philo
{
	pthread_t	monitor_tid;
	sem_t		*actions;
	int			philo_id;
	int			total_meals;
	time_t		time_of_last_meal;
	int			meals;
}				t_philo;

typedef struct s_arg
{
	pthread_t	monitor_tid;
	pid_t		*pid_philos;
	sem_t		*activity;
	sem_t		*forks;
	sem_t		*stop;
	sem_t		*eat_stop;
	int			n_philos;
	time_t		start_time;
	time_t		time_to_die;
	time_t		time_to_eat;
	time_t		time_to_sleep;
	int			meals;
	t_philo		philo;
}				t_arg;

int			ft_strcmp(char *s1, char *s2);
char		*ft_strchr(const char *str, int c);
int			ft_isdigit(int c);
long int	ft_atoi(const char *str);
long int	ft_time(void);
void		ft_sleep(int ms);
void		ft_print(char *str, char *color, t_arg *arg);

void		grabbing_forks_eating(t_arg *args);
void		sleeping_thinking(t_arg *args);
void		*eating_checker(void *arg);
void		*death_checker(void *arg);
void		*routine(void *arg);
int			parse_args(int argc, char **argv);
int			init_arg(t_arg *arg, int ac, char **av);
int			init_philo(t_arg *arg);

#endif