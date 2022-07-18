/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:25:58 by makhtar           #+#    #+#             */
/*   Updated: 2022/01/24 17:25:58 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc_custom(size_t bytes)
{
	char	*c;

	c = malloc(bytes + 1);
	if (c == NULL)
		return (NULL);
	while (bytes + 1 != 0)
	{
		c[bytes] = '\0';
		bytes--;
	}
	return (c);
}

size_t	ft_strclen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c)
		i++;
	return (i);
}

char	*ft_strcdup(char *s1, char c, size_t start)
{
	char	*s2;
	size_t	tmp;
	int		i;

	tmp = start;
	if (s1 == NULL)
		return (NULL);
	while (s1[start] != c)
		start++;
	if (s1[start] == '\0')
		start--;
	s2 = ft_calloc_custom(start - tmp + 1);
	if (s2 == NULL)
		return (NULL);
	i = start - tmp;
	while (start + 1 != tmp)
	{
		s2[i] = s1[start];
		start--;
		i--;
	}
	return (s2);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (0);
}
