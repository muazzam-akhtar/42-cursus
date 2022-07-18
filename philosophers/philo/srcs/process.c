/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:21 by makhtar           #+#    #+#             */
/*   Updated: 2022/03/09 11:22:02 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	count_of_meals(t_philo *philo)
{
	int	flag;
	int	i;

	if ((philo->total_meals != -1) && (philo->max_meals > 0))
	{
		flag = 1;
		i = -1;
		while (++i < philo->philo)
			if (philo[i].total_meals < philo[i].max_meals)
				flag = 0;
		if (flag == 1)
		{
			i = 0;
			while (i < philo[i].philo)
			{
				philo[i].stop = 1;
				i++;
			}
			return (1);
		}
	}
	return (0);
}

void	died_philo(t_philo *philo, int i)
{
	philo->dead = 1;
	pthread_mutex_lock(&philo->locked);
	printf("%s%ld %d died\033[0m\n", RED, ft_time() - philo->start_time,
		philo[i].philo_id + 1);
	pthread_mutex_unlock(&philo->locked);
	i = 0;
	while (i < philo[i].philo)
	{
		philo[i].stop = 1;
		i++;
	}
}

void	*monitor(void *arg)
{
	t_philo		*philo;
	long int	cur_t;
	int			i;

	philo = (t_philo *)arg;
	i = 0;
	while (!philo[i].stop)
	{
		i = -1;
		while (++i < philo->philo)
		{
			cur_t = ft_time();
			if (cur_t - philo[i].time_of_last_meal > philo[i].limit_of_life)
			{
				died_philo(philo, i);
				pthread_mutex_unlock(&philo->locked);
				pthread_mutex_unlock(philo->l_f);
				pthread_mutex_unlock(philo->r_f);
				return (NULL);
			}
		}
		if (count_of_meals(philo) || philo->stop)
			return (NULL);
	}
	return (NULL);
}

void	*process(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->time_of_last_meal = ft_time();
	philo->start_time = ft_time();
	while (!philo->dead)
	{
		if (philo->dead || philo->stop || count_of_meals(philo))
			return (NULL);
		grabbing_forks(philo);
		if (philo->dead || philo->stop || count_of_meals(philo))
			return (NULL);
		eating(philo);
		if (philo->dead || philo->stop || count_of_meals(philo))
			return (NULL);
		sleeping(philo);
		if (philo->dead || philo->stop || count_of_meals(philo))
			return (NULL);
		thinking(philo);
		if (philo->dead || philo->stop || count_of_meals(philo))
			return (NULL);
	}
	return (NULL);
}
