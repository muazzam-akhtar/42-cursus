/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:26:58 by makhtar           #+#    #+#             */
/*   Updated: 2022/01/24 17:26:58 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_info
{
	int			size;
	long int	start;
	long int	end;
	int			max;
	int			min;
	int			s_max;
	int			moves;
	int			length;
	int			bonus;
}				t_info;

# define EOA 2147483648

long int	*ft_allocate(t_info *info);
int			find_max(long int *stack);
int			find_min(long int *stack);
int			find_second_max(long int *stack, int max);
int			get_size(int ac, char **argv);
int			init_stack_a(long int *stack_a, int ac, char **argv);
int			stack_size(long int *stack);
int			stack_last(long int *stack);
void		print_stack(long int *stack);
int			stack_append(long int *stack, int num);
int			check_dup(long int *stack);
int			sa(long int *stack_a, t_info *info);
int			sb(long int *stack_b, t_info *info);
int			ss(long int *stack_a, long int *stack_b, t_info *info);
void		array_duplicate(long int *new_stack, long int *old_stack, int *i);
void		new_stack(long int *new_stack, long int *old_stack, int trigger);
int			pa(long int *stack_a, long int *stack_b, t_info *info);
int			pb(long int *stack_a, long int *stack_b, t_info *info);
int			ra(long int *stack_a, t_info *info);
int			rb(long int *stack_b, t_info *info);
int			rr(long int *stack_a, long int *stack_b, t_info *info);
int			rra(long int *stack_a, t_info *info);
int			rrb(long int *stack_b, t_info *info);
int			rrr(long int *stack_a, long int *stack_b, t_info *info);

void		do_op(char *str, long int *stack_a, long int *stack_b,
				t_info *info);
int			sort_desc(long int *stack);
int			sort_asc(long int *stack);

int			locator(long int *stack, long int *num);
void		rotations(long int *stack_a, long int *stack_b, t_info *info);

void		look_num_asc(long int *num, long int *stack, t_info *info);
void		look_num(long int *num, long int *stack, t_info *info);
long int	look_index(long int *stack_a, long int *stack_b,
				t_info *info, long int *num);

void		mid_point_push(long int *stack_a, long int *stack_b, t_info *info);

void		sort_three(long int *stack_a, t_info *info);
void		small_sort(long int *stack_a, t_info *info);
void		five_sort(long int *stack_a, t_info *info);
void		big_sort(long int *stack_a, t_info *info);

#endif