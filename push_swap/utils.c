/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:27:48 by makhtar           #+#    #+#             */
/*   Updated: 2022/01/24 17:27:48 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(long int *stack)
{
	int	i;
	int	max;

	i = 0;
	max = stack[0];
	while (stack[i] != EOA)
	{
		if (max < stack[i])
			max = (int)stack[i];
		i++;
	}
	return (max);
}

int	find_min(long int *stack)
{
	int	i;
	int	min;

	i = 0;
	min = find_max(stack);
	while (stack[i] != EOA)
	{
		if (min > stack[i])
			min = (int)stack[i];
		i++;
	}
	return (min);
}

int	find_second_max(long int *stack, int max)
{
	int	i;
	int	s_max;

	i = 0;
	if (stack[0] == max)
		s_max = stack[1];
	else
		s_max = stack[0];
	while (stack[i] != EOA)
	{
		if ((s_max < stack[i]) && ((int)stack[i] != max))
			s_max = (int)stack[i];
		i++;
	}
	return (s_max);
}

int	stack_size(long int *stack)
{
	int	i;

	i = 0;
	while (stack[i] != EOA)
		i++;
	return (i);
}

int	stack_last(long int *stack)
{
	int	i;

	i = 0;
	while (stack[i] != EOA)
		i++;
	--i;
	return ((int)stack[i]);
}
