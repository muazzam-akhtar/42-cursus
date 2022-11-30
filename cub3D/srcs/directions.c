/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:30:47 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/22 17:52:38 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Fetches the side of the wall when hitted with the ray
**/
int	wall_hit_direction(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->cx < 0)
			return (3);
		else
			return (4);
	}
	else
	{
		if (ray->cy < 0)
			return (1);
		else
			return (2);
	}
	return (FALSE);
}
