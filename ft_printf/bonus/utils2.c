/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:50:04 by makhtar           #+#    #+#             */
/*   Updated: 2021/11/04 11:50:04 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	work_flags_space(t_flags *flags)
{
	if (flags->width >= flags->prec_length
		&& flags->prec_length > flags->data_len)
	{
		flags->sp_length = flags->width - flags->prec_length;
		flags->sp_length = flags->sp_length - flags->plus;
	}
	else if (!flags->prec_length && flags->width)
		flags->sp_length = flags->width - flags->data_len;
	else if (flags->width > flags->prec_length
		&& flags->prec_length <= flags->data_len)
		flags->sp_length = flags->width - flags->data_len;
	print_space(flags);
}

void	work_flags_xp(unsigned long long int num, t_flags *flags)
{
	if (flags->space > 0 && flags->dash == 0)
		work_flags(flags);
	ft_putstr("0x", flags);
	work_precision(flags);
	if (flags->dash > 0)
	{
		ft_putnbr_xp(num, flags);
		work_sp_zx(flags);
	}
	else if (flags->dash == 0)
	{
		work_sp_zx(flags);
		ft_putnbr_xp(num, flags);
	}
}

void	print_xp(unsigned long long int num, t_flags *flags)
{
	flags->data_len = ft_hex_len(num) + 2;
	if (flags->prec > 0 || flags->width > flags->data_len
		|| flags->dash || flags->hash)
		work_flags_xp(num, flags);
	else if (flags->dash == 0)
	{
		ft_putstr("0x", flags);
		ft_putnbr_xp(num, flags);
	}
}
