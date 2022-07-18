/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:27:01 by makhtar           #+#    #+#             */
/*   Updated: 2022/01/24 17:27:01 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_stack(long int *new_stack, long int *old_stack, int trigger)
{
	int	i;

	i = 0;
	if (trigger == 1)
	{
		while (old_stack[i] != EOA)
		{
			new_stack[i + 1] = old_stack[i];
			i++;
		}
		i += 1;
	}
	else if (trigger == 2)
	{
		while (old_stack[i + 1] != EOA)
		{
			new_stack[i] = old_stack[i + 1];
			i++;
		}
	}
	else
		array_duplicate(new_stack, old_stack, &i);
	new_stack[i] = EOA;
}

void	print_stack(long int *stack)
{
	int	i;

	i = 0;
	while (stack[i] != EOA)
	{
		ft_putstr_fd(ft_itoa(stack[i]), 1);
		ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

int	sort_desc(long int *stack)
{
	int	i;

	i = 0;
	if (stack)
	{
		while (stack[i + 1] != EOA)
		{
			if (stack[i] < stack[i + 1])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	sort_asc(long int *stack)
{
	int	i;

	i = 0;
	if (stack)
	{
		while (stack[i + 1] != EOA)
		{
			if (stack[i] > stack[i + 1])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	stack_append(long int *stack, int num)
{
	int	i;

	i = 0;
	if (stack[0] != EOA)
	{
		while (stack[i] != EOA)
			i++;
		stack[i++] = num;
		stack[i] = EOA;
		return (1);
	}
	return (0);
}
