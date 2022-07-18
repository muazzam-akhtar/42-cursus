/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:52 by makhtar           #+#    #+#             */
/*   Updated: 2022/03/05 15:19:53 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
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

void	ft_sleep(int ms)
{
	long	time;

	time = ft_time();
	usleep(ms * 920);
	while (ft_time() < time + ms)
		usleep(ms * 3);
}

void	ft_print(char *str, char *color, t_arg *arg)
{
	printf("%s%ld %d %s%s\n", color, ft_time() - arg->start_time,
		arg->philo.philo_id + 1, str, FORMAT);
}
