/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:27:17 by makhtar           #+#    #+#             */
/*   Updated: 2022/01/24 17:27:17 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long int	*quick_sort(long int *stack_a, t_info *info, int j)
{
	long int	*sorted;
	long int	*dup;
	int			i;

	i = 0;
	sorted = ft_allocate(info);
	dup = ft_allocate(info);
	new_stack(dup, stack_a, 0);
	while (stack_size(sorted) < stack_size(stack_a))
	{
		sorted[j] = find_min(dup);
		while (dup[i] != find_min(dup))
			i++;
		while (dup[i] != EOA)
		{
			dup[i] = dup[i + 1];
			i++;
		}
		dup[i] = EOA;
		i = 0;
		j++;
	}
	sorted[j] = EOA;
	free (dup);
	return (sorted);
}

static int	check_num(long int *stack_a, long int median)
{
	int	i;

	i = 0;
	while (stack_a[i] != EOA)
	{
		if (stack_a[i] < median)
			return (1);
		i++;
	}
	return (0);
}

void	mid_point_push(long int *stack_a, long int *stack_b, t_info *info)
{
	long int	*sorted;
	long int	median;

	while (stack_size(stack_a) > 2)
	{
		sorted = quick_sort(stack_a, info, 0);
		median = sorted[stack_size(sorted) / 2];
		while (check_num(stack_a, median))
		{
			if (stack_a[0] < median)
				pb(stack_a, stack_b, info);
			else if (stack_last(stack_a) < median)
				rra(stack_a, info);
			else
				ra(stack_a, info);
		}
		free(sorted);
		if (sort_asc(stack_a))
			break ;
	}
}
