/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:18 by makhtar           #+#    #+#             */
/*   Updated: 2022/03/09 11:21:33 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	file_check(char *str)
{
	if (!ft_strcmp(ft_strchr(str, 'p'), "philo"))
		return (0);
	exit (printf("\033[1;31mExecutable file must be named philo\033[0m\n"));
}

static void	end_threads(t_arg *arg)
{
	int	philos;

	philos = arg->n_philos;
	if (philos == 1)
		pthread_mutex_unlock(&arg->forks[0]);
	while (philos)
	{
		philos--;
		pthread_join(arg->tids[philos], NULL);
	}
}

static void	destroy_mutex(t_arg *arg)
{
	int	philos;

	philos = arg->n_philos;
	while (philos--)
	{
		pthread_mutex_unlock(&arg->forks[philos]);
		pthread_mutex_destroy(&arg->forks[philos]);
	}
	pthread_mutex_unlock(&arg->locked);
	pthread_mutex_unlock(&arg->locked);
	pthread_mutex_destroy(&arg->locked);
}

static void	free_all(t_arg *arg)
{
	free(arg->forks);
	free(arg->philo);
	free(arg->tids);
}

int	main(int ac, char **av)
{
	t_arg	arg;

	if (file_check(av[0]))
		return (1);
	if (pars_arg(ac, av, &arg))
		return (2);
	if (init_arg(ac, av, &arg))
		return (3);
	init_mutex(&arg);
	init_philo(&arg);
	init_threads(&arg);
	end_threads(&arg);
	destroy_mutex(&arg);
	free_all(&arg);
}
