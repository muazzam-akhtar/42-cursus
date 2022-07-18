/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:26:14 by makhtar           #+#    #+#             */
/*   Updated: 2021/10/19 11:26:14 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t bytes)
{
	char	*str;

	str = malloc(bytes + 1);
	if (str == NULL)
		return (NULL);
	while (bytes + 1 != 0)
	{
		str[bytes] = '\0';
		bytes--;
	}
	return (str);
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
	s2 = ft_calloc(start - tmp + 1);
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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	else
		return (NULL);
}
