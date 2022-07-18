/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materials.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:12 by makhtar           #+#    #+#             */
/*   Updated: 2022/03/09 10:31:56 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isdigit(char *str)
{
	if ((str[0] >= '0' && str[0] <= '9') || str[0] == '+')
		return (1);
	return (0);
}

int	ft_even(int n)
{
	if (n % 2 == 0)
		return (1);
	return (0);
}

long int	ft_time(void)
{
	struct timeval	tv;
	long			res;

	gettimeofday(&tv, NULL);
	res = 1000 * (size_t)tv.tv_sec + (size_t)tv.tv_usec / 1000;
	return (res);
}

void	duration(int milliseconds)
{
	long	time;

	time = ft_time();
	usleep(milliseconds * 920);
	while (ft_time() < time + milliseconds)
		usleep(milliseconds * 3);
}

void	ft_print(t_philo *philo, char *str, char *color)
{
	printf("%s%ld %d %s%s\n", color, ft_time() - philo->start_time,
		philo->philo_id + 1, str, FORMAT);
}
