/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:56:17 by makhtar           #+#    #+#             */
/*   Updated: 2021/12/15 18:51:55 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	exit_box(t_data *vars)
{
	vars->img = mlx_xpm_file_to_image(vars->mlx, GRI1,
			&vars->width, &vars->height);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img, vars->x, vars->y);
	mlx_destroy_image(vars->mlx, vars->img);
}

void	player_up_image(t_data *vars)
{
	if (go_up(vars))
	{
		if (vars->map[vars->i] == 'E')
			exit_box(vars);
		if (!(vars->x == vars->x_exit && vars->y == vars->y_exit - 64))
		{
			vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
					&vars->width, &vars->height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
				vars->x, vars->y + 64);
			vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
					&vars->width, &vars->height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
				vars->x, vars->y);
			vars->img = mlx_xpm_file_to_image(vars->mlx, GRI1,
					&vars->width, &vars->height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
				vars->x, vars->y);
		}
		vars->moves++;
	}
}

void	player_down_image(t_data *vars)
{
	if (go_down(vars))
	{
		if (vars->map[vars->i] == 'E')
			exit_box(vars);
		if (!(vars->x == vars->x_exit && vars->y == vars->y_exit + 64))
		{
			vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
					&vars->width, &vars->height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
				vars->x, vars->y - 64);
			vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
					&vars->width, &vars->height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
				vars->x, vars->y);
			vars->img = mlx_xpm_file_to_image(vars->mlx, GRI1,
					&vars->width, &vars->height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
				vars->x, vars->y + 15);
		}
		vars->moves++;
	}
}

void	player_right_image(t_data *vars)
{
	if (go_right(vars))
	{
		if (vars->map[vars->i] == 'E')
			exit_box(vars);
		if (!(vars->x == vars->x_exit + 64 && vars->y == vars->y_exit))
		{
			vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
					&vars->width, &vars->height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
				vars->x - 64, vars->y);
			vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
					&vars->width, &vars->height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
				vars->x, vars->y);
		}
		vars->img = mlx_xpm_file_to_image(vars->mlx, GRI1,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
		vars->moves++;
	}
}

void	player_left_image(t_data *vars)
{
	if (go_left(vars))
	{
		if (vars->map[vars->i] == 'E')
			exit_box(vars);
		if (!(vars->x == vars->x_exit - 64 && vars->y == vars->y_exit))
		{
			vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
					&vars->width, &vars->height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
				vars->x + 64, vars->y);
			vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
					&vars->width, &vars->height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
				vars->x, vars->y);
		}
		vars->img = mlx_xpm_file_to_image(vars->mlx, GRI1,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
		vars->moves++;
	}
}
