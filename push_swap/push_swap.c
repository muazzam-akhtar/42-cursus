/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:26:48 by makhtar           #+#    #+#             */
/*   Updated: 2022/01/24 17:26:48 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	file_check(char **argv)
{
	if (!(ft_strcmp(ft_strchr(argv[0], 'p'), "push_swap")))
		return (1);
	return (0);
}

static void	ft_init(t_info *info)
{
	info->size = 0;
	info->end = 0;
	info->start = 0;
	info->max = 0;
	info->min = 0;
	info->s_max = 0;
	info->moves = 0;
	info->length = 0;
	info->bonus = 0;
}

void	check_dup_main(long int *stack)
{
	if (!check_dup(stack))
	{
		ft_putendl_fd("Error", 1);
		exit(0);
	}
}

int	main(int ac, char **argv)
{
	long int		*stack_a;
	t_info			info;

	ft_init(&info);
	if (ac == 1 && file_check(argv))
		return (0);
	else if ((ac >= 2) && (file_check(argv)))
	{
		info.size = get_size(ac, argv);
		stack_a = ft_allocate(&info);
		init_stack_a(stack_a, ac, argv);
		check_dup_main(stack_a);
		if (stack_size(stack_a) == 2 || stack_size(stack_a) == 3)
			small_sort(stack_a, &info);
		else if (stack_size(stack_a) == 4 || stack_size(stack_a) == 5)
			five_sort(stack_a, &info);
		else if (stack_size(stack_a) > 5)
			big_sort(stack_a, &info);
		free(stack_a);
	}
	else
		ft_putendl_fd("Error", 1);
	return (0);
}
