/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gostr@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:37:51 by gsuter            #+#    #+#             */
/*   Updated: 2024/01/18 08:37:51 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		str[i] = 0;
		i++;
	}
}

int	ft_endline(char *buf)
{
	ssize_t	i;

	i = 0;
	if (ft_strlen(buf + i) == 0)
		return (0);
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

ssize_t	ft_strlen(const char *s1)
{
	ssize_t	i;

	if (!s1)
		return (0);
	i = 0;
	while (s1[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;
	size_t	len;

	len = 0;
	while (s1[len] && s1[len] != '\n')
		len++;
	if (s1[len] == '\n')
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[len] = '\0';
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t			i;
	size_t			j;
	unsigned int	len;
	char			*dest;

	len = 0;
	while (s2[len] && s2[len] != '\n')
		len++;
	if (s2[len] == '\n')
		len++;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + len + 1));
	if (!dest)
		return (free((char *)s1), NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j] && (!j || s2[j - 1] != '\n'))
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free((char *)s1);
	return (dest);
}
