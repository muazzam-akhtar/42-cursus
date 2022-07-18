/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:08 by makhtar           #+#    #+#             */
/*   Updated: 2022/03/05 15:26:43 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_arg(int ac, char **av, t_arg *arg)
{
	arg->n_philos = ft_atoi(av[1]);
	arg->time_to_die = ft_atoi(av[2]);
	arg->time_to_eat = ft_atoi(av[3]);
	arg->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		arg->meals = ft_atoi(av[5]);
	if (arg->n_philos > 0)
	{
		if (ac == 5)
			arg->meals = -1;
		if (ac == 6 && arg->meals < 1)
			exit (printf("%sNumber of meals is not positive%s\n", RED, FORMAT));
		return (0);
	}
	return (1);
}

void	init_mutex(t_arg *arg)
{
	int				philos;
	pthread_mutex_t	*mutex;

	philos = arg->n_philos;
	mutex = malloc(sizeof(pthread_mutex_t) * philos);
	while (philos--)
		pthread_mutex_init(&mutex[philos], NULL);
	pthread_mutex_init(&arg->locked, NULL);
	arg->forks = mutex;
}

void	init_philo(t_arg *arg)
{
	t_philo		*philo;
	int			i;
	int			philos;

	philos = arg->n_philos;
	i = 0;
	philo = malloc(sizeof(t_philo) * philos);
	while (i < philos)
	{
		philo[i].philo_id = i;
		philo[i].philo = arg->n_philos;
		philo[i].total_meals = 0;
		philo[i].max_meals = arg->meals;
		philo[i].time_to_eat = arg->time_to_eat;
		philo[i].time_to_sleep = arg->time_to_sleep;
		philo[i].time_to_die = arg->time_to_die;
		philo[i].time_of_last_meal = ft_time();
		philo[i].limit_of_life = arg->time_to_die;
		philo[i].stop = 0;
		philo[i].dead = 0;
		philo[i].l_f = &arg->forks[i];
		philo[i].r_f = &arg->forks[(i + 1) % arg->n_philos];
		i++;
	}
	arg->philo = philo;
}

void	init_threads(t_arg *arg)
{
	int			philos;
	pthread_t	*threads;
	pthread_t	s_id;

	philos = arg->n_philos;
	threads = malloc(sizeof(pthread_t) * arg->n_philos);
	while (philos--)
		pthread_create(&threads[philos], \
		NULL, process, (void *)&arg->philo[philos]);
	pthread_create(&s_id, NULL, monitor, (void *)arg->philo);
	pthread_join(s_id, NULL);
	arg->tids = threads;
}
