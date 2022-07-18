/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:49:52 by makhtar           #+#    #+#             */
/*   Updated: 2021/11/04 11:49:52 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(long long int num, t_flags *flags)
{
	if (num < 0)
	{
		ft_putchar('-', flags);
		num *= -1;
	}
	if (num >= 10)
	{
		ft_putnbr_base(num / 10, flags);
		ft_putnbr_base(num % 10, flags);
	}
	else if (num < 10)
		ft_putchar(DEC[num % 10], flags);
}

void	ft_putnbr_unx(unsigned int num, t_flags *flags)
{
	if (flags->spec == 'x' || flags->spec == 'X')
	{
		if (num >= 16)
		{
			ft_putnbr_unx(num / 16, flags);
			ft_putnbr_unx(num % 16, flags);
		}
		else if (num < 16)
		{
			if (flags->spec == 'X')
				ft_putchar(HEX_UPPER[num % 16], flags);
			else
				ft_putchar(HEX_LOWER[num % 16], flags);
		}
	}
	else if (flags->spec == 'u')
	{
		if (num >= 10)
		{
			ft_putnbr_unx(num / 10, flags);
			ft_putnbr_unx(num % 10, flags);
		}
		else if (num < 10)
			ft_putchar(DEC[num % 10], flags);
	}
}

void	print_dec(va_list argptr, t_flags *flags)
{
	long long int	num;

	num = 0;
	if (flags->spec == 'd' || flags->spec == 'i')
		num = va_arg(argptr, int);
	flags->data_len = ft_nbr_len_d(num);
	if ((flags->prec == 0 && flags->dash > 0
			&& flags->space > 0) || flags->plus > 0)
		flags->data_len++;
	if (flags->prec > 0 || flags->width > flags->data_len
		|| flags->dash > 0 || flags->plus || flags->space)
		work_flags_dec(num, flags);
	else if (flags->dash == 0 && flags->prec == 0)
		ft_putnbr_base(num, flags);
}

void	print_x(unsigned long long int num, t_flags *flags)
{
	flags->data_len = ft_hex_len(num) + (2 * flags->hash);
	if (flags->prec > 0 || flags->width > flags->data_len || flags->dash > 0)
		work_flags_hex(num, flags);
	else if (flags->dash == 0)
	{
		if (flags->hash > 0 && flags->spec == 'x' && num)
			ft_putstr("0x", flags);
		else if (flags->spec == 'X' && flags->hash && num)
			ft_putstr("0X", flags);
		ft_putnbr_unx(num, flags);
	}
}

void	print_uxp(va_list argptr, t_flags *flags)
{
	unsigned long long int	num;

	num = 0;
	if (flags->spec == 'u')
	{
		num = va_arg(argptr, unsigned int);
		print_un_num(num, flags);
	}
	else if (flags->spec == 'x')
	{
		num = va_arg(argptr, unsigned int);
		print_x(num, flags);
	}
	else if (flags->spec == 'X')
	{
		num = va_arg(argptr, unsigned int);
		print_x(num, flags);
	}
	else if (flags->spec == 'p')
	{
		num = va_arg(argptr, unsigned long long int);
		print_xp(num, flags);
	}
}
