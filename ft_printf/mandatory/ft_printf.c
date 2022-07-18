#include "ft_printf.h"

static void	parse_specifier(char **format, t_flags *flags)
{
	if (**format == 'c' || **format == 's' || **format == 'd' || **format == 'i'
		|| **format == 'u' || **format == 'x' || **format == 'X'
		|| **format == 'p' || **format == '%')
		flags->spec = **format;
}

static void	print_hub(va_list argptr, t_flags *flags)
{
	if (flags->spec == 'd' || flags->spec == 'i' || flags->spec == 'u'
		|| flags->spec == 'x' || flags->spec == 'X' || flags->spec == 'p')
		print_diu(argptr, flags);
	else if (flags->spec == 'c' || flags->spec == '%')
		print_c(argptr, flags);
	else if (flags->spec == 's')
		print_strings(argptr, flags);
}

void	ft_flags(t_flags *flags)
{
	flags->spec = 0;
}

void	parse_hub(char *format, va_list argptr, t_flags *flags)
{
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			parse_specifier(&format, flags);
			print_hub(argptr, flags);
			ft_flags(flags);
		}
		else
			ft_putchar(*format, flags);
		format++;
	}
}

int	ft_printf(const char *format, ...)
{
	char	*str;
	va_list	argptr;
	t_flags	flags;

	str = ft_strdup(format);
	ft_flags(&flags);
	flags.printed_len = 0;
	va_start(argptr, format);
	parse_hub(str, argptr, &flags);
	va_end(argptr);
	free(str);
	str = NULL;
	return (flags.printed_len);
}
