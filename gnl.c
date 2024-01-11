/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gostr@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:02:05 by gsuter            #+#    #+#             */
/*   Updated: 2024/01/11 11:02:05 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "gnl.h"

char	*ft_read_copy(int fd, char *buf, char *line, ssize_t bytes_read)
{
	char	*dest;

	dest = ft_str_dup(buf);
	while (!ft_end_line(buf) && bytes_read)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			break ;
		buf[bytes_read] = '\0';
		dest = ft_str_join(dest, buf);
		if (!dest)
			return (free(dest), NULL);
	}
	if (!dest[0])
		return (NULL);
	return (dest);
}

char	*ft_gnl(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes_read;

	bytes_read = 1;
	if (read(fd, buf, 0) < 0)
		return (free(line), NULL);
	line = ft_read_copy(fd, buf, line, bytes_read);
	if (!line)
		return (NULL);
	ft_clean_buff(buf);
	return (line);
}

/*#include <stdio.h>
#include <fcntl.h>
int	main()
{
	int		fd;
	char	*line;

	fd = open("hello.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	int i = 0;
	while(1)
	{
		line = ft_gnl(fd);

		printf("\n%s$", line);
		i++;
		if (!line)
			break ;
		free(line);
	}
	close(fd);
	return (0);
}*/