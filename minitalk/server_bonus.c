/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:47:58 by makhtar           #+#    #+#             */
/*   Updated: 2021/12/23 16:02:08 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static char	*ft_append(char *start, char c)
{
	size_t	i;
	char	*tmp;

	tmp = malloc(ft_strlen(start) + 2);
	if (!tmp)
		return (NULL);
	i = 0;
	while (start[i])
	{
		tmp[i] = start[i];
		i++;
	}
	tmp[i] = c;
	tmp[i + 1] = '\0';
	free(start);
	return (tmp);
}

static void	ft_convert(char *s)
{
	int				pow;
	unsigned char	c;
	size_t			i;

	pow = 1;
	c = 0;
	i = ft_strlen(s) - 1;
	while (i + 1 != 0)
	{
		c += pow * (s[i] - '0');
		pow *= 2;
		i--;
	}
	write(1, &c, 1);
}

static void	ft_confirm(int sig, siginfo_t *info, void *context)
{
	static char	*bits;
	static int	bitcount;

	bitcount++;
	(void)context;
	if (!bits)
	{
		bits = ft_strdup("");
		bitcount = 1;
	}
	if (sig == SIGUSR2)
		bits = ft_append(bits, '0');
	else
		bits = ft_append(bits, '1');
	if (bitcount == 8)
	{
		ft_convert(bits);
		free(bits);
		bits = NULL;
	}
	usleep(200);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("Server PID: ", 1);
	ft_putstr_fd(ft_itoa(getpid()), 1);
	ft_putchar_fd('\n', 1);
	sa.sa_sigaction = &ft_confirm;
	sa.sa_mask = SA_SIGINFO;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (0);
}
