/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:18:52 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/23 13:34:30 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*fill_lines(char *line, char *buff)
{
	line = ft_strjoin_gnl(line, buff);
	if (!line)
		return (NULL);
	ft_strlcpy_gnl(buff, buff + ft_strlen_gnl(buff, '\n'), BUFFER_SIZE + 1);
	return (line);
}

static char	*read_and_join(ssize_t *ro, char *line, char *buffer, int fd)
{
	while (*ro > 0)
	{
		line = fill_lines(line, buffer);
		if (!line)
			return (NULL);
		if (ft_strchr_gnl(line, '\n'))
			break ;
		*ro = read(fd, buffer, BUFFER_SIZE);
		buffer[*ro] = '\0';
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[MAX_FD][BUFFER_SIZE + 1];
	ssize_t		ro;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= MAX_FD)
		return (NULL);
	line = (char *)malloc(sizeof(char));
	if (!line)
		return (NULL);
	line[0] = '\0';
	if (ft_strlen_gnl(buffer[fd], '\0') != 0)
	{
		line = fill_lines(line, buffer[fd]);
		if (!line)
			return (NULL);
		if (ft_strchr_gnl(line, '\n'))
			return (line);
	}
	ro = read(fd, buffer[fd], BUFFER_SIZE);
	buffer[fd][ro] = '\0';
	if (ro == 0 && ft_strlen_gnl(line, '\0') != 0)
		return (line);
	if (ro == -1 || (ft_strlen_gnl(line, '\0') == 0 && ro == 0))
		return (free(line), NULL);
	return (read_and_join(&ro, line, buffer[fd], fd));
}
