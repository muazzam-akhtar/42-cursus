/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:26:05 by makhtar           #+#    #+#             */
/*   Updated: 2022/01/24 17:26:05 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_counts(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (ft_atoi(str) >= -2147483648 && ft_atoi(str) <= 2147483647)
			count++;
		if (!ft_strchr(str, ' '))
			break ;
		str = ft_strchr(str, ' ');
		++str;
	}
	return (count);
}

static int	get_nums(char *str, long int *stack_a)
{
	while (*str)
	{
		if ((*str >= '0' && *str <= '9') || (*str == '-') || (*str == '+'))
		{
			if ((ft_atoi(str) >= -2147483648) && (ft_atoi(str) <= 2147483647))
			{
				if (stack_a[0] == EOA)
					stack_a[0] = ft_atoi(str);
				else
					stack_append(stack_a, ft_atoi(str));
			}
		}
		if (!ft_strchr(str, ' '))
			break ;
		str = ft_strchr(str, ' ');
		++str;
	}
	return (1);
}

int	get_size(int ac, char **argv)
{
	char	*str;
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (ac == 2)
	{
		str = ft_strdup(argv[1]);
		count = get_counts(str);
		free (str);
	}
	else if (ac > 2)
	{
		while (argv[i + 1])
		{
			if ((ft_atoi(argv[i + 1]) >= -2147483648)
				&& (ft_atoi(argv[i + 1]) <= 2147483647))
			{
				count++;
				i++;
			}
		}
	}
	return (count);
}

int	init_stack_a(long int *stack_a, int ac, char **argv)
{
	int			i;
	char		*str;

	i = 0;
	if (ac == 2)
	{
		str = ft_strdup(argv[1]);
		get_nums(str, stack_a);
		free(str);
	}
	else if (ac > 2)
	{
		while (argv[i + 1])
		{
			get_nums(argv[i + 1], stack_a);
			i++;
		}
	}
	return (1);
}
