#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct	s_info
{
	int	spec;
	int	printed_len;
}				t_info;

void	ft_putchar(char c, t_info *info)
{
	write(1, &c, 1);
	info->printed_len++;
}

void	ft_putstr(char *str, t_info *info)
{
	int	i = 0;
	while (*str)
	{
		ft_putchar(*str, info);
		str++;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *format)
{
	char	*ret;
	size_t	i = 0;

	ret = malloc(sizeof(char) * (ft_strlen(format) + 1));
	if (!ret)
		return (NULL);
	while (format[i])
	{
		ret[i] = format[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

void	ft_putnbr_base(long int num, t_info *info)
{
	char	str[50] = "0123456789";

	if (num == -2147483648)
	{
		ft_putstr("-2", info);
		num = 147483648;
	}
	if (num < 0)
	{
		ft_putchar ('-', info);
		num = -num;
	}
	if (num >= 10)
	{
		ft_putnbr_base(num / 10, info);
		ft_putnbr_base(num % 10, info);
	}
	if (num < 10)
		ft_putchar(str[num % 10], info);
}

void	ft_putnbr_hex(unsigned int num, t_info *info)
{
	char	hex[50] = "0123456789abcdef";
	if (num >= 16)
	{
		ft_putnbr_hex(num / 16, info);
		ft_putnbr_hex(num % 16, info);
	}
	if (num < 16)
		ft_putchar(hex[num % 16], info);
}

void	print_dec(va_list ap, t_info *info)
{
	int	num = 0;

	num = va_arg(ap, int);
	ft_putnbr_base(num, info);
}

void	print_hex(va_list ap, t_info *info)
{
	unsigned int	num = 0;

	num = va_arg(ap, unsigned int);
	ft_putnbr_hex(num, info);
}

void	print_string(va_list ap, t_info *info)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	ft_putstr(str, info);
}

void	ft_info(t_info *info)
{
	info->spec = 0;
}

void	parse_specifier(char **format, t_info *info)
{
	if (**format == 'c' || **format == 'd' || **format == 's' || **format == 'i' || **format == 'u' || **format == 'x' || **format == '%')
		info->spec = **format;
}

void	print_hub(va_list ap, t_info *info)
{
	if (info->spec == 'd')
		print_dec(ap, info);
	else if (info->spec == 'x')
		print_hex(ap, info);
	else if (info->spec == 's')
		print_string(ap, info);
}

void	parse_hub(char *format, t_info *info, va_list ap)
{
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			parse_specifier(&format, info);
			print_hub(ap, info);
		}
		else
			ft_putchar(*format, info);
		ft_info(info);
		format++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_info	info;
	char	*str;

	str = ft_strdup(format);
	ft_info(&info);
	info.printed_len = 0;
	va_start(ap, format);
	parse_hub(str, &info, ap);
	va_end(ap);
	free(str);
	str = NULL;
	return (info.printed_len);
}