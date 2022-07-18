/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rot_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:27:04 by makhtar           #+#    #+#             */
/*   Updated: 2022/01/24 17:27:04 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	arr_dup(long int *n_stack, long int *stack)
{
	int	i;

	i = 0;
	n_stack[0] = stack_last(stack);
	while (stack[i] != stack_last(stack))
	{
		n_stack[i + 1] = stack[i];
		i++;
	}
	n_stack[i + 1] = EOA;
}

int	rra(long int *stack_a, t_info *info)
{
	int			i;
	long int	*n_stack;

	i = 0;
	if (stack_size(stack_a) > 1)
	{
		n_stack = ft_allocate(info);
		n_stack[0] = stack_last(stack_a);
		while (stack_a[i] != stack_last(stack_a))
		{
			n_stack[i + 1] = stack_a[i];
			i++;
		}
		n_stack[i + 1] = EOA;
		new_stack(stack_a, n_stack, 0);
		if (!info->bonus)
			ft_putendl_fd("rra", 1);
		info->moves++;
		free(n_stack);
		return (1);
	}
	return (0);
}

int	rrb(long int *stack_b, t_info *info)
{
	int			i;
	long int	*n_stack;

	i = 0;
	if (stack_size(stack_b) > 1)
	{
		n_stack = ft_allocate(info);
		n_stack[0] = stack_last(stack_b);
		while (stack_b[i] != stack_last(stack_b))
		{
			n_stack[i + 1] = stack_b[i];
			i++;
		}
		n_stack[i + 1] = EOA;
		new_stack(stack_b, n_stack, 0);
		if (!info->bonus)
			ft_putendl_fd("rrb", 1);
		info->moves++;
		free(n_stack);
		return (1);
	}
	return (0);
}

int	rrr(long int *stack_a, long int *stack_b, t_info *info)
{
	long int	*n_stack_a;
	long int	*n_stack_b;

	if ((stack_size(stack_b) > 1) && (stack_size(stack_a) > 1))
	{
		n_stack_a = ft_allocate(info);
		n_stack_b = ft_allocate(info);
		arr_dup(n_stack_a, stack_a);
		arr_dup(n_stack_b, stack_b);
		new_stack(stack_a, n_stack_a, 0);
		new_stack(stack_b, n_stack_b, 0);
		if (!info->bonus)
			ft_putendl_fd("rrr", 1);
		info->moves++;
		free(n_stack_a);
		free(n_stack_b);
		return (1);
	}
	return (0);
}
