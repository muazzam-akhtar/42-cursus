/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idle_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:55:52 by makhtar           #+#    #+#             */
/*   Updated: 2021/12/15 16:55:53 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	player_idle_sprite1(t_data *vars, int *timer)
{
	if ((*timer) == 3750 && !vars->collect_triggered)
	{
		vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
		vars->img = mlx_xpm_file_to_image(vars->mlx, GRI4,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
	}
	if ((*timer) == 5000 && !vars->collect_triggered)
	{
		vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
		vars->img = mlx_xpm_file_to_image(vars->mlx, GRI5,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
		*timer = 0;
	}
	(*timer)++;
}

void	player_idle_sprite(t_data *vars)
{
	static int	timer = 0;

	if (timer == 1250 && !vars->collect_triggered)
	{
		vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
		vars->img = mlx_xpm_file_to_image(vars->mlx, GRI2,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
	}
	if (timer == 2500 && !vars->collect_triggered)
	{
		vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
		vars->img = mlx_xpm_file_to_image(vars->mlx, GRI3,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
	}
	player_idle_sprite1(vars, &timer);
}
