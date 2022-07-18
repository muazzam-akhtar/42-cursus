/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:41 by makhtar           #+#    #+#             */
/*   Updated: 2022/03/10 11:36:07 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	grabbing_forks_eating(t_arg *args)
{
	sem_wait(args->forks);
	sem_wait(args->forks);
	sem_wait(args->activity);
	ft_print("has taken a fork", GREEN, args);
	ft_print("has taken a fork", GREEN, args);
	sem_post(args->activity);
	sem_wait(args->activity);
	ft_print("is eating", NAVY, args);
	sem_post(args->activity);
	args->philo.time_of_last_meal = ft_time();
	args->philo.total_meals++;
	if (args->philo.total_meals == args->meals)
		sem_post(args->eat_stop);
	ft_sleep(args->time_to_eat);
	sem_post(args->forks);
	sem_post(args->forks);
}

void	sleeping_thinking(t_arg *args)
{
	sem_wait(args->activity);
	ft_print("is sleeping", YELLOW, args);
	sem_post(args->activity);
	ft_sleep(args->time_to_sleep);
	sem_wait(args->activity);
	ft_print("is thinking", BLUE, args);
	sem_post(args->activity);
}

void	*eating_checker(void *arg)
{
	t_arg	*args;
	int		i;

	args = (t_arg *)arg;
	i = -1;
	sem_wait(args->activity);
	while (++i < args->n_philos)
	{
		sem_post(args->activity);
		sem_wait(args->eat_stop);
		sem_wait(args->activity);
	}
	sem_post(args->stop);
	return (NULL);
}

void	*death_checker(void *arg)
{
	t_arg	*args;
	time_t	cur_t;

	args = (t_arg *)arg;
	while (1)
	{
		cur_t = ft_time();
		if (cur_t - args->philo.time_of_last_meal > args->time_to_die)
		{
			sem_wait(args->activity);
			ft_print("died", RED, args);
			sem_post(args->stop);
			sem_close(args->activity);
			sem_close(args->stop);
			sem_close(args->eat_stop);
			free(args->pid_philos);
			exit(0);
		}
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_arg	*args;

	args = (t_arg *)arg;
	args->start_time = ft_time();
	while (1)
	{
		grabbing_forks_eating(args);
		sleeping_thinking(args);
	}
	return (NULL);
}
