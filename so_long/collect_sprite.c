/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:55:30 by makhtar           #+#    #+#             */
/*   Updated: 2021/12/15 16:55:31 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	collect_sprite4(t_data *vars, int *timer)
{
	if (*timer == 11250)
	{
		vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
		vars->img = mlx_xpm_file_to_image(vars->mlx, GRA9,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
	}
	if (*timer == 12500)
	{
		vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
		vars->img = mlx_xpm_file_to_image(vars->mlx, GRA10,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
		vars->collect_triggered = 0;
		*timer = 0;
	}
	(*timer)++;
}

static void	collect_sprite3(t_data *vars, int *timer)
{
	if (*timer == 8750)
	{
		vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img, vars->x, vars->y);
		vars->img = mlx_xpm_file_to_image(vars->mlx, GRA7,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
	}
	if (*timer == 10000)
	{
		vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
		vars->img = mlx_xpm_file_to_image(vars->mlx, GRA8,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
	}
	collect_sprite4(vars, timer);
}

static void	collect_sprite2(t_data *vars, int *timer)
{
	if (*timer == 6250)
	{
		vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
		vars->img = mlx_xpm_file_to_image(vars->mlx, GRA5,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
	}
	if (*timer == 7500)
	{
		vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
		vars->img = mlx_xpm_file_to_image(vars->mlx, GRA6,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
	}
	collect_sprite3(vars, timer);
}

static void	collect_sprite1(t_data *vars, int *timer)
{
	if (*timer == 3750)
	{
		vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
		vars->img = mlx_xpm_file_to_image(vars->mlx, GRA3,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
	}
	if (*timer == 5000)
	{
		vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
		vars->img = mlx_xpm_file_to_image(vars->mlx, GRA4,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
	}
	collect_sprite2(vars, timer);
}

void	collect_sprite(t_data *vars)
{
	static int	timer;

	if (timer == 1250)
	{
		vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
		vars->img = mlx_xpm_file_to_image(vars->mlx, GRA1,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img, vars->x, vars->y);
	}
	if (timer == 2500)
	{
		vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
		vars->img = mlx_xpm_file_to_image(vars->mlx, GRA2,
				&vars->width, &vars->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
	}
	collect_sprite1(vars, &timer);
}
