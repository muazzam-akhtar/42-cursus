/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:54:16 by makhtar           #+#    #+#             */
/*   Updated: 2022/01/24 19:54:17 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	invalid_op(void)
{
	ft_putendl_fd("Error", 1);
	exit (1);
}

void	do_op(char *str, long int *stack_a, long int *stack_b, t_info *info)
{
	if (!ft_strcmp(str, "rra"))
		rra(stack_a, info);
	else if (!ft_strcmp(str, "rrb"))
		rrb(stack_b, info);
	else if (!ft_strcmp(str, "rrr"))
		rrr(stack_a, stack_b, info);
	else if (!ft_strcmp(str, "sa"))
		sa(stack_a, info);
	else if (!ft_strcmp(str, "sb"))
		sb(stack_b, info);
	else if (!ft_strcmp(str, "ss"))
		ss(stack_a, stack_b, info);
	else if (!ft_strcmp(str, "pa"))
		pa(stack_a, stack_b, info);
	else if (!ft_strcmp(str, "pb"))
		pb(stack_a, stack_b, info);
	else if (!ft_strcmp(str, "ra"))
		ra(stack_a, info);
	else if (!ft_strcmp(str, "rb"))
		rb(stack_b, info);
	else if (!ft_strcmp(str, "rr"))
		rr(stack_a, stack_b, info);
	else
		invalid_op();
}
