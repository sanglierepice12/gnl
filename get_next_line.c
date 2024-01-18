/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gostr@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:37:39 by gsuter            #+#    #+#             */
/*   Updated: 2024/01/18 08:37:39 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	buf[BUFFER_SIZE + 1];
	ssize_t		bytes_readed;
	char		*line;

	bytes_readed = 1;
	if (read(fd, buf, 0) < 0)
		return (ft_bzero(buf), NULL);
	line = ft_strdup(buf);
	if (!line)
		return (free(line), NULL);
	while (!ft_endline(line) && bytes_readed)
	{
		bytes_readed = read(fd, buf, BUFFER_SIZE);
		if (bytes_readed < 0)
			return (ft_bzero(buf), free(line), NULL);
		buf[bytes_readed] = '\0';
		line = ft_strjoin(line, buf);
		if (!line)
			return (NULL);
	}
	ft_clean_buf(buf);
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
	char	*line;

	if (ac)
		fd = open(av[1], O_RDONLY);
	else
		return 0;
	if (fd < 0)
		return (0);
	int i = 0;
	while(1)
	{
		line = get_next_line(fd);

		printf("%s$", line);
		i++;
		if (!line)
			break ;
		free(line);
	}
	close(fd);
	return (0);
}
*/