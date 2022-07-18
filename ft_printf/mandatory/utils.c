#include "ft_printf.h"

void	ft_putchar(char c, t_flags *flags)
{
	write(1, &c, 1);
	flags->printed_len++;
}

void	ft_putstr(char *data_s, t_flags *flags)
{
	while (*data_s)
	{
		ft_putchar(*data_s, flags);
		data_s++;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;

	dst = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dst)
		return (0);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}