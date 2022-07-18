/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:24 by makhtar           #+#    #+#             */
/*   Updated: 2022/03/09 10:30:29 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (0);
}

static void	max_length_error(int *length)
{
	if (*length >= 20)
	{
		printf("\033[1;31mInvalid Argument\033[0m\n");
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
	printf("\033[1;31mInvalid Argument\033[0m\n");
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
