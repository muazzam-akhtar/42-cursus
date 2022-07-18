/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:55:41 by makhtar           #+#    #+#             */
/*   Updated: 2021/12/15 18:54:30 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_locator(t_data *vars)
{
	vars->i = 0;
	vars->x = 0;
	vars->y = 0;
	while (vars->map[vars->i] != 'P' && vars->map[vars->i] != '\0')
	{
		vars->x += 64;
		if (vars->map[vars->i] == '\n')
		{
			vars->x = 0;
			vars->y += 64;
		}
		vars->i++;
	}
}

void	put_image_exit(t_data *vars)
{
	vars->map[vars->i] = 'E';
	if (vars->collected_tokens == vars->collectible)
		vars->img = mlx_xpm_file_to_image(vars->mlx, EXIT_PATH1,
				&vars->width, &vars->height);
	else
		vars->img = mlx_xpm_file_to_image(vars->mlx, EXIT_PATH,
				&vars->width, &vars->height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->x_exit, vars->y_exit);
	mlx_destroy_image(vars->mlx, vars->img);
}

void	departure(t_data *vars)
{
	vars->img = mlx_xpm_file_to_image(vars->mlx, SKY, &vars->width,
			&vars->height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x, vars->y);
	vars->img = mlx_xpm_file_to_image(vars->mlx, GRI1, &vars->width,
			&vars->height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x, vars->y);
	if (vars->collected_tokens == vars->collectible)
	{
		write(1, "\nYou Won\n", 8);
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->map);
		exit(0);
	}
}
