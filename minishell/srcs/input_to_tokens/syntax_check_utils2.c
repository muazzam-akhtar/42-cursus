/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:29:13 by makhtar & a       #+#    #+#             */
/*   Updated: 2022/05/24 11:42:28 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_shell.h"

int	is_token_syntax_valid(char **tokens)
{
	int	i;

	i = 0;
	if (tokens[i] && tokens[i][0] == '|')
		return (0);
	while (tokens && tokens[i] != NULL)
	{
		if (!token_contains_quote(tokens[i]))
		{
			if (tokens[i] && tokens[i + 1] == NULL)
			{
				if (is_token_redir(tokens[i]))
					return (0);
				if (!is_token_pipe(tokens[i]))
					return (0);
			}
			if (check_pipe_conditions(tokens, i))
				return (0);
			if (!is_special_charater_correct(tokens[i]))
				return (0);
		}
		i++;
	}
	return (1);
}
