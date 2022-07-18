/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_un.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:49:47 by makhtar           #+#    #+#             */
/*   Updated: 2021/11/04 11:49:47 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	work_precision(t_flags *flags)
{
	if (flags->prec > 0)
	{
		if (flags->prec_length > flags->data_len
			&& (flags->spec != 'c' || flags->spec != 's'))
		{
			flags->zero_length = flags->prec_length - flags->data_len;
			print_zero(flags);
			if (flags->space > 0)
				flags->sp_length = flags->width - flags->prec_length;
		}
		if (flags->prec > 0 && flags->spec == 's')
			flags->data_len = flags->prec_length;
	}
}

long long int	ft_hex_len(unsigned long long int num)
{
	unsigned long long int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

long long int	ft_nbr_len_d(long long int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		len++;
		num *= -1;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

void	print_un_num(unsigned int num, t_flags *flags)
{
	flags->data_len = ft_nbr_len(num);
	if (flags->space > 0 && flags->dash == 0)
		work_flags_ps(num, flags);
	if (flags->prec_length > 0)
		work_precision(flags);
	if (flags->dash > 0)
		work_flags_pd(num, flags);
	else
	{
		work_flags(flags);
		if (flags->prec > 0)
		{
			if (flags->prec_length > 0 || num > 0)
				ft_putnbr_unx(num, flags);
		}
		else
			ft_putnbr_unx(num, flags);
	}
}

void	ft_putnbr_xp(unsigned long long int num, t_flags *flags)
{
	if (num >= 16)
	{
		ft_putnbr_xp(num / 16, flags);
		ft_putnbr_xp(num % 16, flags);
	}
	else if (num < 16)
		ft_putchar(HEX_LOWER[num % 16], flags);
}
