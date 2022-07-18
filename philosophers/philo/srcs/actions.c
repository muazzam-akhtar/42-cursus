/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:03 by makhtar           #+#    #+#             */
/*   Updated: 2022/03/05 15:19:04 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	grabbing_forks_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->l_f);
	pthread_mutex_lock(philo->r_f);
	pthread_mutex_lock(&philo->locked);
	if (philo->stop != 1)
	{
		ft_print(philo, "has taken a fork", GREEN);
		ft_print(philo, "has taken a fork", GREEN);
	}
	pthread_mutex_unlock(&philo->locked);
}

void	grabbing_forks(t_philo *philo)
{
	if ((ft_even(philo->philo_id)) && (philo->philo_id + 1 != philo->philo))
	{
		pthread_mutex_lock(philo->r_f);
		pthread_mutex_lock(philo->l_f);
		pthread_mutex_lock(&philo->locked);
		if (philo->stop != 1)
		{
			ft_print(philo, "has taken a fork", GREEN);
			ft_print(philo, "has taken a fork", GREEN);
		}
		pthread_mutex_unlock(&philo->locked);
	}
	else
		grabbing_forks_odd(philo);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->locked);
	ft_print(philo, "is eating", NAVY);
	pthread_mutex_unlock(&philo->locked);
	philo->total_meals++;
	philo->time_of_last_meal = ft_time();
	duration(philo->time_to_eat);
	pthread_mutex_unlock(philo->l_f);
	pthread_mutex_unlock(philo->r_f);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->locked);
	ft_print(philo, "is sleeping", YELLOW);
	pthread_mutex_unlock(&philo->locked);
	duration(philo->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->locked);
	ft_print(philo, "is thinking", BLUE);
	pthread_mutex_unlock(&philo->locked);
}
