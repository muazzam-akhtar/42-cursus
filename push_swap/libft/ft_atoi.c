/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:14:30 by makhtar           #+#    #+#             */
/*   Updated: 2021/10/04 12:14:33 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	max_length_error(int *length)
{
	if (*length >= 20)
	{
		ft_putendl_fd("Error", 1);
		exit(1);
	}
}

static long int	ft_atoi_atoi(char *str, int sign, int *length)
{
	int			i;
	long int	nbr;

	i = 0;
	nbr = 0;
	if ((str[i] >= '0') && (str[i] <= '9'))
	{
		while ((str[i] >= '0') && (str[i] <= '9'))
		{
			nbr = (nbr * 10) + (str[i] - '0');
			i++;
			(*length)++;
		}
		max_length_error(length);
		nbr = nbr * sign;
		if (str[i] == '\0' || str[i] == ' ')
		{
			if (nbr >= -2147483648 && nbr <= 2147483647)
				return (nbr);
		}
	}
	ft_putendl_fd("Error", 1);
	exit (1);
}

long int	ft_atoi(const char *str)
{
	int		i;
	long	nbr;
	char	*s;
	int		sign;
	int		length;

	i = 0;
	length = 0;
	s = (char *)str;
	sign = 1;
	while (s[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
		length++;
	}
	nbr = ft_atoi_atoi(&s[i], sign, &length);
	return (nbr);
}
