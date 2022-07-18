/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:27:10 by makhtar           #+#    #+#             */
/*   Updated: 2022/01/24 17:27:11 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	top_rotations(long int *stack_a, long int *stack_b, t_info *info)
{
	while (stack_b[0] != info->end || stack_a[0] != info->start)
	{
		if (stack_a[0] == info->start)
			rb(stack_b, info);
		else if (stack_b[0] == info->end)
			ra(stack_a, info);
		else if (!rr(stack_a, stack_b, info))
			rb(stack_b, info);
	}
}

static void	bottom_rotations(long int *stack_a, long int *stack_b, t_info *info)
{
	while (stack_b[0] != info->end || stack_a[0] != info->start)
	{
		if (stack_a[0] == info->start)
			rrb(stack_b, info);
		else if (stack_b[0] == info->end)
			rra(stack_a, info);
		else if (!rrr(stack_a, stack_b, info))
			rrb(stack_b, info);
	}
}

static void	custom_rotations(long int *stack_a, long int *stack_b, t_info *info)
{
	while ((stack_b[0] != info->end) || (stack_a[0] != info->start))
	{
		if (stack_a[0] != info->start)
			ra(stack_a, info);
		else if (stack_b[0] != info->end)
			rrb(stack_b, info);
	}
}

static void	inverse_rotations(long int *stack_a, long int *stack_b,
			t_info *info)
{
	while ((stack_a[0] != info->start) || (stack_b[0] != info->end))
	{
		if (stack_a[0] != info->start)
			rra(stack_a, info);
		else if (stack_b[0] != info->end)
			rb(stack_b, info);
	}
}

void	rotations(long int *stack_a, long int *stack_b, t_info *info)
{
	if ((locator(stack_b, &info->end) <= (stack_size(stack_b) / 2))
		&& (locator(stack_a, &info->start) <= (stack_size(stack_a) / 2)))
		top_rotations(stack_a, stack_b, info);
	else if ((locator(stack_b, &info->end) > (stack_size(stack_b) / 2))
		&& (locator(stack_a, &info->start) > (stack_size(stack_a) / 2)))
		bottom_rotations(stack_a, stack_b, info);
	else if ((locator(stack_b, &info->end) > (stack_size(stack_b) / 2))
		&& (locator(stack_a, &info->start) <= (stack_size(stack_a) / 2)))
		custom_rotations(stack_a, stack_b, info);
	else if ((locator(stack_b, &info->end) <= (stack_size(stack_b) / 2))
		&& (locator(stack_a, &info->start) > (stack_size(stack_a) / 2)))
		inverse_rotations(stack_a, stack_b, info);
}
