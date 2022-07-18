/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:47:41 by makhtar           #+#    #+#             */
/*   Updated: 2021/12/22 16:56:10 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	received(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (sig == SIGUSR1)
	{
		ft_putstr_fd("Signal Confirmed from Server's PID: ", 1);
		ft_putendl_fd(ft_itoa(info->si_pid), 1);
	}
}

static char	*ft_bit(char *str, size_t i, size_t j)
{
	char			*ret;
	unsigned char	c;
	int				bytes;

	ret = malloc(((i * 8) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (i + 1 != 0)
	{
		c = str[i - 1];
		bytes = 8;
		while (bytes > 0)
		{
			if (c % 2 == 1)
				ret[ft_strlen(str) * 8 - j - 1] = '1';
			else
				ret[ft_strlen(str) * 8 - j - 1] = '0';
			c /= 2;
			j++;
			bytes--;
		}
		i--;
	}
	ret[ft_strlen(str) * 8] = '\0';
	return (ret);
}

static void	ft_send_msg(int pid, char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			kill(pid, SIGUSR1);
		else if (str[i] == '0')
			kill(pid, SIGUSR2);
		i++;
		pause();
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	char				*bits;
	int					pid;
	struct sigaction	sa;

	if (argc == 3)
	{
		sa.sa_sigaction = &received;
		sa.sa_flags = SA_SIGINFO;
		sigemptyset(&sa.sa_mask);
		sigaction(SIGUSR1, &sa, 0);
		pid = ft_atoi(argv[1]);
		bits = ft_bit(argv[2], ft_strlen(argv[2]), 0);
		if (!bits)
			ft_putstr_fd("Allocation went wrong!\n", 1);
		ft_send_msg(pid, bits);
		free(bits);
	}
	else
	{
		ft_putstr_fd("First argument must be ./client\n", 1);
		ft_putstr_fd("Second argument must be Server's PID\n", 1);
		ft_putstr_fd("Third argument must be the message\n", 1);
	}
	return (0);
}
