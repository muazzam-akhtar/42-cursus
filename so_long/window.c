/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:56:36 by makhtar           #+#    #+#             */
/*   Updated: 2021/12/15 20:29:41 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	create_window(t_data *vars)
{
	vars->win = mlx_new_window(vars->mlx, 64 *(vars->rows),
			64 *(vars->columns), "So Long");
	vars->y = 0;
	while (vars->y < 64 * vars->columns)
	{
		vars->x = 0;
		while (vars->x < 64 * vars->rows)
		{
			vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
					&vars->width, &vars->height);
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->img, vars->x, vars->y);
			vars->x += 64;
		}
		vars->y += 64;
	}
	vars->x = 0;
	vars->i = 0;
	vars->img = mlx_xpm_file_to_image(vars->mlx, BRICK,
			&vars->width, &vars->height);
}

static void	black_walls(t_data *vars)
{
	while (vars->map[vars->i] == '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x, 0);
		vars->x += 64;
		vars->i++;
	}
	vars->x = 0;
	vars->y = 64;
	++vars->i;
}

static void	take_picture(t_data *vars)
{
	if (vars->map[vars->i] == 'C')
	{
		vars->img = mlx_xpm_file_to_image(vars->mlx, COLLECT,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x - 16, vars->y);
	}
	else if (vars->map[vars->i] == 'P')
		vars->img = mlx_xpm_file_to_image(vars->mlx, GRI1,
				&vars->width, &vars->height);
	else if (vars->map[vars->i] == '0')
		vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
				&vars->width, &vars->height);
	else if (vars->map[vars->i] == '1')
		vars->img = mlx_xpm_file_to_image(vars->mlx, CRATE,
				&vars->width, &vars->height);
	else if (vars->map[vars->i] == 'E')
	{
		vars->x_exit = vars->x;
		vars->y_exit = vars->y;
		vars->img = mlx_xpm_file_to_image(vars->mlx, EXIT_PATH,
				&vars->width, &vars->height);
	}
}

static void	ft_reset(t_data *vars)
{
	if (vars->map[vars->i] != 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
	vars->i++;
	vars->x += 64;
	if (vars->map[vars->i] == '\n')
	{
		vars->x = 0;
		vars->y += 64;
		++vars->i;
	}
}

void	map_init(t_data *vars)
{
	create_window(vars);
	black_walls(vars);
	while (vars->map[vars->i])
	{
		if (vars->map[vars->i] != 'M')
			take_picture(vars);
		ft_reset(vars);
	}
}
