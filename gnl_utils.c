/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gostr@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:02:05 by gsuter            #+#    #+#             */
/*   Updated: 2024/01/11 11:02:05 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int	ft_end_line(char *buf)
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

int	ft_strlen(const char *str)
{
	ssize_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_str_join(char const *s1, char const *s2)
{
	size_t			i;
	size_t			j;
	unsigned int	len;
	char			*dest;

	len = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] && s2[j] != '\n')
		dest[i++] = s2[j++];
	if (s2[j] == '\n')
		dest[i] = s2[j];
	dest[++i] = '\0';
	free((char *)s1);
	return (dest);
}

char	*ft_str_dup(const char *s1)
{
	char	*dest;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
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

void	ft_clean_buff(char *buf)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	j = 0;
	if (!buf)
		return ;
	while (buf[i] != '\n' && buf[i] != 0)
	{
		buf[i] = 0;
		i++;
	}
	if (buf[i] == '\n')
	{
		buf[i] = 0;
		i++;
	}
	while (buf[i + j])
	{
		buf[j] = buf[i + j];
		buf[i + j] = 0;
		j++;
	}
}
