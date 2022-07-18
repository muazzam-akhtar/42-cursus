/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:25:41 by makhtar           #+#    #+#             */
/*   Updated: 2022/01/24 17:25:41 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	big_sort_des(long int *stack_a, long int *stack_b, t_info *info)
{
	if (stack_a[0] == info->max)
	{
		ra(stack_a, info);
		while (stack_a[0] != info->max)
			pb(stack_a, stack_b, info);
		if (stack_size(stack_a) == 1)
		{
			while (stack_b[0] != EOA)
			{
				rrb(stack_b, info);
				pa(stack_a, stack_b, info);
			}
		}
	}
}

static void	placement(long int *stack_a, long int *stack_b, t_info *info)
{
	look_num(&info->end, stack_a, info);
	look_index(stack_a, stack_b, info, &info->end);
	rotations(stack_a, stack_b, info);
	if ((stack_a[0] == info->start) && (stack_b[0] == info->end))
		pa(stack_a, stack_b, info);
}

static void	sorting(long int *stack_a, long int *stack_b, t_info *info)
{
	int			i;
	long int	*inst;
	long int	num;

	inst = ft_allocate(info);
	while (stack_size(stack_b) > 1)
	{
		i = 0;
		while (stack_b[i] != EOA)
		{
			look_num(&stack_b[i], stack_a, info);
			inst[i] = look_index(stack_a, stack_b, info, &stack_b[i]);
			i++;
		}
		inst[i] = EOA;
		num = find_min(inst);
		info->end = stack_b[locator(inst, &num)];
		placement(stack_a, stack_b, info);
	}
	if (stack_size(stack_b) == 1)
	{
		info->end = stack_b[0];
		placement(stack_a, stack_b, info);
	}
	free(inst);
}

void	big_sort(long int *stack_a, t_info *info)
{
	long int	*stack_b;
	long int	num;

	stack_b = ft_allocate(info);
	info->max = find_max(stack_a);
	if (!sort_asc(stack_a))
	{
		if (sort_desc(stack_a))
			big_sort_des(stack_a, stack_b, info);
		else
		{
			mid_point_push(stack_a, stack_b, info);
			sorting(stack_a, stack_b, info);
			while (!sort_asc(stack_a))
			{
				num = find_min(stack_a);
				if (locator(stack_a, &num) <= (stack_size(stack_a) / 2))
					ra(stack_a, info);
				else
					rra(stack_a, info);
			}
			free(stack_b);
		}
	}
}
