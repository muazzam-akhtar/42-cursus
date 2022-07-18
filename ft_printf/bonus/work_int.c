/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:50:09 by makhtar           #+#    #+#             */
/*   Updated: 2021/11/04 11:50:09 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	work_flags_d1(long long int num, t_flags *flags)
{
	if ((flags->width > flags->prec_length)
		&& (flags->prec_length < flags->data_len))
	{
		if (num < 0)
			flags->sp_length = flags->width - flags->data_len;
		else if ((flags->width > flags->prec_length)
			&& (flags->prec_length < flags->data_len))
			flags->sp_length = flags->width - flags->data_len;
		else if (flags->width != flags->data_len)
			flags->sp_length = flags->width - flags->prec_length;
	}
	else
	{
		if (num < 0)
			flags->sp_length = flags->width - flags->prec_length - 1;
		else
			flags->sp_length = flags->width - flags->prec_length;
	}
	print_space(flags);
}

void	work_flags_dpn(long long int num, t_flags *flags)
{
	if (flags->prec && flags->dash
		&& flags->prec_length > 0 && flags->width > 0)
	{
		if (num < 0 && flags->prec_length == flags->data_len)
		{
			ft_putchar('-', flags);
			num = -num;
			flags->data_len--;
			work_precision(flags);
			flags->data_len = flags->data_len + 2;
			ft_putnbr_base(num, flags);
			flags->sp_length = flags->width - flags->data_len;
			print_space(flags);
			num = 0;
		}
	}
}

void	dec_sp(long long int num, t_flags *flags)
{
	if (flags->prec > 0)
	{
		if (flags->width && !flags->prec_length && !num)
		{
			flags->sp_length = flags->width;
			print_space(flags);
		}
		else
			work_flags_d1(num, flags);
	}
	if (num >= 0 && !flags->prec && !flags->width && flags->space)
		num = plus_flag(num, flags);
	work_flags(flags);
}

void	dec_dash(long long int num, t_flags *flags)
{
	if (flags->dash > 0)
	{
		if (flags->prec > 0)
		{
			if ((num != 0 && flags->prec_length > 0)
				|| (num != 0 && flags->width > 0)
				|| (flags->prec_length > flags->width))
				ft_putnbr_base(num, flags);
			else
				flags->data_len--;
		}
		else
			ft_putnbr_base(num, flags);
		if (flags->prec_length < flags->width)
			work_flags(flags);
		else if (flags->prec && flags->width > flags->prec_length)
			work_flags_d1(num, flags);
	}
}

void	dec_flags(long long int num, t_flags *flags)
{
	if (flags->width != flags->data_len && !flags->prec)
		work_flags(flags);
	if (flags->prec > 0)
	{
		if (flags->prec_length > 0 || num != 0)
			ft_putnbr_base(num, flags);
	}
	else if (flags->plus)
		ft_putnbr_base(num, flags);
	else
		ft_putnbr_base(num, flags);
}
