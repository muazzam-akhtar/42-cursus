int	ft_printf(const char *format, ...);

int main(void)
{
	int	a = ft_printf("%s", (void *)NULL);
	ft_printf("\n%d", a);
	ft_printf("\n%d", 42);
	ft_printf("\n%x", 42);
	return (0);
}