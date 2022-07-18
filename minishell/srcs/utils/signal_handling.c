/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:27:53 by makhtar & a       #+#    #+#             */
/*   Updated: 2022/05/25 14:19:10 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_shell.h"

//	move to a newline rl_on_new_line();

//	clear readline buffer rl_replace_line("", 0);

//	display prompt again	rl_redisplay();

static void	control_c(void)
{
	write(2, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_env.stat_code = 1;
}

static void	print_nothing(void)
{
	rl_on_new_line();
	rl_redisplay();
	write(2, "  \b\b  \b\b", 8);
}

void	signal_handler(int signum)
{
	if (signum == SIGINT)
	{
		if (g_env.s_pid)
		{
			ft_putendl_fd("\b\b", 2);
			g_env.stat_code = 130;
		}
		else
			control_c();
	}
	else if (signum == SIGQUIT)
	{
		if (g_env.s_pid)
		{
			ft_putendl_fd("\b\bQuit", 2);
			g_env.stat_code = 131;
		}
		else
			print_nothing();
	}
	g_env.s_pid = 0;
}

/*
! why this funnction ? 
This function helps to handle signals such as CTRL + C and CONTRL + \
*/
void	handle_signals(void)
{
	signal(SIGINT, &signal_handler);
	signal(SIGQUIT, &signal_handler);
}
