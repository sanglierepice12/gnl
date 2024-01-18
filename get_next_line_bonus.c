/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gostr@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:37:39 by gsuter            #+#    #+#             */
/*   Updated: 2024/01/18 15:19:39 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_clean_buf(char *buf)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	if (buf[i] == '\n')
		i++;
	j = 0;
	while (buf[i + j])
	{
		buf[j] = buf[i + j];
		j++;
	}
	buf[j] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buf[OPEN_MAX][BUFFER_SIZE + 1];
	ssize_t		bytes_readed;
	char		*line;

	bytes_readed = 1;
	if (fd < 0 || read(fd, buf[fd], 0) < 0)
		return (ft_bzero(buf[fd]), NULL);
	line = ft_strdup(buf[fd]);
	if (!line)
		return (free(line), NULL);
	while (!ft_endline(line) && bytes_readed)
	{
		bytes_readed = read(fd, buf[fd], BUFFER_SIZE);
		if (bytes_readed < 0)
			return (ft_bzero(buf[fd]), free(line), NULL);
		buf[fd][bytes_readed] = '\0';
		line = ft_strjoin(line, buf[fd]);
		if (!line)
			return (NULL);
	}
	ft_clean_buf(buf[fd]);
	if (line[0] == 0)
		return (free(line), NULL);
	return (line);
}

/*
#include <stdio.h>
#include <fcntl.h>
int	main(int ac, char **av)
{
	int		fd;
	int		fdeux;
	char	*line;

	if (ac)
	{
		fd = open(av[1], O_RDONLY);
		fdeux = open(av[2], O_RDONLY);
		int i = 0;
		while (1)
		{
			line = get_next_line(fd);
			printf("%s$", line);
			line = get_next_line(fdeux);
			printf("%s$", line);
			i++;
			if (!line)
				break;
			free(line);
		}
		close(fd);
		close(fdeux);
	}
	return (0);
}
*/