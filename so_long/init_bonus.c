/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:55:56 by makhtar           #+#    #+#             */
/*   Updated: 2021/12/15 16:55:57 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init(t_data *info)
{
	info->collectible = 0;
	info->columns = 0;
	info->exit = 0;
	info->free_sp = 0;
	info->rows = 0;
	info->spawn = 0;
	info->wall = 0;
	info->i = 0;
	info->collected_tokens = 0;
	info->x_exit = 0;
	info->y_exit = 0;
	info->collect_triggered = 0;
	info->wizards = 0;
	info->right_triggered = 1;
	info->left_triggered = 1;
	info->death_triggered = 0;
	info->moves = 0;
}

void	print_moves(t_data *vars)
{
	mlx_string_put(vars->mlx, vars->win, 15, 15, 0XDC143C, "MOVES: ");
	mlx_string_put(vars->mlx, vars->win, 65, 15, 0XDC143C,
		ft_itoa(vars->moves));
	vars->img = mlx_xpm_file_to_image(vars->mlx, BRICK,
			&vars->width, &vars->height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 64, 0);
	mlx_string_put(vars->mlx, vars->win, 65, 15,
		0XDC143C, ft_itoa(vars->moves));
}

void	grass(t_data *vars)
{
	while (vars->map[vars->i] != '\n')
		vars->i--;
	vars->x = 0;
	vars->y = 64 * (vars->columns - 1);
	while (vars->map[vars->i])
	{
		if (vars->map[vars->i] == '1')
		{
			vars->img = mlx_xpm_file_to_image(vars->mlx, GRASS,
					&vars->width, &vars->height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
				vars->x, vars->y);
			mlx_destroy_image(vars->mlx, vars->img);
			vars->x += 64;
		}
		vars->i++;
	}
}

void	ft_allocate(t_data *vars)
{
	if (vars->wizards)
	{
		vars->x_wizards = ft_calloc(vars->wizards, sizeof(int));
		vars->y_wizards = ft_calloc(vars->wizards, sizeof(int));
		vars->i_wizards = ft_calloc(vars->wizards, sizeof(int));
	}
}
