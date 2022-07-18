/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:25:52 by makhtar           #+#    #+#             */
/*   Updated: 2022/01/24 17:25:52 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	non_push_strategy(long int *stack_a, t_info *info)
{
	if (stack_a[3] < stack_a[4])
	{
		rra(stack_a, info);
		rra(stack_a, info);
		if (stack_size(stack_a) == 5)
			rra(stack_a, info);
	}
	else if (stack_a[3] > stack_a[4])
	{
		rra(stack_a, info);
		rra(stack_a, info);
		sa(stack_a, info);
		rra(stack_a, info);
	}
}

static long int	*filling_stack_b(long int *stack_a, t_info *info)
{
	int			pushed;
	long int	*stack_b;

	pushed = stack_size(stack_a) - 3;
	stack_b = ft_allocate(info);
	while (pushed > 0)
	{
		if ((stack_last(stack_a) != info->min)
			&& (stack_last(stack_a) != info->max)
			&& (stack_last(stack_a) != info->s_max))
			rra(stack_a, info);
		else if (stack_a[0] == info->min || stack_a[0] == info->max
			|| stack_a[0] == info->s_max)
			ra(stack_a, info);
		else if (stack_a[0] != EOA)
		{
			pb(stack_a, stack_b, info);
			pushed--;
		}
	}
	return (stack_b);
}

static void	sort_stack_a_asc(long int *stack_a, long int *stack_b, t_info *info)
{
	if (sort_desc(stack_a))
	{
		if (!ss(stack_a, stack_b, info))
			sa(stack_a, info);
	}
	else if (sort_asc(stack_a))
		rr(stack_a, stack_b, info);
	else if (stack_a[1] == info->min && stack_a[2] == info->max)
	{
		rra(stack_a, info);
		if (!ss(stack_a, stack_b, info))
			sa(stack_a, info);
	}
	else if ((stack_a[0] == info->min) && (stack_a[1] == info->max))
	{
		ra(stack_a, info);
		if (!ss(stack_a, stack_b, info))
			sa(stack_a, info);
	}
	else if (stack_a[1] == info->min && stack_a[0] == info->max)
		rra(stack_a, info);
}

static void	sort_stack_a_desc(long int *stack_a, t_info *info)
{
	if (sort_desc(stack_a))
		sa(stack_a, info);
	else if (sort_asc(stack_a))
		ra(stack_a, info);
	else if ((stack_a[0] == info->max) && (stack_a[2] == info->s_max))
		rra(stack_a, info);
	else if ((stack_a[0] == info->s_max) && (stack_a[2] == info->max))
	{
		rra(stack_a, info);
		sa(stack_a, info);
	}
	else if ((stack_a[0] == info->min) && (stack_a[1] == info->max))
	{
		ra(stack_a, info);
		sa(stack_a, info);
	}
}

void	five_sort(long int *stack_a, t_info *info)
{
	long int	*stack_b;

	info->max = find_max(stack_a);
	info->min = find_min(stack_a);
	info->s_max = find_second_max(stack_a, info->max);
	if (!sort_asc(stack_a))
	{
		if (stack_a[0] == info->s_max && stack_a[1] == info->max
			&& stack_a[2] == info->min)
			non_push_strategy(stack_a, info);
		else
		{
			stack_b = filling_stack_b(stack_a, info);
			if (sort_asc(stack_b))
				sort_stack_a_asc(stack_a, stack_b, info);
			else if (sort_desc(stack_b))
				sort_stack_a_desc(stack_a, info);
			if (!sort_desc(stack_b))
				sb(stack_b, info);
			while (stack_b[0] != EOA)
				pa(stack_a, stack_b, info);
			rra(stack_a, info);
		}
	}
}
