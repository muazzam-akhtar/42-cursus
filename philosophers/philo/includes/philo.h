/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:09:17 by makhtar           #+#    #+#             */
/*   Updated: 2022/03/05 15:26:51 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define FORMAT "\033[0m"
# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define GREEN "\033[1;32m"
# define BLUE "\033[1;34m"
# define NAVY "\033[1;36m"

struct	s_arg;

typedef struct s_philo
{
	int				philo_id;
	int				total_meals;
	int				max_meals;
	time_t			time_of_last_meal;
	int				philo;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	time_t			limit_of_life;
	int				stop;
	int				dead;
	time_t			start_time;
	pthread_mutex_t	locked;
	pthread_mutex_t	*l_f;
	pthread_mutex_t	*r_f;
}				t_philo;

typedef struct s_arg
{
	int				n_philos;
	int				philo_id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals;
	time_t			start_time;
	pthread_mutex_t	*forks;
	pthread_t		*tids;
	pthread_mutex_t	locked;
	t_philo			*philo;
}				t_arg;

int			ft_strcmp(char *s1, char *s2);
char		*ft_strchr(const char *str, int c);
int			ft_isdigit(char *str);
long int	ft_atoi(const char *str);
int			ft_even(int n);
long int	ft_time(void);
void		duration(int milliseconds);
void		ft_print(t_philo *philo, char *str, char *color);

int			pars_arg(int ac, char **av, t_arg *arg);
int			init_arg(int ac, char **av, t_arg *arg);
void		init_mutex(t_arg *arg);
void		init_philo(t_arg *arg);

void		grabbing_forks(t_philo *philo);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);

int			count_of_meals(t_philo *philo);
void		died_philo(t_philo *philo, int i);
void		*monitor(void *arg);
void		*process(void *arg);
void		init_threads(t_arg *arg);

#endif