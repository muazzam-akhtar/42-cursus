#include "ft_printf.h"

void	ft_putnbr_base(int num, t_flags *flags)
{
	if (num == -2147483648)
	{
		ft_putstr("-2", flags);
		num = 147483648;
	}
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

void	ft_putnbr_un(unsigned int num, t_flags *flags)
{
	if (num >= 10)
	{
		ft_putnbr_un(num / 10, flags);
		ft_putnbr_un(num % 10, flags);
	}
	else if (num < 10)
		ft_putchar(DEC[num % 10], flags);
}

void	ft_putnbr_xl(unsigned int num, t_flags *flags)
{
	if (num >= 16)
	{
		ft_putnbr_xl(num / 16, flags);
		ft_putnbr_xl(num % 16, flags);
	}
	else if (num < 16)
		ft_putchar(HEX_LOWER[num % 16], flags);
}

void	ft_putnbr_xu(unsigned int num, t_flags *flags)
{
	if (num >= 16)
	{
		ft_putnbr_xu(num / 16, flags);
		ft_putnbr_xu(num % 16, flags);
	}
	else if (num < 16)
		ft_putchar(HEX_UPPER[num % 16], flags);
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