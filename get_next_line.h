/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gostr@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:37:51 by gsuter            #+#    #+#             */
/*   Updated: 2024/01/18 08:37:51 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

//GNL
char	*get_next_line(int fd);
/*char	*ft_read_copy(int fd, char *buf, ssize_t bytesread);*/

//GNL UTILS
char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
void	ft_clean_buf(char *buf);
int		ft_endline(char *buf);
ssize_t	ft_strlen(const char *s1);
void	ft_bzero(char *str);

#endif
