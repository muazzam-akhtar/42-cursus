/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:26:04 by makhtar           #+#    #+#             */
/*   Updated: 2021/10/19 11:26:04 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_free(char **a)
{
	free(*a);
	*a = NULL;
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

static char	*ft_reading(char **save, int fd)
{
	char	*buffer;
	int		reader;

	buffer = ft_calloc(BUFFER_SIZE + 1);
	reader = read(fd, buffer, BUFFER_SIZE);
	while (reader > 0)
	{
		buffer[reader] = '\0';
		if (*save == NULL)
			*save = ft_strcdup(buffer, '\0', 0);
		else
			*save = ft_strjoin(*save, buffer);
		if (ft_strchr(*save, '\n') != NULL)
			break ;
		reader = read(fd, buffer, BUFFER_SIZE);
	}
	if (reader < 0)
		ft_free(save);
	ft_free(&buffer);
	return (*save);
}

char	*get_next_line(int fd)
{
	static char	*save[10240];
	char		*tmp;
	char		*line;

	if (fd < 0)
		return (NULL);
	save[fd] = ft_reading(&save[fd], fd);
	if (save[fd] == NULL || save[fd][0] == '\0')
		return (NULL);
	else if (ft_strchr(save[fd], '\n') != NULL)
	{
		line = ft_strcdup(save[fd], '\n', 0);
		tmp = ft_strcdup(save[fd], '\0', ft_strclen(save[fd], '\n') + 1);
		free(save[fd]);
		save[fd] = tmp;
		if (save[fd][0] == '\0')
			ft_free(&save[fd]);
	}
	else
	{
		line = ft_strcdup(save[fd], '\0', 0);
		ft_free(&save[fd]);
	}
	return (line);
}
