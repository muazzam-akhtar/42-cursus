/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:43 by makhtar           #+#    #+#             */
/*   Updated: 2022/03/05 15:19:44 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static void	init_semaphores(t_arg *arg)
{
	sem_unlink("forks");
	sem_unlink("activity");
	sem_unlink("stop");
	sem_unlink("eat_stop");
	arg->forks = sem_open("forks", O_CREAT | O_EXCL, S_IRWXU, arg->n_philos);
	arg->activity = sem_open("activity", O_CREAT | O_EXCL, S_IRWXU, 1);
	arg->stop = sem_open("stop", O_CREAT | O_EXCL, S_IRWXU, 0);
	if (arg->meals)
		arg->eat_stop = sem_open("eat_stop", O_CREAT | O_EXCL, S_IRWXU, 0);
}

static int	init_monitor(t_arg *arg)
{
	if (arg->meals)
	{
		if (pthread_create(&arg->monitor_tid, NULL, &eating_checker, arg))
			return (printf("Error: Failed to create a thread\n"));
		pthread_detach(arg->monitor_tid);
	}
	return (0);
}

int	init_philo(t_arg *arg)
{
	arg->philo.time_of_last_meal = ft_time();
	if (pthread_create(&arg->monitor_tid, NULL, &death_checker, arg))
		return (printf("Error: Failed to create a thread"));
	pthread_detach(arg->monitor_tid);
	return (0);
}

int	init_arg(t_arg *arg, int ac, char **av)
{
	memset(arg, 0, sizeof(t_arg));
	arg->n_philos = ft_atoi(av[1]);
	arg->time_to_die = ft_atoi(av[2]);
	arg->time_to_eat = ft_atoi(av[3]);
	arg->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		arg->meals = ft_atoi(av[5]);
	arg->pid_philos = calloc(arg->n_philos, sizeof(pid_t));
	if (ac == 5)
	{
		if (arg->n_philos < 1)
			return (0);
		arg->meals = -1;
	}
	if (ac == 6)
	{
		if (arg->meals < 1)
			return (0);
	}
	init_semaphores(arg);
	init_monitor(arg);
	return (0);
}
