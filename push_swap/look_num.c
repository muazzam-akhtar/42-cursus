/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:26:22 by makhtar           #+#    #+#             */
/*   Updated: 2022/01/24 17:26:23 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	zero_index(long int *stack, t_info *info, long int *num)
{
	if (stack[0] == find_max(stack))
	{
		if (*num > stack[0])
		{
			info->start = stack[1];
			return (1);
		}
		else if ((*num < stack[0]) && (*num > stack_last(stack)))
		{
			info->start = stack[0];
			return (1);
		}
	}
	else
	{
		if ((*num < stack[0]) && (*num > stack_last(stack)))
		{
			info->start = stack[0];
			return (1);
		}
	}
	return (0);
}

static int	min_num_manipulation(long int *stack, long int *num,
			int *i, t_info *info)
{
	if (*num < stack[(*i)])
	{
		info->start = stack[(*i)];
		return (1);
	}
	else if ((*num > stack[(*i)]) && (*num < stack[(*i) + 1]))
	{
		info->start = stack[(*i) + 1];
		return (1);
	}
	return (0);
}

static int	non_zero_index(long int *stack, t_info *info, long int *num, int *i)
{
	if (stack[*i] == find_max(stack))
	{
		if (*num > stack[*i])
		{
			info->start = stack[(*i) + 1];
			return (1);
		}
		else if ((*num < stack[(*i)]) && (*num > stack[(*i) - 1]))
		{
			info->start = stack[(*i)];
			return (1);
		}
	}
	else if (stack[(*i)] == find_min(stack))
	{
		if (min_num_manipulation(stack, num, i, info))
			return (1);
	}
	return (0);
}

static void	loop_look(long int *stack, t_info *info, long int *num)
{
	int	i;

	i = 0;
	while (stack[i] != EOA)
	{
		if (!i)
		{
			if (zero_index(stack, info, num))
				break ;
		}
		else
		{
			if (non_zero_index(stack, info, num, &i))
				break ;
			else if ((*num < stack[i]) && (*num > stack[i - 1]))
			{
				info->start = stack[i];
				break ;
			}
		}
		i++;
	}
}

void	look_num(long int *num, long int *stack, t_info *info)
{
	if (sort_asc(stack))
		look_num_asc(num, stack, info);
	else
		loop_look(stack, info, num);
}

/*void	look_num(long int *num, long int *stack, t_info *info)
{
	int	i;

	i = 0;
	if (sort_asc(stack))
		look_num_asc(num, stack, info);
	else
	{
		while (stack[i] != EOA)
		{
			if (!i)
			{
				if (stack[i] == find_max(stack))
				{
					if (*num > stack[i])
					{
						info->start = stack[i + 1];
						break ;
					}
					else if ((*num < stack[i]) && (*num > stack_last(stack)))
					{
						info->start = stack[i];
						break ;
					}
				}
				else
				{
					if ((*num < stack[i]) && (*num > stack_last(stack)))
					{
						info->start = stack[i];
						break ;
					}
				}
			}
			else
			{
				if (stack[i] == find_max(stack))
				{
					if (*num > stack[i])
					{
						info->start = stack[i + 1];
						break ;
					}
					else if ((*num < stack[i]) && (*num > stack[i - 1]))
					{
						info->start = stack[i];
						break ;
					}
				}
				else if (stack[i] == find_min(stack))
				{
					if (*num < stack[i])
					{
						info->start = stack[i];
						break ;
					}
					else if ((*num > stack[i]) && (*num < stack[i + 1]))
					{
						info->start = stack[i + 1];
						break ;
					}
				}
				else if ((*num < stack[i]) && (*num > stack[i - 1]))
				{
					info->start = stack[i];
					break ;
				}
			}
			i++;
		}
	}
}*/
