#include "ft_printf.h"

void	print_dec(va_list argptr, t_flags *flags)
{
	int	num;

	num = 0;
	if (flags->spec == 'd')
		num = va_arg(argptr, int);
	else if (flags->spec == 'i')
		num = va_arg(argptr, int);
	ft_putnbr_base(num, flags);
}

void	print_uxp(va_list argptr, t_flags *flags)
{
	unsigned long long int	num;

	num = 0;
	if (flags->spec == 'u')
	{
		num = va_arg(argptr, unsigned int);
		ft_putnbr_un(num, flags);
	}
	else if (flags->spec == 'x')
	{
		num = va_arg(argptr, unsigned int);
		ft_putnbr_xl(num, flags);
	}
	else if (flags->spec == 'X')
	{
		num = va_arg(argptr, unsigned int);
		ft_putnbr_xu(num, flags);
	}
	else if (flags->spec == 'p')
	{
		num = va_arg(argptr, unsigned long long int);
		ft_putstr("0x", flags);
		ft_putnbr_xp(num, flags);
	}
}

void	print_diu(va_list argptr, t_flags *flags)
{
	if (flags->spec == 'd' || flags->spec == 'i')
		print_dec(argptr, flags);
	else if (flags->spec == 'x' || flags->spec == 'X' || flags->spec == 'p'
		|| flags->spec == 'u')
		print_uxp(argptr, flags);
}

void	print_c(va_list argptr, t_flags *flags)
{
	int	data_c;

	data_c = 0;
	if (flags->spec == 'c')
		data_c = va_arg(argptr, int);
	else
		data_c = '%';
	ft_putchar(data_c, flags);
}

void	print_strings(va_list argptr, t_flags *flags)
{
	char	*data_s;

	data_s = 0;
	data_s = va_arg(argptr, char *);
	if (!data_s)
		data_s = "(null)";
	ft_putstr(data_s, flags);
}
