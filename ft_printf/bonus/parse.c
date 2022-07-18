/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:49:42 by makhtar           #+#    #+#             */
/*   Updated: 2021/11/04 11:49:42 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_diu(va_list argptr, t_flags *flags)
{
	if (flags->spec == 'd' || flags->spec == 'i')
		print_dec(argptr, flags);
	else if (flags->spec == 'x' || flags->spec == 'X'
		|| flags->spec == 'p' || flags->spec == 'u')
		print_uxp(argptr, flags);
}

void	print_c(va_list argptr, t_flags *flags)
{
	int	data_c;

	data_c = 0;
	if (flags->spec == 'c')
		data_c = va_arg(argptr, int);
	flags->data_len = 1;
	if (flags->space > 0 && flags->dash == 0)
		work_flags(flags);
	if (flags->dash > 0)
	{
		ft_putchar(data_c, flags);
		work_flags(flags);
	}
	else
	{
		work_flags(flags);
		ft_putchar(data_c, flags);
	}
}

void	print_strings(va_list argptr, t_flags *flags)
{
	char	*data_s;

	data_s = va_arg(argptr, char *);
	if (!data_s)
		data_s = "(null)";
	flags->data_len = ft_strlen(data_s);
	if (flags->prec > 0 && flags->prec_length < flags->data_len)
		flags->data_len = flags->prec_length;
	if (flags->width > flags->data_len || flags->dash > 0)
	{
		if (flags->dash > 0)
			ft_putstr(data_s, flags);
		work_flags_cs(flags);
	}
	if (flags->dash == 0)
		ft_putstr(data_s, flags);
}

void	parse_flags2(char **format, t_flags *flags)
{
	if (**format == '#')
		flags->hash = 1;
	else if (**format == '+')
		flags->plus = 1;
}

void	parse_precisions(char **format, t_flags *flags)
{
	if (**format == '.')
	{
		flags->prec = 1;
		++(*format);
		while (**format >= '0' && **format <= '9')
		{
			flags->prec_length = (flags->prec_length * 10) + (**format - '0');
			(*format)++;
		}
	}
	if (flags->prec > 0 && flags->zero_pad > 0)
	{
		flags->space = 1;
		flags->zero_pad = 0;
	}
}
