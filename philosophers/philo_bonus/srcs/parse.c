/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:46 by makhtar           #+#    #+#             */
/*   Updated: 2022/03/05 15:30:56 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static int	file_check(char *str)
{
	if (!ft_strcmp(ft_strchr(str, 'p'), "philo"))
		return (0);
	return (1);
}

static void	error_msg(void)
{
	printf("\033[1;31m*************************************\033[0m\n");
	printf("\033[1;31m*            Error                  *\033[0m\n");
	printf("\033[1;31m*************************************\033[0m\n");
	printf("\033[1;31m* [1]    Executable File            *\033[0m\n");
	printf("\033[1;31m* [2]    Number of Philosophers     *\033[0m\n");
	printf("\033[1;31m* [3]    Time to die                *\033[0m\n");
	printf("\033[1;31m* [4]    Time to eat                *\033[0m\n");
	printf("\033[1;31m* [5]    Time to sleep              *\033[0m\n");
	printf("\033[1;31m* [6]    Number of meals (Optional) *\033[0m\n");
	printf("\033[1;31m*************************************\033[0m\n");
}

int	parse_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (file_check(argv[0]))
		exit (printf("\033[1;31mExecutable file must be named philo\033[0m\n"));
	if (argc < 5 || argc > 6)
	{
		error_msg();
		exit(2);
	}
	while (argv[i])
	{
		if (!ft_isdigit(argv[i][0]) || !ft_atoi(argv[i]))
			exit(printf("\033[1;31mInvalid Argument\033[0m\n"));
		i++;
	}
	return (0);
}
