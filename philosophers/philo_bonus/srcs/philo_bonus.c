/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:49 by makhtar           #+#    #+#             */
/*   Updated: 2022/03/05 15:19:50 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static int	start_philo(t_arg *arg)
{
	int	i;

	i = 0;
	arg->start_time = ft_time();
	while (i < arg->n_philos)
	{
		arg->philo.philo_id = i;
		arg->pid_philos[i] = fork();
		if (arg->pid_philos[i] < 0)
		{
			while (--i > 0)
				kill(arg->pid_philos[i], SIGKILL);
			return (1);
		}
		else if (!arg->pid_philos[i])
		{
			init_philo(arg);
			routine(arg);
		}
		i++;
	}
	sem_wait(arg->stop);
	return (0);
}

static void	rip_philos(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->n_philos)
	{
		kill(arg->pid_philos[i], SIGKILL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_arg	arg;

	if (parse_args(argc, argv))
		return (1);
	if (init_arg(&arg, argc, argv))
		return (1);
	if (start_philo(&arg))
		return (1);
	rip_philos(&arg);
	return (0);
}
