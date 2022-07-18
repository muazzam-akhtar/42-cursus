/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   killer_locator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:54:50 by makhtar           #+#    #+#             */
/*   Updated: 2021/12/15 16:55:03 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	killer_locator_up(t_data *vars, int i)
{
	int	code;
	int	count;

	code = 0;
	count = vars->rows + 1;
	i -= count;
	if (vars->map[i] == 'M')
	{
		while (vars->i_wizards[code++])
			if (vars->i_wizards[code] == i)
				break ;
		if (vars->map[vars->i_wizards[code]] == vars->map[i])
			return (code);
	}
	return (0);
}

static int	killer_locator_down(t_data *vars, int i)
{
	int	code;
	int	count;

	code = 0;
	count = vars->rows + 1;
	i += count;
	if (vars->map[i] == 'M')
	{
		while (vars->i_wizards[code++])
			if (vars->i_wizards[code] == i)
				break ;
		if (vars->map[vars->i_wizards[code]] == vars->map[i])
			return (code);
	}
	return (0);
}

static int	killer_locator_left(t_data *vars, int i)
{
	int	code;

	code = 0;
	i -= 1;
	if (vars->map[i] == 'M')
	{
		while (vars->i_wizards[code++])
			if (vars->i_wizards[code] == i)
				break ;
		if (vars->map[vars->i_wizards[code]] == vars->map[i])
			return (code);
	}
	return (0);
}

static int	killer_locator_right(t_data *vars, int i)
{
	int	code;

	code = 0;
	i += 1;
	if (vars->map[i] == 'M')
	{
		while (vars->i_wizards[code++])
			if (vars->i_wizards[code] == i)
				break ;
		if (vars->map[vars->i_wizards[code]] == vars->map[i])
			return (code);
	}
	return (0);
}

int	killer_locator(t_data *vars)
{
	int	i;
	int	code;

	player_locator(vars);
	i = vars->i;
	code = 0;
	if (vars->death_triggered == 'W')
		code = killer_locator_up(vars, i);
	else if (vars->death_triggered == 'S')
		code = killer_locator_down(vars, i);
	else if (vars->death_triggered == 'A')
		code = killer_locator_left(vars, i);
	else if (vars->death_triggered == 'D')
		code = killer_locator_right(vars, i);
	vars->killer = code;
	return (vars->killer);
}
