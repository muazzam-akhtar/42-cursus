/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:27:13 by makhtar           #+#    #+#             */
/*   Updated: 2022/01/24 17:27:13 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	custom_placing(long int *stack, t_info *info)
{
	if (stack[1] == info->min && stack[2] == info->max)
		sa(stack, info);
	else if (stack[0] == info->max && stack[2] == info->min)
	{
		ra(stack, info);
		sa(stack, info);
	}
}

void	sort_three(long int *stack_a, t_info *info)
{
	info->min = find_min(stack_a);
	info->max = find_max(stack_a);
	if (sort_desc(stack_a))
	{
		ra(stack_a, info);
		sa(stack_a, info);
	}
	else if (stack_a[0] == info->min && stack_a[1] == info->max)
	{
		rra(stack_a, info);
		sa(stack_a, info);
	}
	else if (stack_a[2] == info->min && stack_a[1] == info->max)
		rra(stack_a, info);
	else if (stack_a[0] == info->max && stack_a[1] == info->min)
	{
		rra(stack_a, info);
		rra(stack_a, info);
	}
	else
		custom_placing(stack_a, info);
}

void	small_sort(long int *stack_a, t_info *info)
{
	if (stack_size(stack_a) == 2)
	{
		if (stack_a[0] > stack_a[1])
			sa(stack_a, info);
	}
	else if ((stack_size(stack_a) == 3) && !sort_asc(stack_a))
		sort_three(stack_a, info);
}
