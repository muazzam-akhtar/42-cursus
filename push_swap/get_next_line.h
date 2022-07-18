/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:29:23 by makhtar           #+#    #+#             */
/*   Updated: 2022/01/24 17:29:23 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>

void	*ft_calloc_custom(size_t bytes);
size_t	ft_strclen(const char *s, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strcdup(char *s1, char c, size_t start);
char	*get_next_line(int fd);

#endif