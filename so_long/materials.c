/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materials.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:56:14 by makhtar           #+#    #+#             */
/*   Updated: 2021/12/16 14:49:16 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_check(char **arg)
{
	if (!ft_strncmp(arg[0], "./so_long",
			ft_strlen("./so_long")) && !ft_strncmp(ft_strrchr(arg[1], '.'),
			".ber", 4))
		return (1);
	return (0);
}

char	*ft_append(char *str, char *buffer)
{
	int		i;
	int		j;
	char	*ret;

	ret = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(buffer) + 1));
	i = 0;
	j = 0;
	if (!ret)
		return (0);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	while (buffer[j])
	{
		ret[i] = buffer[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_reading(int fd)
{
	char		*buffer;
	int			reader;
	char		*ret;
	char		*tmp;

	buffer = malloc(sizeof(char) * 1);
	reader = read(fd, buffer, 1);
	if ((fd > 0) && (reader > 0))
	{
		tmp = NULL;
		while (reader > 0)
		{
			buffer[reader] = '\0';
			if (!tmp)
				tmp = ft_strdup(buffer);
			else
				tmp = ft_append(ret, buffer);
			ret = ft_strdup(tmp);
			free(tmp);
			reader = read(fd, buffer, 1);
		}
		free(buffer);
		return (ret);
	}
	return (0);
}
