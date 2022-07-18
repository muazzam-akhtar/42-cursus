/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:30:53 by makhtar & a       #+#    #+#             */
/*   Updated: 2022/05/24 12:54:40 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mini_shell.h"

int	export_env(char *str)
{
	char	*var;
	char	*value;

	delimit_qtes(str);
	var = ft_strdup(str);
	value = NULL;
	if (exp_op(var, value, 0))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	export(char **str)
{
	int		ret;
	int		i;

	i = 0;
	if (str[1] == NULL || is_rdr(str[1]) || !ft_strcmp(str[1], "|"))
		exp_one_arg();
	else
	{
		i = 1;
		while (str[i] != NULL)
		{
			if (is_rdr(str[i]) || !ft_strcmp(str[i], "|"))
				break ;
			ret = export_env(str[i]);
			i++;
		}
		return (ret);
	}
	return (EXIT_SUCCESS);
}
