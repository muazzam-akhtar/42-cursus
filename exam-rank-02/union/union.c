#include <unistd.h>

void	check_param(char *str, int *ascii)
{
	int	i = 0;

	while (str[i])
	{
		ascii[(int)str[i]] = 1;
		i++;
	}
}

void	print_param(char *str, int *ascii)
{
	int	i = 0;

	while (str[i])
	{
		if (ascii[(int)str[i]] == 1)
		{
			write(1, str + i, 1);
			ascii[(int)str[i]] = 0;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	int	ascii[255] = {0, };
	if (argc == 3)
	{
		check_param(argv[1], ascii);
		check_param(argv[2], ascii);
		print_param(argv[1], ascii);
		print_param(argv[2], ascii);
	}
	write(1, "\n", 1);
	return (0);
}