/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:56:07 by makhtar           #+#    #+#             */
/*   Updated: 2021/12/16 15:35:19 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_res(char *ret, int *i, t_data *info)
{
	while (ret[*i])
	{
		if (ret[*i] == '\n')
		{
			if (ret[++(*i)] != '1' && ret[(*i) - 2] != '1')
				return (0);
			info->wall = 1;
		}
		if (ret[*i] == '1')
			info->wall = 1;
		else if (ret[*i] == '0')
			info->free_sp = 1;
		else if (ret[*i] == 'C')
			info->collectible++;
		else if (ret[*i] == 'P')
			info->spawn++;
		else if (ret[*i] == 'E')
			info->exit++;
		else
			return (0);
		(*i)++;
	}
	return (1);
}

static int	check_args(char *ret, t_data *info)
{
	int	i;

	i = 0;
	while (ret[i] != '\n' && ret[i] != '\0')
	{
		if (ret[i] != '1')
			return (0);
		i++;
	}
	if (!check_res(ret, &i, info))
		return (0);
	while (ret[--i] != '\n' && ret[i] != '\0')
	{
		if (ret[i] != '1')
			return (0);
	}
	if (info->spawn == 1 && info->exit == 1
		&& info->collectible && info->wall)
		return (1);
	return (0);
}

static int	check_size(char	*ret, t_data *info)
{
	static int	tmp;
	static int	i;

	while (ret[i] != '\n' && ret[i] != '\0')
		i++;
	info->rows = i;
	if (ret[i++] == '\n')
	{
		while (ret[i])
		{
			if (ret[i++] == '\n')
			{
				if (tmp != info->rows)
					return (0);
				tmp = 0;
			}
			else
				tmp++;
		}
		if (tmp != info->rows)
			return (0);
	}
	return (i);
}

static void	map_calculator(char *map, t_data *info)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i] != '\n')
			i++;
		while (map[i])
		{
			if (map[i] == '\n')
				info->columns++;
			i++;
		}
		info->columns++;
	}
}

char	*map_work(int fd, t_data *info)
{
	char	*map;

	map = ft_reading(fd);
	if (map)
	{
		if (!check_args(map, info))
		{
			ft_putstr_fd("Error in arguments\n", 1);
			return (0);
		}
		else if (!check_size(map, info))
		{
			ft_putstr_fd("Map Invalid\n", 1);
			return (0);
		}
		map_calculator(map, info);
		return (map);
	}
	return (0);
}
