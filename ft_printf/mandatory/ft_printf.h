#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define DEC "0123456789"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

typedef struct s_flags
{
	int							spec;
	int							printed_len;
}				t_flags;

size_t	ft_strlen(const char *str);

char	*ft_strdup(const char *s1);

void	ft_putchar(char c, t_flags *flags);
void	ft_putstr(char *data_s, t_flags *flags);
void	ft_putnbr_base(int num, t_flags *flags);
void	ft_putnbr_un(unsigned int num, t_flags *flags);
void	ft_putnbr_xl(unsigned int num, t_flags *flags);
void	ft_putnbr_xu(unsigned int num, t_flags *flags);
void	ft_putnbr_xp(unsigned long long int num, t_flags *flags);
void	print_dec(va_list argptr, t_flags *flags);
void	print_uxp(va_list argptr, t_flags *flags);
void	print_diu(va_list argptr, t_flags *flags);
void	print_c(va_list argptr, t_flags *flags);
void	print_strings(va_list argptr, t_flags *flags);
void	ft_flags(t_flags *flags);
void	parse_hub(char *format, va_list argptr, t_flags *flags);

int		ft_printf(const char *format, ...);

#endif 