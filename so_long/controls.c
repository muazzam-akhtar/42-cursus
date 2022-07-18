/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:55:33 by makhtar           #+#    #+#             */
/*   Updated: 2021/12/15 18:54:00 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement_up(t_data *vars, int count)
{
	vars->y -= 64;
	if (vars->map[vars->i - count] == 'C')
		vars->collected_tokens++;
	vars->map[vars->i] = '0';
	if (vars->x == vars->x_exit && vars->y == vars->y_exit - 64)
		put_image_exit(vars);
	else if (vars->map[vars->i - count] == 'E')
	{
		vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img, vars->x, vars->y + 64);
		departure(vars);
	}
	vars->map[vars->i - count] = 'P';
}

void	movement_down(t_data *vars, int count)
{
	vars->y += 64;
	if (vars->map[vars->i + count] == 'C')
		vars->collected_tokens++;
	vars->map[vars->i] = '0';
	if (vars->x == vars->x_exit && vars->y == vars->y_exit + 64)
		put_image_exit(vars);
	else if (vars->map[vars->i + count] == 'E')
	{
		vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y - 64);
		departure(vars);
	}
	vars->map[vars->i + count] = 'P';
}

void	movement_right(t_data *vars)
{
	vars->x += 64;
	if (vars->map[vars->i + 1] == 'C')
		vars->collected_tokens++;
	vars->map[vars->i] = '0';
	if (vars->x == vars->x_exit + 64 && vars->y == vars->y_exit)
		put_image_exit(vars);
	else if (vars->map[vars->i + 1] == 'E')
		departure(vars);
	vars->map[vars->i + 1] = 'P';
}

void	movement_left(t_data *vars)
{
	vars->x -= 64;
	if (vars->map[vars->i - 1] == 'C')
		vars->collected_tokens++;
	vars->map[vars->i] = '0';
	if (vars->x == vars->x_exit - 64 && vars->y == vars->y_exit)
		put_image_exit(vars);
	else if (vars->map[vars->i - 1] == 'E')
		departure(vars);
	vars->map[vars->i - 1] = 'P';
}
