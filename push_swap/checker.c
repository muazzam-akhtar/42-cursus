/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:25:47 by makhtar           #+#    #+#             */
/*   Updated: 2022/01/24 17:25:47 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static int	file_checker(char **str)
{
	if (!(ft_strcmp(ft_strchr(str[0], 'c'), "checker")))
		return (1);
	return (0);
}

static void	ft_initialise(t_info *info)
{
	info->size = 0;
	info->end = 0;
	info->start = 0;
	info->max = 0;
	info->min = 0;
	info->s_max = 0;
	info->moves = 0;
	info->length = 0;
	info->bonus = 1;
}

static void	checker_operations(long int *stack_a,
			long int *stack_b, t_info *info)
{
	char	*str;
	int		i;

	str = get_next_line(0);
	while (str)
	{
		i = 0;
		while (str[i] != '\n')
			i++;
		str[i] = '\0';
		do_op(str, stack_a, stack_b, info);
		free(str);
		str = get_next_line(0);
	}
	free(str);
}

static void	dup_error(long int *stack)
{
	if (!check_dup(stack))
	{
		ft_putendl_fd("Error", 1);
		exit(1);
	}
}

int	main(int ac, char **argv)
{
	long int	*stack_a;
	long int	*stack_b;
	t_info		info;

	ft_initialise(&info);
	if (ac == 1 && file_checker(argv))
		return (0);
	if (ac >= 2 && (file_checker(argv)))
	{
		info.size = get_size(ac, argv);
		stack_a = ft_allocate(&info);
		stack_b = ft_allocate(&info);
		init_stack_a(stack_a, ac, argv);
		dup_error(stack_a);
		checker_operations(stack_a, stack_b, &info);
		if ((sort_asc(stack_a)) && (!stack_size(stack_b)))
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 1);
	}
	else
		ft_putendl_fd("Error", 1);
	return (0);
}
