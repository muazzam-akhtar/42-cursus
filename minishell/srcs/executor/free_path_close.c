/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_path_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:35:13 by makhtar           #+#    #+#             */
/*   Updated: 2022/05/26 19:29:59 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_shell.h"

void	get_exit_status(int i, pid_t *pid)
{
	int	status;

	status = 2;
	if (i == g_env.count - 1)
	{
		if (pid[i] != 0)
		{
			waitpid(pid[i], &status, 0);
			if (WIFEXITED(status))
				g_env.stat_code = WEXITSTATUS(status);
		}
		else
			g_env.stat_code = 1;
	}
	else
	{
		if (pid[i] != 0)
		{
			waitpid(pid[i], &status, 0);
			WIFEXITED(status);
		}
	}
}

void	free_path_close(t_pars_tokens *pa_tkns, int i, char **path)
{
	close_out_in_files_fd(pa_tkns, i);
	free_me(path);
}

void	closing_pipes(t_pars_tokens *pa_tkns, int i, int **p)
{
	if (pa_tkns[i].pipe)
	{
		close(p[i][0]);
		close(p[i][1]);
	}
	if (pa_tkns[i].pipe != 1 && pa_tkns[i].pipe)
		close(p[i + 1][1]);
}

void	closing_fds_child(t_pars_tokens *pa_tkns, int i, \
		int **p)
{
	close_out_in_files_fd(pa_tkns, i);
	close_pipe_and_heredoc_fd(pa_tkns, p);
}

void	free_child(t_pars_tokens *pa_tkns, \
		int i, pid_t *pid, char *path)
{
	free_path_close(pa_tkns, i, &path);
	free_everything(pa_tkns);
	free_env();
	free(pid);
}
