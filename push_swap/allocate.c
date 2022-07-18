/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:25:38 by makhtar           #+#    #+#             */
/*   Updated: 2022/01/24 17:25:38 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	*ft_allocate(t_info *info)
{
	int			i;
	int			size;
	long int	*stack;

	i = 0;
	size = info->size + 1;
	stack = ft_calloc(info->size + 1, sizeof(long int));
	while (i < size)
	{
		stack[i] = EOA;
		i++;
	}
	return (stack);
}

void	look_num_asc(long int *num, long int *stack, t_info *info)
{
	int	i;

	i = 0;
	while (stack[i] != EOA)
	{
		if ((*num < find_min(stack)) || (*num > find_max(stack)))
		{
			info->start = stack[0];
			break ;
		}
		else if (*num < stack[i])
		{
			info->start = stack[i];
			break ;
		}
		i++;
	}
}

int	locator(long int *stack, long int *num)
{
	int	i;

	i = 0;
	while ((stack[i] != *num) && (stack[i] != EOA))
		i++;
	return (i);
}

void	array_duplicate(long int *new_stack, long int *old_stack, int *i)
{
	while (old_stack[(*i)] != EOA)
	{
		new_stack[(*i)] = old_stack[(*i)];
		(*i)++;
	}
}

int	check_dup(long int *stack)
{
	long int	num;
	int			i;
	int			j;
	int			trigger;

	j = 1;
	num = stack[0];
	while (num != EOA)
	{
		trigger = 0;
		i = 0;
		while (stack[i] != EOA)
		{
			if (num == stack[i])
				trigger++;
			if (trigger > 1)
				return (0);
			i++;
		}
		num = stack[j];
		j++;
	}
	return (1);
}
