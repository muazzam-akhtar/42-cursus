/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:49:18 by makhtar           #+#    #+#             */
/*   Updated: 2021/11/04 11:49:18 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags1(char **format, t_flags *flags)
{
	while (**format == ' ' || **format == '#' || **format == '-'
		|| **format == '+' || **format == '0')
	{
		parse_flags2(format, flags);
		if (**format == '0')
			flags->zero_pad = 1;
		else if (**format == ' ')
			flags->space = 1;
		else if (**format == '-')
			flags->dash = 1;
		(*format)++;
	}
	while (**format >= '0' && **format <= '9')
	{
		flags->width = (flags->width * 10) + (**format - '0');
		(*format)++;
	}
	if (flags->dash > 0 && flags->zero_pad > 0)
		flags->zero_pad = 0;
	if (flags->space > 0 && flags->zero_pad > 0)
		flags->space = 0;
	if (flags->dash == 0 && flags->zero_pad == 0 && flags->width > 0)
		flags->space = 1;
}

void	work_flags(t_flags *flags)
{
	if (flags->space > 0 || flags->dash > 0)
		work_flags_space(flags);
	else if (flags->zero_pad > 0)
	{
		if (flags->width >= flags->prec_length
			&& flags->prec_length > flags->data_len)
		{
			flags->zero_length = flags->width - flags->prec_length;
			flags->zero_length = flags->width - flags->plus;
		}
		else if (flags->data_len >= flags->prec_length)
			flags->zero_length = flags->width - flags->data_len;
		print_zero(flags);
	}
}

long long int	plus_flag(long long int num, t_flags *flags)
{
	if (num >= 0)
	{
		if (flags->plus > 0)
			ft_putchar('+', flags);
		else if (flags->space > 0)
			ft_putchar(' ', flags);
		if ((flags->space > 0 && flags->width > 0)
			|| (flags->plus > 0 && flags->width > 0))
			flags->data_len--;
	}
	else if (num < 0)
	{
		ft_putchar('-', flags);
		if (flags->dash == 0 || (flags->prec_length >= flags->data_len))
		{
			if (flags->zero_pad > 0)
				flags->zero_pad = 1;
			else
				flags->data_len--;
		}
		num = -num;
	}
	return (num);
}

void	hash_flag(t_flags *flags)
{
	if (flags->hash > 0)
	{
		if (flags->spec == 'X')
			ft_putstr("0X", flags);
		else if (flags->spec == 'x')
			ft_putstr("0x", flags);
	}
	if (flags->spec == 'p')
		ft_putstr("0x", flags);
}

void	work_flags_dec(long long int num, t_flags *flags)
{
	if (num < 0 && flags->width && flags->prec_length
		&& flags->width > flags->prec_length
		&& flags->prec_length == flags->data_len)
		work_flags_dpn(num, flags);
	else
	{
		if (flags->space > 0 && flags->dash == 0)
			dec_sp(num, flags);
		num = plus_flag(num, flags);
		if (num != 0 || flags->prec_length > 0)
		{
			if (flags->prec_length > flags->width)
			{
				flags->zero_length = flags->prec_length - flags->data_len;
				print_zero(flags);
			}
			else
				work_precision(flags);
		}
		if (flags->dash > 0)
			dec_dash(num, flags);
		else
			dec_flags(num, flags);
	}
}
