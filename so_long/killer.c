/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   killer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:55:00 by makhtar           #+#    #+#             */
/*   Updated: 2021/12/15 16:55:01 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_wizard(t_data *vars, int *k)
{
	vars->img = mlx_xpm_file_to_image(vars->mlx, PA1,
			&vars->width, &vars->height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->x_wizards[*k], vars->y_wizards[*k]);
}

static void	right_movement(t_data *vars, int *timer, int *k)
{
	if (vars->map[vars->i_wizards[*k] + 1] == 'P')
	{
		vars->killer = *k;
		vars->death_triggered = 'D';
	}
	else if (vars->map[vars->i_wizards[*k] + 1] == '0')
	{
		vars->right_triggered = 1;
		vars->map[vars->i_wizards[*k] + 1] = 'M';
		vars->map[vars->i_wizards[*k]] = '0';
		vars->i_wizards[*k] += 1;
		vars->x_wizards[*k] += 64;
		vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x_wizards[*k] - 64, vars->y_wizards[*k]);
		put_wizard(vars, k);
	}
	else
	{
		vars->right_triggered = 0;
		vars->left_triggered = 1;
	}
	*timer = 0;
	(*k)++;
}

static void	left_movement(t_data *vars, int *timer, int *k)
{
	if (vars->map[vars->i_wizards[*k] - 1] == 'P')
	{
		vars->killer = *k;
		vars->death_triggered = 'A';
	}
	else if (vars->map[vars->i_wizards[*k] - 1] == '0')
	{
		vars->left_triggered = 1;
		vars->map[vars->i_wizards[*k] - 1] = 'M';
		vars->map[vars->i_wizards[*k]] = '0';
		vars->i_wizards[*k] -= 1;
		vars->x_wizards[*k] -= 64;
		vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x_wizards[*k] + 64, vars->y_wizards[*k]);
		put_wizard(vars, k);
	}
	else
	{
		vars->right_triggered = 1;
		vars->left_triggered = 0;
	}
	*timer = 0;
	(*k)++;
}

void	wizard_movement(t_data *vars)
{
	static int	k;
	static int	timer;

	if (vars->i_wizards[k] && !vars->death_triggered)
	{
		if (timer == 215 && vars->right_triggered)
			right_movement(vars, &timer, &k);
		if (vars->left_triggered && timer == 215)
			left_movement(vars, &timer, &k);
		if (k == vars->wizards)
			k = 0;
		timer++;
	}
}
