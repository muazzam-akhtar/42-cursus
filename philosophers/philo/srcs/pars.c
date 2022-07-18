/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:15 by makhtar           #+#    #+#             */
/*   Updated: 2022/03/10 11:58:43 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_error(void)
{
	printf("%s*************************************%s\n", RED, FORMAT);
	printf("%s*            Error                  *%s\n", RED, FORMAT);
	printf("%s*************************************%s\n", RED, FORMAT);
	printf("%s* [1]    Executable File            *%s\n", RED, FORMAT);
	printf("%s* [2]    Number of Philosophers     *%s\n", RED, FORMAT);
	printf("%s* [3]    Time to die                *%s\n", RED, FORMAT);
	printf("%s* [4]    Time to eat                *%s\n", RED, FORMAT);
	printf("%s* [5]    Time to sleep              *%s\n", RED, FORMAT);
	printf("%s* [6]    Number of meals (Optional) *%s\n", RED, FORMAT);
	printf("%s*************************************%s\n", RED, FORMAT);
}

void	ft_init(t_arg *arg)
{
	arg->meals = 0;
	arg->n_philos = 0;
	arg->time_to_die = 0;
	arg->time_to_eat = 0;
	arg->time_to_sleep = 0;
}

int	pars_arg(int ac, char **av, t_arg *arg)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
	{
		ft_error();
		exit(1);
	}
	while (av[i])
	{
		if (!ft_isdigit(av[i]) || !ft_atoi(av[i]))
			exit (printf("%sInvalid Argument%s\n", RED, FORMAT));
		i++;
	}
	ft_init(arg);
	return (0);
}
