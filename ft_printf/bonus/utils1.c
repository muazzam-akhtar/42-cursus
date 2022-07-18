/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:50:00 by makhtar           #+#    #+#             */
/*   Updated: 2021/11/04 11:50:00 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_zero(t_flags *flags)
{
	if (flags->zero_length > 0)
		while (flags->zero_length--)
			ft_putchar('0', flags);
	flags->zero_pad = 0;
}

void	print_space(t_flags *flags)
{
	if (flags->sp_length > 0)
		while (flags->sp_length--)
			ft_putchar(' ', flags);
	flags->space = 0;
}

void	work_sp_zx(t_flags *flags)
{
	if (flags->space > 0 || flags->dash > 0)
	{
		if (flags->width > flags->prec_length
			&& flags->prec_length > flags->data_len)
		{
			flags->sp_length = flags->width - flags->prec_length;
			flags->sp_length = flags->sp_length - (2 * flags->hash);
		}
		else if (flags->data_len >= flags->prec_length)
			flags->sp_length = flags->width - flags->data_len;
		print_space(flags);
	}
	else if (flags->zero_pad > 0)
	{
		if (flags->width > flags->prec_length
			&& flags->prec_length > flags->data_len)
			flags->zero_length = flags->width - flags->prec_length;
		else if (flags->data_len >= flags->prec_length)
			flags->zero_length = flags->width - flags->data_len;
		print_zero(flags);
	}
}

void	work_flags_hex(unsigned long long int num, t_flags *flags)
{
	flags->data_len = ft_hex_len(num);
	if (flags->space > 0 && flags->dash == 0)
		work_flags_ps(num, flags);
	hash_flag(flags);
	if (flags->prec_length > 0)
		work_precision(flags);
	if (flags->dash > 0)
		work_flags_pdx(num, flags);
	else
	{
		work_sp_zx(flags);
		if (flags->prec > 0)
		{
			if (flags->prec_length > 0 || num > 0)
				ft_putnbr_unx(num, flags);
		}
		else
			ft_putnbr_unx(num, flags);
	}
}

void	work_flags_cs(t_flags *flags)
{
	if (flags->prec > 0 || flags->width > flags->data_len)
	{
		if (flags->width > flags->data_len)
		{
			if (flags->space > 0 || flags->dash > 0)
			{
				flags->sp_length = flags->width - flags->data_len;
				print_space(flags);
			}
			else if (flags->zero_pad > 0)
			{
				flags->zero_length = flags->width - flags->data_len;
				print_zero(flags);
			}
		}
	}
}
