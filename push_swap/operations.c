/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:26:30 by makhtar           #+#    #+#             */
/*   Updated: 2022/01/24 17:26:30 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(long int *stack_a, t_info *info)
{
	long int	tmp;

	if (stack_size(stack_a) >= 2)
	{
		tmp = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = tmp;
		if (!info->bonus)
			ft_putendl_fd("sa", 1);
		info->moves++;
		return (1);
	}
	return (0);
}

int	sb(long int *stack_b, t_info *info)
{
	long int	tmp;

	if (stack_size(stack_b) >= 2)
	{
		tmp = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = tmp;
		if (!info->bonus)
			ft_putendl_fd("sb", 1);
		info->moves++;
		return (1);
	}
	return (0);
}

int	ss(long int *stack_a, long int *stack_b, t_info *info)
{
	long int	tmp;

	if ((stack_size(stack_a) >= 2) && (stack_size(stack_b) >= 2))
	{
		tmp = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = tmp;
		tmp = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = tmp;
		info->moves++;
		if (!info->bonus)
			ft_putendl_fd("ss", 1);
		return (1);
	}
	return (0);
}

int	pb(long int *stack_a, long int *stack_b, t_info *info)
{
	long int	*new_stack_b;
	long int	*new_stack_a;

	if (stack_a[0] != EOA)
	{
		new_stack_b = ft_allocate(info);
		new_stack_a = ft_allocate(info);
		new_stack_b[0] = stack_a[0];
		new_stack(new_stack_b, stack_b, 1);
		new_stack(new_stack_a, stack_a, 2);
		new_stack(stack_b, new_stack_b, 0);
		new_stack(stack_a, new_stack_a, 0);
		if (!info->bonus)
			ft_putendl_fd("pb", 1);
		info->moves++;
		free(new_stack_b);
		free(new_stack_a);
		return (1);
	}
	return (0);
}

int	pa(long int *stack_a, long int *stack_b, t_info *info)
{
	long int	*new_stack_b;
	long int	*new_stack_a;

	if (stack_b[0] != EOA)
	{
		new_stack_a = ft_allocate(info);
		new_stack_b = ft_allocate(info);
		new_stack_a[0] = stack_b[0];
		new_stack(new_stack_a, stack_a, 1);
		new_stack(new_stack_b, stack_b, 2);
		new_stack(stack_b, new_stack_b, 0);
		new_stack(stack_a, new_stack_a, 0);
		if (!info->bonus)
			ft_putendl_fd("pa", 1);
		info->moves++;
		free(new_stack_b);
		free(new_stack_a);
		return (1);
	}
	return (0);
}
