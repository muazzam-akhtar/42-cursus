/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:25:48 by makhtar           #+#    #+#             */
/*   Updated: 2021/10/19 11:25:48 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

static char	*ft_strjoin(char *start, char *end)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	tmp = malloc(ft_strclen(start, '\0') + ft_strclen(end, '\0') + 1);
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (start[i] != '\0')
	{
		tmp[i] = start[i];
		i++;
	}
	j = 0;
	while (end[j] != '\0')
	{
		tmp[i] = end[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	free(start);
	return (tmp);
}

static char	*ft_reading(char *save, int fd)
{
	char	*buffer;
	int		reader;

	buffer = ft_calloc(BUFFER_SIZE + 1);
	reader = read(fd, buffer, BUFFER_SIZE);
	while (reader > 0)
	{
		buffer[reader] = '\0';
		if (save == NULL)
			save = ft_strcdup(buffer, '\0', 0);
		else
			save = ft_strjoin(save, buffer);
		if (ft_strchr(save, '\n') != NULL)
			break ;
		reader = read(fd, buffer, BUFFER_SIZE);
	}
	if (reader < 0)
		ft_free(&save);
	ft_free(&buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*tmp;
	char		*line;

	if (fd < 0)
		return (NULL);
	save = ft_reading(save, fd);
	if (save == NULL || *save == '\0')
		return (NULL);
	else if (ft_strchr(save, '\n') != NULL)
	{
		line = ft_strcdup(save, '\n', 0);
		tmp = ft_strcdup(save, '\0', ft_strclen(save, '\n') + 1);
		free(save);
		save = tmp;
		if (*save == '\0')
			ft_free(&save);
	}
	else
	{
		line = ft_strcdup(save, '\0', 0);
		ft_free(&save);
	}
	return (line);
}
