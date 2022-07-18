/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:54:56 by makhtar           #+#    #+#             */
/*   Updated: 2021/12/15 16:55:38 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	smoke_xpm(void **img, t_data *vars)
{
	img[0] = mlx_xpm_file_to_image(vars->mlx,
			SMOKE1, &vars->width, &vars->height);
	img[1] = mlx_xpm_file_to_image(vars->mlx,
			SMOKE2, &vars->width, &vars->height);
	img[2] = mlx_xpm_file_to_image(vars->mlx,
			SMOKE3, &vars->width, &vars->height);
	img[3] = mlx_xpm_file_to_image(vars->mlx,
			SMOKE4, &vars->width, &vars->height);
	img[4] = mlx_xpm_file_to_image(vars->mlx,
			SMOKE5, &vars->width, &vars->height);
	img[5] = mlx_xpm_file_to_image(vars->mlx,
			SMOKE6, &vars->width, &vars->height);
	img[6] = mlx_xpm_file_to_image(vars->mlx,
			SMOKE7, &vars->width, &vars->height);
	img[7] = mlx_xpm_file_to_image(vars->mlx,
			SMOKE8, &vars->width, &vars->height);
}

static void	magic_xpm(void **img, t_data *vars)
{
	img[0] = mlx_xpm_file_to_image(vars->mlx, PA2, &vars->width, &vars->height);
	img[1] = mlx_xpm_file_to_image(vars->mlx, PA3, &vars->width, &vars->height);
	img[2] = mlx_xpm_file_to_image(vars->mlx, PA4, &vars->width, &vars->height);
	img[3] = mlx_xpm_file_to_image(vars->mlx, PA5, &vars->width, &vars->height);
	img[4] = mlx_xpm_file_to_image(vars->mlx, PA6, &vars->width, &vars->height);
	img[5] = mlx_xpm_file_to_image(vars->mlx, PA7, &vars->width, &vars->height);
	img[6] = mlx_xpm_file_to_image(vars->mlx, PA8, &vars->width, &vars->height);
	img[7] = mlx_xpm_file_to_image(vars->mlx, PA9, &vars->width, &vars->height);
	img[8] = mlx_xpm_file_to_image(vars->mlx,
			PA10, &vars->width, &vars->height);
}

static void	wizard_magic(t_data *vars, void **img)
{
	static int	i;

	vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
			&vars->width, &vars->height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->x_wizards[vars->killer], vars->y_wizards[vars->killer]);
	mlx_put_image_to_window(vars->mlx, vars->win, img[i],
		vars->x_wizards[vars->killer], vars->y_wizards[vars->killer]);
	i++;
}

static void	smoke(t_data *vars, void **img)
{
	static int	i;

	vars->img = mlx_xpm_file_to_image(vars->mlx, SKY,
			&vars->width, &vars->height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->x, vars->y);
	if ((i < 8))
	{
		mlx_put_image_to_window(vars->mlx, vars->win, img[i],
			vars->x, vars->y);
		i++;
	}
}

int	dead_sprite(t_data *vars)
{
	static void		*img[9];
	static int		i;
	static int		timer;
	static int		flags;

	if (!flags)
		magic_xpm(img, vars);
	if (i < 9 && ((timer == 200 && !flags) || (timer == 800 && flags)))
	{
		if (!flags && (timer == 200))
			wizard_magic(vars, img);
		if ((i++ < 8) && flags && (timer == 800))
			smoke(vars, img);
		timer = 0;
	}
	if (i == 9)
	{
		smoke_xpm(img, vars);
		flags = 1;
		i = 0;
	}
	if (i == 8 && flags)
		return (1);
	timer++;
	return (0);
}
