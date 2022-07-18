/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:26:19 by makhtar           #+#    #+#             */
/*   Updated: 2022/01/24 17:26:19 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long int	unequal_locators(long int *stack_a, long int *num,
				long int *stack_b, t_info *info)
{
	if (locator(stack_b, num) <= (stack_size(stack_b) / 2)
		&& (locator(stack_a, &info->start) > (stack_size(stack_a) / 2)))
		return ((stack_size(stack_a) - locator(stack_a, &info->start))
			+ (locator(stack_b, num) + 1));
	return ((stack_size(stack_b) - locator(stack_b, num))
		+ (locator(stack_a, &info->start)) + 1);
}

static long int	equal_locator(long int *stack_a, long int *num,
				long int *stack_b, t_info *info)
{
	if (locator(stack_b, num) == locator(stack_a, &info->start))
	{
		if (locator(stack_b, num) > (stack_size(stack_b) / 2))
			return (stack_size(stack_b) - locator(stack_b, num) + 1);
		return (locator(stack_b, num) + 1);
	}
	else if (locator(stack_b, num) > locator(stack_a, &info->start))
	{
		if (locator(stack_b, num) > (stack_size(stack_b) / 2))
		{
			if ((stack_size(stack_b) - locator(stack_b, num))
				> (stack_size(stack_a) - locator(stack_a, &info->start)))
				return (stack_size(stack_b) - locator(stack_b, num) + 1);
			return (stack_size(stack_a) - locator(stack_a, &info->start)
				+ 1);
		}
		return (locator(stack_b, num) + 1);
	}
	return (0);
}

long int	look_index(long int *stack_a, long int *stack_b,
			t_info *info, long int *num)
{
	if (((locator(stack_b, num) <= (stack_size(stack_b) / 2))
			&& (locator(stack_a, &info->start) <= (stack_size(stack_a) / 2)))
		|| ((locator(stack_b, num) > (stack_size(stack_b) / 2))
			&& (locator(stack_a, &info->start) > (stack_size(stack_a) / 2))))
	{
		if (equal_locator(stack_a, num, stack_b, info))
			return (equal_locator(stack_a, num, stack_b, info));
		else if (locator(stack_b, num) <= locator(stack_a, &info->start))
		{
			if (locator(stack_b, num) > (stack_size(stack_b) / 2))
			{
				if ((stack_size(stack_b) - locator(stack_b, num))
					> (stack_size(stack_a) - locator(stack_a, &info->start)))
					return (stack_size(stack_b) - locator(stack_b, num) + 1);
				return (stack_size(stack_a) - locator(stack_a, &info->start)
					+ 1);
			}
			return (locator(stack_a, &info->start) + 1);
		}
	}
	else
		return (unequal_locators(stack_a, num, stack_b, info));
	return (EOA);
}
