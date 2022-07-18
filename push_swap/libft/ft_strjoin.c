/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:23:43 by makhtar           #+#    #+#             */
/*   Updated: 2021/10/04 14:07:07 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	i;
	size_t	j;

	if (s1 && s2)
	{
		dst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!dst)
			return (0);
		i = 0;
		while (s1[i] != '\0')
		{
			dst[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j])
		{
			dst[i++] = s2[j++];
		}
		dst[i] = '\0';
		return (dst);
	}
	return (0);
}
