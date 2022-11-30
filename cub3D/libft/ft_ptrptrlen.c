/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrptrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:11:58 by hawadh            #+#    #+#             */
/*   Updated: 2022/10/03 15:25:51 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
**	Returns 2D array **ptr size
**/
size_t	ft_ptrptrlen(char **ptr)
{
	size_t	count;

	count = 0;
	while (ptr[count] != NULL)
		count++;
	return (count);
}
