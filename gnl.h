/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gostr@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:02:09 by gsuter            #+#    #+#             */
/*   Updated: 2024/01/11 11:02:09 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

//GNL
char	*ft_gnl(int fd);

//GNL UTILS
char	*ft_read_copy(int fd, char *buf, char *line, ssize_t bytes_read);
int		ft_end_line(char *buf);
char	*ft_str_join(char const *s1, char const *s2);
int		ft_strlen(const char *str);
char	*ft_str_dup(const char *s1);
void	ft_clean_buff(char *buf);
char	*ft_str_dup(const char *s1);

#endif