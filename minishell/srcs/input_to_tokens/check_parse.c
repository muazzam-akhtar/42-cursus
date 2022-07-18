/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:40:34 by makhtar           #+#    #+#             */
/*   Updated: 2022/05/26 19:40:35 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_shell.h"

int	check_parse(char **tokens)
{
	if (tokens[0] == NULL)
	{
		ft_free_str_array(&tokens);
		return (1);
	}
	return (0);
}
