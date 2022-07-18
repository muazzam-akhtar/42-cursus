/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:27:08 by makhtar           #+#    #+#             */
/*   Updated: 2022/01/24 17:27:08 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(long int *stack_a, t_info *info)
{
	int			i;
	long int	*n_stack;

	i = 0;
	if (stack_size(stack_a) > 1)
	{
		n_stack = ft_allocate(info);
		while (stack_a[i + 1] != EOA)
		{
			n_stack[i] = stack_a[i + 1];
			i++;
		}
		n_stack[i++] = stack_a[0];
		n_stack[i] = EOA;
		new_stack(stack_a, n_stack, 0);
		if (!info->bonus)
			ft_putendl_fd("ra", 1);
		info->moves++;
		free (n_stack);
		return (1);
	}
	return (0);
}

int	rb(long int *stack_b, t_info *info)
{
	int			i;
	long int	*n_stack;

	i = 0;
	if (stack_size(stack_b) > 1)
	{
		n_stack = ft_allocate(info);
		while (stack_b[i + 1] != EOA)
		{
			n_stack[i] = stack_b[i + 1];
			i++;
		}
		n_stack[i++] = stack_b[0];
		n_stack[i] = EOA;
		new_stack(stack_b, n_stack, 0);
		if (!info->bonus)
			ft_putendl_fd("rb", 1);
		info->moves++;
		free (n_stack);
		return (1);
	}
	return (0);
}

int	rr(long int *stack_a, long int *stack_b, t_info *info)
{
	long int	*n_stack_a;
	long int	*n_stack_b;

	if ((stack_size(stack_a) > 1) && (stack_size(stack_b) > 1))
	{
		n_stack_a = ft_allocate(info);
		n_stack_b = ft_allocate(info);
		new_stack(n_stack_a, stack_a, 2);
		stack_append(n_stack_a, (int)stack_a[0]);
		new_stack(n_stack_b, stack_b, 2);
		stack_append(n_stack_b, (int)stack_b[0]);
		new_stack(stack_a, n_stack_a, 0);
		new_stack(stack_b, n_stack_b, 0);
		if (!info->bonus)
			ft_putendl_fd("rr", 1);
		info->moves++;
		free(n_stack_b);
		free(n_stack_a);
		return (1);
	}
	return (0);
}
