/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_un.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:50:14 by makhtar           #+#    #+#             */
/*   Updated: 2021/11/04 11:50:14 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	work_flags_u1(t_flags *flags)
{
	if (flags->width > flags->prec_length
		&& flags->prec_length <= flags->data_len)
		flags->sp_length = flags->width - flags->data_len;
	else if (flags->width > flags->prec_length
		&& flags->prec_length > flags->data_len)
		flags->sp_length = flags->width - flags->prec_length;
	print_space(flags);
}

void	work_flags_ps(unsigned long long int num, t_flags *flags)
{
	if (flags->prec > 0)
	{
		if (flags->width && !flags->prec_length && !num)
		{
			flags->sp_length = flags->width;
			print_space(flags);
		}
		else if (flags->width > flags->prec_length
			&& flags->prec_length < flags->data_len)
			work_flags_u1(flags);
		else
			work_flags_u1(flags);
	}
	else
		work_flags(flags);
}

void	work_flags_pd(unsigned int num, t_flags *flags)
{
	if (flags->prec > 0)
	{
		if (flags->prec_length > 0 || num > 0)
			ft_putnbr_unx(num, flags);
		else
			flags->data_len--;
	}
	else
		ft_putnbr_unx(num, flags);
	work_flags(flags);
}

void	work_flags_pdx(unsigned long long int num, t_flags *flags)
{
	if (flags->prec > 0)
	{
		if (flags->prec_length > 0 || num > 0)
			ft_putnbr_unx(num, flags);
		else
			flags->data_len--;
	}
	else
		ft_putnbr_unx(num, flags);
	work_sp_zx(flags);
}
