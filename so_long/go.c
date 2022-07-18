/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:55:45 by makhtar           #+#    #+#             */
/*   Updated: 2021/12/15 18:56:36 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	go_up(t_data *vars)
{
	int			count;

	count = vars->rows + 1;
	player_locator(vars);
	if (vars->map[vars->i] == 'P' && vars->map[vars->i - count] != '1')
	{
		movement_up(vars, count);
		return (1);
	}
	return (0);
}

int	go_down(t_data *vars)
{
	int			count;

	count = vars->rows + 1;
	player_locator(vars);
	if (vars->map[vars->i] == 'P' && vars->map[vars->i + count] != '1')
	{
		movement_down(vars, count);
		return (1);
	}
	return (0);
}

int	go_right(t_data *vars)
{
	player_locator(vars);
	if (vars->map[vars->i] == 'P' && vars->map[vars->i + 1] != '1')
	{
		movement_right(vars);
		return (1);
	}
	return (0);
}

int	go_left(t_data *vars)
{
	player_locator(vars);
	if (vars->map[vars->i] == 'P' && vars->map[vars->i - 1] != '1')
	{
		movement_left(vars);
		return (1);
	}
	return (0);
}

void	open_exit(t_data *vars)
{
	vars->i = 0;
	vars->x = 0;
	vars->y = 0;
	while (vars->map[vars->i] != 'E')
	{
		vars->x += 64;
		if (vars->map[vars->i == '\n'])
		{
			vars->y += 64;
			vars->x = 0;
		}
		vars->i++;
	}
	vars->img = mlx_xpm_file_to_image(vars->mlx, EXIT_PATH1,
			&vars->width, &vars->height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->x_exit, vars->y_exit);
}
